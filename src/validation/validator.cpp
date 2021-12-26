#include "validation/validator.hpp"

Validator::Validator()
    : typeDeclTable{}, varDeclTable{}, typeStack{}, forSwitchCountStack{}
{
    this->typeDeclTable.addScope();
    this->varDeclTable.addScope();
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
    for (const auto functionValidator : functionDeclarationValidators) {
        functionValidator();
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

    std::vector<Type *> types{};

    while (!typeStack.empty()) {
        types.push_back(typeStack.pop());
    }

    std::reverse(types.begin(), types.end());

    for (const auto type : types) {
        std::cout << type->toString() << std::endl;
    }
}

void Validator::visitFunctionDeclaration(std::string id, const std::function<void ()>& visitSignature, const std::function<void ()>& visitBody)
{
    visitSignature();
    auto signature = typeStack.pop();
    varDeclTable.add(id, signature);
    
    functionDeclarationValidators.push_back([this, visitSignature, visitBody]() {
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
    });
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
        if (varDeclTable.contains(id)) {
            errors.push_back("Duplicate declaration of \'" + id + "\' in this scope.");
        } else {
            varDeclTable.add(id, type);
        }
    }
}

void Validator::visitExpressionStatement()
{
    // FIXME: function calls can return more than one type. THIS WILL BREAK EVERYTING IF YOU USE ONE OF THOSE
    typeStack.pop(); // ommit
}

void Validator::visitAssignmentStatement(const std::function<long ()>& visitLhs, const std::function<long ()>& visitRhs)
{ 
    auto lhsSize = visitLhs();
    auto rhsSize = visitRhs();

    if (lhsSize != rhsSize) {
        errors.push_back("Assignment mismatch, " + std::to_string(lhsSize) + " variables but " + std::to_string(rhsSize) + (rhsSize == 1 ? " value." : " values."));
        return;
    }

    auto rhsTypes = typeStack.pop(rhsSize);
    auto lhsTypes = typeStack.pop(lhsSize);

    for (int i = 0; i < lhsSize; ++i) {
        auto lhs = lhsTypes[i];
        auto rhs = rhsTypes[i];

        if (!lhs->equals(*rhs)) {
            errors.push_back("Got type " + rhs->toString() + " but expected " + lhs->toString() + ".");
        }
    }
}

void Validator::visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse)
{
    auto conditionType = typeStack.pop();

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
    std::reverse(types.begin(), types.end());


    if (returns.size() != size) {
        errors.push_back("Got " + std::to_string(size) + " expressions but current function has to return " + std::to_string(returns.size()) + " values.");
    }

    for (int i = 0; i < size; ++i) {
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
}

void Validator::visitIntExpression(int value)
{
    typeStack.push(new IntType{});
}

void Validator::visitFloat32Expression(float value)
{
    typeStack.push(new Float32Type{});
}

void Validator::visitRuneExpression(char value)
{
    typeStack.push(new RuneType{});
}

void Validator::visitStringExpression(char *value, long length)
{
    typeStack.push(new StringType{});
}

void Validator::visitIdentifierExpression(std::string id)
{
    if (!varDeclTable.contains(id)) {
        errors.push_back("Variable \'" + id + "\' does not exist.");
        typeStack.push(new UnresolvedType{});
        return;
    }
    
    auto type = varDeclTable.get(id);

    typeStack.push(type);
}

void Validator::visitCompositLiteralExpression(std::vector<std::string> keys)
{
    auto expressionTypes = typeStack.pop(keys.size());

    std::reverse(expressionTypes.begin(), expressionTypes.end());

    Type *type = typeStack.pop();
    Type *baseType = type;

    if (!type->composable()) {
        errors.push_back(type->toString() + " is not composable.");
        typeStack.push(new UnresolvedType{});
        return;
    }

    if (instanceof<CustomType>(type)) {
        baseType = dynamic_cast<CustomType *>(type)->underlyingType();
    }

    if (instanceof<ArrayType>(baseType)) {
        if (!std::all_of(keys.begin(), keys.end(), [](std::string key) { return key == ""; })) {
            errors.push_back("Keys on a composite literal are only accepted for structures (because i got lazy).");
            typeStack.push(type);
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
            return;
        }

        std::vector<std::pair<std::string, Type *>> fields;

        for (int i = 0; i < keys.size(); ++i) {
            fields.push_back(std::make_pair(keys[i], expressionTypes[i]));
        }

        auto composedType = new StructType{fields};

        if (baseType != composedType) {
            errors.push_back("Given type doesn't match composed type, either the fields are out of order, or incorrect/not all fields have been declared.");
            typeStack.push(type);
            return;
        }

    }

    typeStack.push(type);
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
}

void Validator::visitSelectExpression(std::string id)
{
    auto type = typeStack.pop();
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
    } else {
        errors.push_back("Selectors can only be used on Structs not on " + type->toString());
        typeStack.push(new UnresolvedType{});
    }
}

void Validator::visitIndexExpression()
{
    auto indexType = typeStack.pop();
    auto expressionType = typeStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Arrays can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<ArrayType *>(expressionType)->elementType());
    } else if (instanceof<SliceType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Slices can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<SliceType *>(expressionType)->elementType());
    } else if (instanceof<StringType>(expressionType)) {
        if (!instanceof<IntType>(indexType)) {
            errors.push_back("Strings can only be indexed using Ints, not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<SliceType *>(expressionType)->elementType());
    } else if (instanceof<MapType>(expressionType)) {
        if (indexType != dynamic_cast<MapType *>(expressionType)->keyType()) {
            errors.push_back(expressionType->toString() + " can only be indexed using " + dynamic_cast<MapType *>(expressionType)->keyType()->toString() + ", not " + indexType->toString() + ".");
        }

        typeStack.push(dynamic_cast<MapType *>(expressionType)->elementType());
    }else {
        errors.push_back("Indexing can not be used on " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
    }
}

void Validator::visitSimpleSliceExpression(bool lowDeclared, bool highDeclared)
{
    if (highDeclared) {
        auto highType = typeStack.pop();
        if(!instanceof<IntType>(highType)) {
            errors.push_back("High index on slice can only be of type int, not " + highType->toString() + ".");
        }
    }

    if (lowDeclared) {
        auto lowType = typeStack.pop();
        if(!instanceof<IntType>(lowType)) {
            errors.push_back("Low index on slice can only be of type int, not " + lowType->toString() + ".");
        }
    }

    auto expressionType = typeStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<ArrayType *>(expressionType)
                    ->elementType()});
    } else if (instanceof<SliceType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<SliceType *>(expressionType)
                    ->elementType()});
    } else if (instanceof<StringType>(expressionType)) {
        typeStack.push(expressionType);
    } else {
        errors.push_back("Can not take slice of " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
    }
}

void Validator::visitFullSliceExpression(bool lowDeclared)
{
    auto maxType = typeStack.pop();
    if(!instanceof<IntType>(maxType)) {
        errors.push_back("Max index on slice can only be of type int, not " + maxType->toString() + ".");
    }

    auto highType = typeStack.pop();
    if(!instanceof<IntType>(highType)) {
        errors.push_back("High index on slice can only be of type int, not " + highType->toString() + ".");
    }

    if (lowDeclared) {
        auto lowType = typeStack.pop();
        if(!instanceof<IntType>(lowType)) {
            errors.push_back("Low index on slice can only be of type int, not " + lowType->toString() + ".");
        }
    }

    auto expressionType = typeStack.pop();

    if (instanceof<ArrayType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<ArrayType *>(expressionType)
                    ->elementType()});
    } else if (instanceof<SliceType>(expressionType)) {
        typeStack.push(
            new SliceType{
                dynamic_cast<SliceType *>(expressionType)
                    ->elementType()});
    } else if (instanceof<StringType>(expressionType)) {
        typeStack.push(expressionType);
    } else {
        errors.push_back("Can not take slice of " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
    }
}

void Validator::visitCallExpression(long size)
{
    auto argTypes = typeStack.pop(size);
    auto expressionType = typeStack.pop();

    if (!instanceof<FunctionType>(expressionType)) {
        errors.push_back("Expected a function, not " + expressionType->toString() + ".");
        typeStack.push(new UnresolvedType{});
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
    }
}

void Validator::visitConversionExpression()
{
    // FIXME: in parser
}

void Validator::visitUnaryPlusExpression()
{
    auto operand = typeStack.pop();

    if (!instanceof<IntType>(operand)
        || !instanceof<Float32Type>(operand)) {
            errors.push_back("Unary plus can only be used on int, and float32, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
}

void Validator::visitUnaryNegateExpression()
{
    auto operand = typeStack.pop();

    if (!instanceof<IntType>(operand)
        || !instanceof<Float32Type>(operand)) {
            errors.push_back("Unary minus can only be used on int, and float32, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
}

void Validator::visitUnaryLogicalNotExpression()
{
    auto operand = typeStack.pop();

    if (!instanceof<BoolType>(operand)) {
            errors.push_back("Logical not can only be used on booleans, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
}

void Validator::visitUnaryBitwiseNotExpression()
{
    auto operand = typeStack.pop();

    if (!instanceof<BoolType>(operand)) {
            errors.push_back("Logical not can only be used on booleans, not on " + operand->toString() + ".");
    }

    typeStack.push(operand);
}

void Validator::visitUnaryDereferenceExpression()
{
    errors.push_back("Address operations are not supported.");

    auto operand = typeStack.pop();

    if (!instanceof<PointerType>(operand)) {
        errors.push_back("Dereference can only be used on pointers, not on " + operand->toString() + ".");
        typeStack.push(new UnresolvedType{});
    } else {
        typeStack.push(dynamic_cast<PointerType*>(operand)->underlyingType());
    }
}

void Validator::visitUnaryReferenceExpression()
{
    errors.push_back("Address operations are not supported.");

    auto operand = typeStack.pop();
    typeStack.push(new PointerType{operand});
}

void Validator::visitBinaryLogicalOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + lhs->toString() + ".");
    }

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
}

void Validator::visitBinaryLogicalAndExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + lhs->toString() + ".");
    }

    if (!instanceof<BoolType>(lhs)) {
            errors.push_back("Logical or can only be used on booleans, not on " + rhs->toString() + ".");
    }

    typeStack.push(new BoolType{});
}

void Validator::visitBinaryEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryNotEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryLessThanExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryLessThanEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryGreaterThanExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryGreaterThanEqualExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}

void Validator::visitBinaryShiftLeftExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
}

void Validator::visitBinaryShiftRightExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Shift expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
}

void Validator::visitBinaryAddExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs) && !instanceof<StringType>(lhs)) {
        errors.push_back("Add expression can only be used on an integer, float32 or string, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs) && !instanceof<StringType>(rhs)) {
        errors.push_back("Add expression can only be used on an integer, float32 or string, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
}

void Validator::visitBinarySubtractExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs)) {
        errors.push_back("Subtract expression can only be used on an integer or float32, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs)) {
        errors.push_back("Subtract expression can only be used on an integer or float32, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot subtract " + rhs->toString() + " from " + lhs->toString() + ".");
    }

    typeStack.push(lhs);
}

void Validator::visitBinaryBitwiseOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise or expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise or expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
}

void Validator::visitBinaryBitwiseXOrExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise xor expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise xor expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
}

void Validator::visitBinaryBitwiseAndExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs)) {
        errors.push_back("Bitwise and expression can only be used on an integer, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs)) {
        errors.push_back("Bitwise and expression can only be used on an integer, not on " + rhs->toString() + ".");
    }

    typeStack.push(new IntType{});
}

void Validator::visitBinaryMultiplyExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs)) {
        errors.push_back("Multiply expression can only be used on an integer or float32, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs)) {
        errors.push_back("Mulitply expression can only be used on an integer or float32, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
}

void Validator::visitBinaryDivideExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

    if (!instanceof<IntType>(lhs) && !instanceof<Float32Type>(lhs)) {
        errors.push_back("Divide expression can only be used on an integer or float32, not on " + lhs->toString() + ".");
    }

    if (!instanceof<IntType>(rhs) && !instanceof<Float32Type>(rhs)) {
        errors.push_back("Divide expression can only be used on an integer or float32, not on " + rhs->toString() + ".");
    }

    if (!lhs->equals(*rhs)) {
        errors.push_back("Cannot add " + lhs->toString() + " to " + rhs->toString() + ".");
    }

    typeStack.push(lhs);
}

void Validator::visitBinaryModuloExpression()
{
    auto rhs = typeStack.pop();
    auto lhs = typeStack.pop();

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
}
