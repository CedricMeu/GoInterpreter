#include "validation/validator.hpp"

Validator::Validator()
    : 
    errors{},
    functionDeclarationValidators{},
    typeDeclTable{}, 
    varDeclTable{}, 
    typeStack{}, 
    referencableStack{}, 
    switchExpressionTypeStack{},
    currentFunction{},
    forSwitchCountStack{},
    returnsStack{},
    switchDefaultCaseDeclared{}
{
    this->typeDeclTable.addScope();
    this->varDeclTable.addScope();

    std::string printInt = "printInt";
    std::string printRune = "printRune";
    std::string printFloat32 = "printFloat32";
    std::string printString = "printString";
    this->varDeclTable.add(printInt, new FunctionType{{std::make_pair("value", new IntType{})}, {}});
    this->varDeclTable.add(printRune, new FunctionType{{std::make_pair("value", new RuneType{})}, {}});
    this->varDeclTable.add(printFloat32, new FunctionType{{std::make_pair("value", new Float32Type{})}, {}});
    this->varDeclTable.add(printString, new FunctionType{{std::make_pair("value", new StringType{})}, {}});
}

Validator::~Validator()
{
    for (const auto typedecl : typeDeclTable.allValues())
    {
        delete typedecl;
    }

    for (const auto vardecl : varDeclTable.allValues())
    {
        delete vardecl;
    }
}

std::vector<std::string> Validator::getErrors() const
{
    return errors;
}

void Validator::visitProgram(long size)
{
    if (!functionDeclarationValidators.contains("main")) {
        errors.push_back("Program does not contain a main function");
    } else {
        std::string id = "main";
        auto main = dynamic_cast<FunctionType*>(varDeclTable.get(id));

        if (!main->getParameters().empty()) {
            errors.push_back("Main function should not accept any parameters");
        }
        
        if (!main->getReturns().empty()) {
            errors.push_back("Main function should not return any values");
        }
    }

    for (const auto functionValidator : functionDeclarationValidators) {
        functionValidator.second();
    }
}

void Validator::visitBoolType()
{
    typeStack.push(new BoolType{});
}

void Validator::visitIntType()
{
    typeStack.push(new IntType{});
}

void Validator::visitFloat32Type()
{
    typeStack.push(new Float32Type{});
}

void Validator::visitRuneType()
{
    typeStack.push(new RuneType{});
}

void Validator::visitStringType()
{
    typeStack.push(new StringType{});
}

void Validator::visitArrayType(long size)
{
    auto elementType = typeStack.pop();
    typeStack.push(new ArrayType{elementType, size});
}

void Validator::visitSliceType()
{
    auto elementType = typeStack.pop();
    typeStack.push(new SliceType{elementType});
}

void Validator::visitStructType(std::vector<std::string> fields)
{
    auto types = typeStack.pop(fields.size());

    std::reverse(types.begin(), types.end());

    std::vector<std::pair<std::string, Type *>> _fields;

    std::transform(fields.begin(), fields.end(), types.begin(),
               std::back_inserter(_fields),
               [](const auto& name, const auto& type)
               {
                   return std::make_pair(name, type);
               });

    typeStack.push(new StructType{_fields});
}

void Validator::visitPointerType()
{
    auto type = typeStack.pop();
    typeStack.push(new PointerType{type});
}

void Validator::visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns)
{
    auto returnTypes = typeStack.pop(returns.size());
    auto parameterTypes = typeStack.pop(parameters.size());

    std::reverse(parameterTypes.begin(), parameterTypes.end());
    std::reverse(returnTypes.begin(), returnTypes.end());

    std::vector<std::pair<std::string, Type *>> _parameters;
    std::vector<std::pair<std::string, Type *>> _returns;

    std::transform(parameters.begin(), parameters.end(), parameterTypes.begin(),
               std::back_inserter(_parameters),
               [](const auto& name, const auto& type)
               {
                   return std::make_pair(name, type);
               });

    std::transform(returns.begin(), returns.end(), returnTypes.begin(),
               std::back_inserter(_returns),
               [](const auto& name, const auto& type)
               {
                   return std::make_pair(name, type);
               });

    if (_returns.size() > 1) {
        errors.push_back("Multiple return values is not supported.");
    }

    typeStack.push(new FunctionType{_parameters, _returns});
}

void Validator::visitMapType()
{
    auto elementType = typeStack.pop();
    auto keyType = typeStack.pop();
    typeStack.push(new MapType{keyType, elementType});
}

void Validator::visitCustomType(std::string id)
{
    if (!typeDeclTable.contains(id)) {
        errors.push_back("Type \'" + id + "\' does not exist.");
        typeDeclTable.add(id, new UnresolvedType{});
    }

    typeStack.push(typeDeclTable.get(id));
}

void Validator::visitBlock(const std::vector<const std::function<void ()>> visitStatements)
{
    typeDeclTable.addScope();
    varDeclTable.addScope();

    for (const auto visitStatement : visitStatements) {
        visitStatement();
    }

    typeDeclTable.removeScope();
    varDeclTable.removeScope();
}

void Validator::visitFunctionDeclaration(std::string id, const std::function<void ()>& visitSignature, const std::function<void ()>& visitBody)
{
    visitSignature();
    auto signature = typeStack.pop();
    varDeclTable.add(id, signature);
    
    functionDeclarationValidators.insert(std::make_pair(id, [this, visitSignature, visitBody]() {
        visitSignature();
        auto signature = dynamic_cast<FunctionType *>(typeStack.pop());
        currentFunction.push(signature);
    
        for (const auto param : signature->getParameters()) {
            auto id = param.first;
            varDeclTable.add(id, param.second);
        }
        
        for (const auto ret : signature->getReturns()) {
            auto id = ret.first;
            varDeclTable.add(id, ret.second);
        }

        this->returnsStack.push(false);

        this->forSwitchCountStack.push(0);
        visitBody();
        this->forSwitchCountStack.pop();

        auto returns = this->returnsStack.pop();
        if (!returns && signature->getReturns().size() > 0) {
            this->errors.push_back("Not all paths through function return.");
        }

        currentFunction.pop();
    }));
}

void Validator::visitTypeAliasDeclaration(std::string id)
{
    auto type = typeStack.pop();
    typeDeclTable.add(id, type);
}

void Validator::visitTypeDefinitionDeclaration(std::string id)
{
    auto type = new CustomType{typeStack.pop()};
    typeDeclTable.add(id, type);
}

void Validator::visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count)
{
    Type *type = new UnresolvedType{};
    std::vector<Type *> types = typeStack.pop(expression_count);
    std::vector<bool> referencable = referencableStack.pop(expression_count);
    std::reverse(types.begin(), types.end());

    if (typeDeclared) {
        delete type;
        type = typeStack.pop();
    
        if (ids.size() != expression_count && expression_count != 0) {
            errors.push_back("Assignment mismatch, " + std::to_string(ids.size()) + " variables but " + std::to_string(expression_count) + (expression_count == 1 ? " value." : " values."));
            return;
        }
    } else {
        if (ids.size() != expression_count) {
            errors.push_back("Assignment mismatch, " + std::to_string(ids.size()) + " variables but " + std::to_string(expression_count) + (expression_count == 1 ? " value." : " values."));
            return;
        } else {
            delete type;
            type = types[0];
        }
    }

    for (const auto elemType : types) {
        if (!elemType->equals(*type)) {
            errors.push_back("Got type " + elemType->toString() + " but expected " + type->toString() + ".");
        }
    }

    for (auto id : ids) {
        if (varDeclTable.scopeContains(id)) {
            errors.push_back("Duplicate declaration of \'" + id + "\' in this scope.");
        } else {
            varDeclTable.add(id, type);
        }
    }
}

void Validator::visitExpressionStatement()
{
    // FIXME: 
}

void Validator::visitAssignmentStatement(const std::function<long ()>& visitLhs, const std::function<long ()>& visitRhs)
{ 
    auto lhsSize = visitLhs();
    auto rhsSize = visitRhs();

    auto rhsTypes = typeStack.pop(rhsSize);
    auto lhsTypes = typeStack.pop(lhsSize);

    auto rhsReferencable = referencableStack.pop(rhsSize);
    auto lhsReferencable = referencableStack.pop(lhsSize);

    if (lhsSize != rhsSize) {
        errors.push_back("Assignment mismatch, " + std::to_string(lhsSize) + " variables but " + std::to_string(rhsSize) + (rhsSize == 1 ? " value." : " values."));
        return;
    }

    for (int i = 0; i < lhsSize; ++i) {
        auto lhs = lhsTypes[i];
        auto rhs = rhsTypes[i];

        auto referencable = lhsReferencable[i];

        if (!referencable) {
            errors.push_back("Left hand side of assignment must be assignable");
        }

        if (!lhs->equals(*rhs)) {
            errors.push_back("Got type " + rhs->toString() + " but expected " + lhs->toString() + ".");
        }
    }
}

void Validator::visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse)
{
    auto conditionType = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<BoolType>(conditionType)) {
        errors.push_back("Condition of if-statement must be Bool, not " + conditionType->toString() + ".");
    }

    returnsStack.push(false);
    visitTrue();
    auto trueReturns = returnsStack.pop();

    returnsStack.push(false);
    visitFalse();
    auto falseReturns = returnsStack.pop();

    auto currentReturns = returnsStack.pop();
    returnsStack.push(currentReturns || (trueReturns && falseReturns));
}

void Validator::visitSwitchStatement(const std::function<void ()>& visitExpression, const std::vector<const std::function<void ()>> visitClauses)
{
    visitExpression();

    auto expressionType = typeStack.pop();
    referencableStack.pop();
    switchExpressionTypeStack.push(expressionType);
    auto returns = true;

    switchDefaultCaseDeclared.push(false);
    for (const auto visitClause : visitClauses) {
        returnsStack.push(false);
        visitClause();
        auto clauseReturns = returnsStack.pop();
        returns &= clauseReturns;
    }
    auto defaultCaseDeclared = switchDefaultCaseDeclared.pop();

    auto currentReturns = returnsStack.pop();
    returnsStack.push(currentReturns || (returns && defaultCaseDeclared));

    switchExpressionTypeStack.pop();
}

void Validator::visitSwitchExpressionClause(const std::vector<const std::function<void ()>> visitExpressions, const std::vector<const std::function<void ()>> visitStatements)
{
    for (const auto visitExpression : visitExpressions) {
        visitExpression();

        auto type = typeStack.pop();
        referencableStack.pop();
        auto expected = switchExpressionTypeStack.top();

        if (!type->equals(*expected)) {
            errors.push_back("Expected expression of type " + expected->toString() + ", not of type " + type->toString() + ".");
        }
    }

    for (const auto visitStatement : visitStatements) {
        visitStatement();
    }
}

void Validator::visitSwitchDefaultClause(const std::vector<const std::function<void ()>> visitStatements)
{
    for (const auto visitStatement : visitStatements) {
        visitStatement();
    }

    switchDefaultCaseDeclared.pop();
    switchDefaultCaseDeclared.push(true);
}

void Validator::visitReturnStatement(long size)
{
    auto signature = currentFunction.top();
    auto returns = signature->getReturns();
    auto types = typeStack.pop(size);
    referencableStack.pop(size);
    std::reverse(types.begin(), types.end());


    if (returns.size() != size) {
        errors.push_back("Got " + std::to_string(size) + " expressions but current function has to return " + std::to_string(returns.size()) + " values.");
    }

    for (int i = 0; i < returns.size(); ++i) {
        if (!returns[i].second->equals(*types[i])) {
            errors.push_back("The " + std::to_string(i + 1) + (i == 0 ? "st" : (i == 1 ? "nd" : "th")) + " element has type " + types[i]->toString() + ", but expected " + returns[i].second->toString() + " in the return statementd.");
        }
    }

    returnsStack.pop();
    returnsStack.push(true); // return always returns, doesn't it?
}

void Validator::visitBreakStatement()
{
    auto current = forSwitchCountStack.pop();
    forSwitchCountStack.push(current);

    if (current == 0) {
        errors.push_back("Break can only be used inside loops and switch statements");
    }
}

void Validator::visitContinueStatement()
{
    auto current = forSwitchCountStack.pop();
    forSwitchCountStack.push(current);

    if (current == 0) {
        errors.push_back("Continue can only be used inside loops and switch statements");
    }
}

void Validator::visitEmptyStatement()
{}

void Validator::visitForConditionStatement(const std::function<void ()>& visitInit, const std::function<void ()>& visitCondition, const std::function<void ()>& visitPost, const std::function<void ()>& visitBody)
{
    visitInit();
    visitCondition();

    auto conditionType = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<BoolType>(conditionType)) {
        errors.push_back("Condition of a for-loop must be of boolean type, not " + conditionType->toString() + ".");
    }
    visitPost();
    auto current = forSwitchCountStack.pop();
    forSwitchCountStack.push(current + 1);
    returnsStack.push(false);
    visitBody();
    returnsStack.pop(); 
    // wont update return stack because we can't assume more than 0 runs
    forSwitchCountStack.pop();
    forSwitchCountStack.push(current);
}

void Validator::visitBoolExpression(bool value)
{
    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitIntExpression(int value)
{
    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitFloat32Expression(float value)
{
    typeStack.push(new Float32Type{});
    referencableStack.push(false);
}

void Validator::visitRuneExpression(char value)
{
    typeStack.push(new RuneType{});
    referencableStack.push(false);
}

void Validator::visitStringExpression(char *value, long length)
{
    typeStack.push(new StringType{});
    referencableStack.push(false);
}

void Validator::visitIdentifierExpression(std::string id)
{
    if (!varDeclTable.contains(id)) {
        errors.push_back("Variable \'" + id + "\' does not exist.");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(true);
        return;
    }
    
    auto type = varDeclTable.get(id);

    typeStack.push(type);
    referencableStack.push(true);
}

void Validator::visitCompositLiteralExpression(std::vector<std::string> keys)
{
    auto expressionTypes = typeStack.pop(keys.size());
    referencableStack.pop(keys.size());

    std::reverse(expressionTypes.begin(), expressionTypes.end());

    Type *type = typeStack.pop();
    Type *baseType = type;

    if (!type->composable()) {
        errors.push_back(type->toString() + " is not composable.");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
        return;
    }

    if (instanceof<CustomType>(type)) {
        baseType = dynamic_cast<CustomType *>(type)->underlyingType();
    }

    if (instanceof<ArrayType>(baseType)) {
        if (!std::all_of(keys.begin(), keys.end(), [](std::string key) { return key == ""; })) {
            errors.push_back("Keys on a composite literal are only accepted for structures (because i got lazy).");
            typeStack.push(type);
            referencableStack.push(false);
            return;
        }

        auto arrayType = dynamic_cast<ArrayType *>(baseType);

        for (int i = 0; i < expressionTypes.size(); ++i) {
            if (!expressionTypes[i]->equals(*arrayType->elementType())) {
                errors.push_back("The " + std::to_string(i + 1) + (i == 0 ? "st" : (i == 1 ? "nd" : "th")) + " element has type " + expressionTypes[i]->toString() + ", but expected " + arrayType->elementType()->toString() + '.');
            }
        }
    } else if (instanceof<SliceType>(baseType)) {
        if (!std::all_of(keys.begin(), keys.end(), [](std::string key) { return key == ""; })) {
            errors.push_back("Keys on a composite literal are only accepted for structures (because i got lazy).");
            typeStack.push(type);
            referencableStack.push(false);
            return;
        }

        auto sliceType = dynamic_cast<SliceType *>(baseType);

        for (int i = 0; i < expressionTypes.size(); ++i) {
            if (!expressionTypes[i]->equals(*sliceType->elementType())) {
                errors.push_back("The " + std::to_string(i + 1) + (i == 0 ? "st" : (i == 1 ? "nd" : "th")) + " element has type " + expressionTypes[i]->toString() + ", but expected " + sliceType->elementType()->toString() + '.');
            }
        }
    } else if (instanceof<MapType>(baseType)) {
        if (keys.size() != 0) {
            errors.push_back("Composite literals for maps are not supported (because i got lazy).");
        }

        // // Uncomment when implementing maps decently:
        // auto mapType = dynamic_cast<MapType *>(baseType);

        // for (int i = 0; i < expressionTypes.size(); ++i) {
        //     if (expressionTypes[i] != mapType->elementType()) {
        //         errors.push_back("The " + std::to_string(i + 1) + (i == 0 ? "st" : (i == 1 ? "nd" : "th")) + " element has type " + expressionTypes[i]->toString() + ", but expected " + mapType->elementType()->toString() + '.');
        //     }
        // }
    } else if (instanceof<StructType>(baseType)) {
        if (!std::all_of(keys.begin(), keys.end(), [](std::string key) { return key != ""; })) {
            errors.push_back("Keys on a composite literal are required for structures (because i got lazy).");
            typeStack.push(type);
            referencableStack.push(false);
            return;
        }

        std::vector<std::string> dupCheck;

        bool flag = false;

        for (const auto key : keys) {
            if (std::find(dupCheck.begin(), dupCheck.end(), key) != dupCheck.end()) {
                errors.push_back("Duplicate key \'" + key + "\' in composite literal");
                flag = true;
            } else {
                dupCheck.push_back(key);
            }
        }

        if (flag) {
            typeStack.push(type);
            referencableStack.push(false);
            return;
        }

        std::vector<std::pair<std::string, Type *>> fields;

        for (int i = 0; i < keys.size(); ++i) {
            fields.push_back(std::make_pair(keys[i], expressionTypes[i]));
        }

        auto composedType = new StructType{fields};

        if (!baseType->equals(*composedType)) {
            errors.push_back("Given type doesn't match composed type, either the fields are out of order, or incorrect/not all fields have been declared.");
            typeStack.push(type);
            referencableStack.push(false);
            return;
        }

    }

    typeStack.push(type);
    referencableStack.push(false);
}

void Validator::VisitFunctionLiteralExpression(const std::function<void ()>& visitSignature, const std::function<void ()>& visitBody)
{
    visitSignature();
    auto signature = dynamic_cast<FunctionType *>(typeStack.pop());
    currentFunction.push(signature);
    
    for (const auto param : signature->getParameters()) {
        auto id = param.first;
        varDeclTable.add(id, param.second);
    }
    
    for (const auto ret : signature->getReturns()) {
        auto id = ret.first;
        varDeclTable.add(id, ret.second);
    }

    this->returnsStack.push(false);

    this->forSwitchCountStack.push(0);
    visitBody();
    this->forSwitchCountStack.pop();

    auto returns = this->returnsStack.pop();
    if (!returns && signature->getReturns().size() > 0) {
        this->errors.push_back("Not all paths through function return.");
    }

    currentFunction.pop();

    typeStack.push(signature);
    referencableStack.push(false);
}

void Validator::visitSelectExpression(std::string id)
{
    auto type = typeStack.pop();
    auto referencable = referencableStack.pop();
    auto baseType = type;

    if (instanceof<CustomType>(baseType)) {
        baseType = dynamic_cast<CustomType*>(baseType)->underlyingType();
    }

    if (instanceof<StructType>(baseType)) {
        if (!dynamic_cast<StructType *>(baseType)->hasField(id)) {
            errors.push_back("Type " + type->toString() + " has no field \'" + id + "\'.");
            typeStack.push(new UnresolvedType{});
        } else {
            typeStack.push(dynamic_cast<StructType *>(baseType)->typeOfField(id));
        }
        referencableStack.push(referencable);
    } else {
        errors.push_back("Selectors can only be used on Structs not on " + type->toString());
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
    }
}

void Validator::visitIndexExpression()
{
    auto indexType = typeStack.pop();
    auto indexReferencable = referencableStack.pop();
    auto expressionType = typeStack.pop();
    auto expresionReferencable = referencableStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Arrays can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<ArrayType *>(expressionType)->elementType());
        referencableStack.push(expresionReferencable);
    } else if (instanceof<SliceType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Slices can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<SliceType *>(expressionType)->elementType());
        referencableStack.push(expresionReferencable);
    } else if (instanceof<StringType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Strings can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<SliceType *>(expressionType)->elementType());
        referencableStack.push(expresionReferencable);
    } else if (instanceof<MapType>(expressionType)) {
        if (indexType != dynamic_cast<MapType *>(expressionType)->keyType()) {
            errors.push_back(expressionType->toString() + " can only be indexed using " + dynamic_cast<MapType *>(expressionType)->keyType()->toString() + ", not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<MapType *>(expressionType)->elementType());
        referencableStack.push(expresionReferencable);
    } else {
        errors.push_back("Indexing can not be used on " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
    }
}

void Validator::visitSimpleSliceExpression(bool lowDeclared, bool highDeclared)
{
    if (highDeclared) {
        auto highType = typeStack.pop();
        referencableStack.pop();
        if(!instanceof<IntType>(highType)) {
            errors.push_back("High index on slice can only be of type int, not " + highType->toString() + ".");
        }
    }

    if (lowDeclared) {
        auto lowType = typeStack.pop();
        referencableStack.pop();
        if(!instanceof<IntType>(lowType)) {
            errors.push_back("Low index on slice can only be of type int, not " + lowType->toString() + ".");
        }
    }

    auto expressionType = typeStack.pop();
    referencableStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<ArrayType *>(expressionType)
                    ->elementType()});
        referencableStack.push(false);
    } else if (instanceof<SliceType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<SliceType *>(expressionType)
                    ->elementType()});
        referencableStack.push(false);
    } else if (instanceof<StringType>(expressionType)) {
        typeStack.push(expressionType);
        referencableStack.push(false);
    } else {
        errors.push_back("Can not take slice of " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
    }
}

void Validator::visitFullSliceExpression(bool lowDeclared)
{
    auto maxType = typeStack.pop();
    referencableStack.pop();

    if(!instanceof<IntType>(maxType)) {
        errors.push_back("Max index on slice can only be of type int, not " + maxType->toString() + ".");
    }

    auto highType = typeStack.pop();
    referencableStack.pop();
    if(!instanceof<IntType>(highType)) {
        errors.push_back("High index on slice can only be of type int, not " + highType->toString() + ".");
    }

    if (lowDeclared) {
        auto lowType = typeStack.pop();
        referencableStack.pop();
        if(!instanceof<IntType>(lowType)) {
            errors.push_back("Low index on slice can only be of type int, not " + lowType->toString() + ".");
        }
    }

    auto expressionType = typeStack.pop();
    referencableStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<ArrayType *>(expressionType)
                    ->elementType()});
        referencableStack.push(false);
    } else if (instanceof<SliceType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<SliceType *>(expressionType)
                    ->elementType()});
        referencableStack.push(false);
    } else if (instanceof<StringType>(expressionType)) {
        typeStack.push(expressionType);
        referencableStack.push(false);
    } else {
        errors.push_back("Can not take slice of " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
    }
}

void Validator::visitCallExpression(long size)
{
    auto argTypes = typeStack.pop(size);
    referencableStack.pop(size);
    auto expressionType = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<FunctionType>(expressionType)) {
        errors.push_back("Expected a function, not " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(false);
        return;
    }

    auto funcType = dynamic_cast<FunctionType *>(expressionType);

    auto paramTypes = funcType->getParameterTypes();

    if (paramTypes.size() != argTypes.size()) {
        errors.push_back("Expected " + std::to_string(paramTypes.size()) + " arguments, but got " + std::to_string(argTypes.size()) + " arguments.");
    }

    for (int i = 0; i < paramTypes.size(); ++i) {
        if (!paramTypes[i]->equals(*argTypes[i])) {
            errors.push_back("Expected the " + std::to_string(i+1) + (
                i == 0 ? "st" :
                i == 1 ? "nd" :
                         "rd"
            ) + " argument to be of type " + paramTypes[i]->toString() + " but got " + argTypes[i]->toString());
        }
    }

    for (const auto ret : funcType->getReturnTypes()) {
        typeStack.push(ret);
        referencableStack.push(false);
    }
}

void Validator::visitConversionExpression()
{
    // FIXME: in parser
}

void Validator::visitUnaryPlusExpression()
{
    auto operand = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(operand)
        || !instanceof<Float32Type>(operand)) {
            errors.push_back("Unary plus can only be used on int, and float32, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
    referencableStack.push(false);
}

void Validator::visitUnaryNegateExpression()
{
    auto operand = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(operand)
        || !instanceof<Float32Type>(operand)) {
            errors.push_back("Unary minus can only be used on int, and float32, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
    referencableStack.push(false);
}

void Validator::visitUnaryLogicalNotExpression()
{
    auto operand = typeStack.pop();
    referencableStack.pop();

    if (!instanceof<BoolType>(operand)) {
            errors.push_back("Logical not can only be used on booleans, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
    referencableStack.push(false);
}

void Validator::visitUnaryBitwiseNotExpression()
{
    auto operand = typeStack.pop();

    if (!instanceof<IntType>(operand)) {
            errors.push_back("Logical not can only be used on integers, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
    referencableStack.push(false);
}

void Validator::visitUnaryDereferenceExpression()
{
    errors.push_back("Address operations are not supported.");

    auto operand = typeStack.pop();
    auto referencable = referencableStack.pop();

    if (!instanceof<PointerType>(operand)) {
        errors.push_back("Dereference can only be used on pointers, not on " + operand->toString() + ".");
        typeStack.push(new UnresolvedType{});
        referencableStack.push(referencable);
    } else {
        typeStack.push(dynamic_cast<PointerType*>(operand)->underlyingType());
        referencableStack.push(referencable);
    }
}

void Validator::visitUnaryReferenceExpression()
{
    errors.push_back("Address operations are not supported.");

    auto operand = typeStack.pop();
    auto referencable = referencableStack.pop();

    if (!referencable) {
        errors.push_back("Operand of reference operator has to be referencable.");
    } 

    typeStack.push(new PointerType{operand});
    referencableStack.push(false);
}

void Validator::visitBinaryLogicalOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + lhs->toString() + ".");
    }

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryLogicalAndExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + lhs->toString() + ".");
    }

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) || instanceof<MapType>(lhs) || instanceof<FunctionType>(lhs)) {
        errors.push_back(lhs->toString() + " is not comparable.");
    }

    if (instanceof<UnresolvedType>(rhs) || instanceof<MapType>(rhs) || instanceof<FunctionType>(rhs)) {
        errors.push_back(rhs->toString() + " is not comparable.");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryNotEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) || instanceof<MapType>(lhs) || instanceof<FunctionType>(lhs)) {
        errors.push_back(lhs->toString() + " is not comparable.");
    }

    if (instanceof<UnresolvedType>(rhs) || instanceof<MapType>(rhs) || instanceof<FunctionType>(rhs)) {
        errors.push_back(rhs->toString() + " is not comparable.");
    }
    // TODO: check if values in array are ordered/comparable

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryLessThanExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) 
    || instanceof<MapType>(lhs) 
    || instanceof<FunctionType>(lhs) 
    || instanceof<BoolType>(lhs)
    || instanceof<PointerType>(lhs)
    || instanceof<StructType>(lhs)) {
        errors.push_back(lhs->toString() + " is not ordered.");
    }

    if (instanceof<UnresolvedType>(rhs) 
    || instanceof<MapType>(rhs) 
    || instanceof<FunctionType>(rhs) 
    || instanceof<BoolType>(rhs)
    || instanceof<PointerType>(rhs)
    || instanceof<StructType>(rhs)) {
        errors.push_back(rhs->toString() + " is not ordered.");
    }
    // TODO: check if values in array are ordered/comparable

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryLessThanEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) 
    || instanceof<MapType>(lhs) 
    || instanceof<FunctionType>(lhs) 
    || instanceof<BoolType>(lhs)
    || instanceof<PointerType>(lhs)
    || instanceof<StructType>(lhs)) {
        errors.push_back(lhs->toString() + " is not ordered.");
    }

    if (instanceof<UnresolvedType>(rhs) 
    || instanceof<MapType>(rhs) 
    || instanceof<FunctionType>(rhs) 
    || instanceof<BoolType>(rhs)
    || instanceof<PointerType>(rhs)
    || instanceof<StructType>(rhs)) {
        errors.push_back(rhs->toString() + " is not ordered.");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryGreaterThanExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) 
    || instanceof<MapType>(lhs) 
    || instanceof<FunctionType>(lhs) 
    || instanceof<BoolType>(lhs)
    || instanceof<PointerType>(lhs)
    || instanceof<StructType>(lhs)) {
        errors.push_back(lhs->toString() + " is not ordered.");
    }

    if (instanceof<UnresolvedType>(rhs) 
    || instanceof<MapType>(rhs) 
    || instanceof<FunctionType>(rhs) 
    || instanceof<BoolType>(rhs)
    || instanceof<PointerType>(rhs)
    || instanceof<StructType>(rhs)) {
        errors.push_back(rhs->toString() + " is not ordered.");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryGreaterThanEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (instanceof<UnresolvedType>(lhs) 
    || instanceof<MapType>(lhs) 
    || instanceof<FunctionType>(lhs) 
    || instanceof<BoolType>(lhs)
    || instanceof<PointerType>(lhs)
    || instanceof<StructType>(lhs)) {
        errors.push_back(lhs->toString() + " is not ordered.");
    }

    if (instanceof<UnresolvedType>(rhs) 
    || instanceof<MapType>(rhs) 
    || instanceof<FunctionType>(rhs) 
    || instanceof<BoolType>(rhs)
    || instanceof<PointerType>(rhs)
    || instanceof<StructType>(rhs)) {
        errors.push_back(rhs->toString() + " is not ordered.");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot compare " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
    referencableStack.push(false);
}

void Validator::visitBinaryShiftLeftExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitBinaryShiftRightExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitBinaryAddExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs) && !instanceof<RuneType>(lhs) && !instanceof<StringType>(lhs)) {
        errors.push_back("Add expression can only be used on an integer, float32, rune or string, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs) && !instanceof<RuneType>(rhs) && !instanceof<StringType>(rhs)) {
        errors.push_back("Add expression can only be used on an integer, float32, rune or string, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
    referencableStack.push(false);
}

void Validator::visitBinarySubtractExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs) && !instanceof<RuneType>(lhs)) {
        errors.push_back("Subtract expression can only be used on an integer, float32 or rune, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs) && !instanceof<RuneType>(rhs)) {
        errors.push_back("Subtract expression can only be used on an integer, float32 or rune, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot subtract " + rhs->toString() + " from " + lhs->toString() + ".");
    }

    typeStack.push(lhs);
    referencableStack.push(false);
}

void Validator::visitBinaryBitwiseOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise or expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise or expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitBinaryBitwiseXOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise xor expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise xor expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitBinaryBitwiseAndExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise and expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise and expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
    referencableStack.push(false);
}

void Validator::visitBinaryMultiplyExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs) && !instanceof<RuneType>(lhs)) {
        errors.push_back("Multiply expression can only be used on an integer, float32 or rune, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs) && !instanceof<RuneType>(rhs)) {
        errors.push_back("Mulitply expression can only be used on an integer, float32 or rune, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
    referencableStack.push(false);
}

void Validator::visitBinaryDivideExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs) && !instanceof<RuneType>(lhs)) {
        errors.push_back("Divide expression can only be used on an integer, float32 or rune, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs) && !instanceof<RuneType>(rhs)) {
        errors.push_back("Divide expression can only be used on an integer, float32 or rune, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
    referencableStack.push(false);
}

void Validator::visitBinaryModuloExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();
    referencableStack.pop();
    referencableStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Modulo expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Modulo expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
    referencableStack.push(false);
}
