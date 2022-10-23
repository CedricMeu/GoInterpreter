#include "interpreter/interpreter.hpp"

Interpreter::Interpreter()
    : stack{}, switchStack{}, symbolTable{}, returnsByCurrentFunction{}, functionClosed{}, compositeLiteralType{}, brk{false}, cont{false}, ret{false}
{
    symbolTable.addScope();

    std::string printInt = "printInt";
    std::string printRune = "printRune";
    std::string printFloat32 = "printFloat32";
    std::string printString = "printString";
    symbolTable.add(printInt, new FunctionValue{{}, [](auto closure, auto arguments) -> Value * {
        auto value = dynamic_cast<IntValue *>(arguments[0]->getValue());
        std::cout << value->getInt();
        return nullptr;
    }});
    symbolTable.add(printRune, new FunctionValue{{}, [](auto closure, auto arguments) -> Value * {
        auto value = dynamic_cast<RuneValue *>(arguments[0]->getValue());
        std::cout << value->getChar();
        return nullptr;
    }});
    symbolTable.add(printFloat32, new FunctionValue{{}, [](auto closure, auto arguments) -> Value * {
        auto value = dynamic_cast<Float32Value *>(arguments[0]->getValue());
        std::cout << value->getFloat();
        return nullptr;
    }});
    symbolTable.add(printString, new FunctionValue{{}, [](auto closure, auto arguments) -> Value * {
        auto value = dynamic_cast<StringValue *>(arguments[0]->getValue());
        auto string = value->getString();
        auto converted = std::string{};
        for (int i = 0; i < string.size; ++i) {
            if (string.value[i] != '\0') {
                converted += string.value[i];
            }
        }
        std::cout << converted;
        return nullptr;
    }});
}

Interpreter::~Interpreter()
{
    symbolTable.removeScope();
    std::cout << std::endl;
}

void Interpreter::visitProgram(long size)
{
    std::string main_name = "main";
    auto main = dynamic_cast<FunctionValue *>(symbolTable.get(main_name)->getValue());


    symbolTable.addScope();
    functionClosed.push(false);
    main->call({});
    symbolTable.removeScope();
}

void Interpreter::visitBoolType()
{}

void Interpreter::visitIntType()
{}

void Interpreter::visitFloat32Type()
{}

void Interpreter::visitRuneType()
{}

void Interpreter::visitStringType()
{}

void Interpreter::visitArrayType(long size)
{
    compositeLiteralType.push(CompositeLiteralType::Array);
}

void Interpreter::visitSliceType()
{
    compositeLiteralType.push(CompositeLiteralType::Slice);
}

void Interpreter::visitStructType(std::vector<std::string> fields)
{
    compositeLiteralType.push(CompositeLiteralType::Struct);
}

void Interpreter::visitPointerType()
{}

void Interpreter::visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns)
{
    auto arguments = stack.pop(parameters.size());
    std::reverse(arguments.begin(), arguments.end());

    for (int i = 0; i < parameters.size(); ++i) {
        symbolTable.add(parameters[i], arguments[i]->getValue());
    }

    returnsByCurrentFunction.push(returns.size());
}

void Interpreter::visitMapType()
{}

void Interpreter::visitCustomType(std::string id)
{}

void Interpreter::visitBlock(const std::vector<const std::function<void ()>> visitStatements)
{
    for (const auto visitStatement : visitStatements) {
        visitStatement();
        if (brk || cont || ret) break;
    }
}

void Interpreter::visitFunctionDeclaration(std::string id, const std::function<void ()>& visitSignature, const std::function<void ()>& visitBody)
{  
    symbolTable.add(id, new FunctionValue{{}, [this, visitSignature, visitBody](auto closure, auto arguments) -> Value * {
        // Remove current scope
        auto closed = functionClosed.pop();
        std::vector<std::map<std::string, Value *>> scopes;

        scopes.push_back(symbolTable.getScope());
        symbolTable.removeScope();

        if (closed) {
            scopes.push_back(symbolTable.getScope());
            symbolTable.removeScope();
        }

        // Run function
        symbolTable.addScope();

        functionClosed.push(false);
        for (const auto argument : arguments) {
            stack.push(argument);
        }
        visitSignature();
        visitBody();
        symbolTable.removeScope();

        // restore scope(s)
        std::reverse(scopes.begin(), scopes.end());
        for (auto scope : scopes) {
            symbolTable.addScope(scope);
        }

        functionClosed.push(closed);
        
        // return the result of the function
        auto returns = returnsByCurrentFunction.pop();
        if (returns == 0) {
            return nullptr;
        } else if (returns == 1) {
            return stack.pop();
        } else {
            throw std::exception{};
        }
    }});
}

void Interpreter::visitTypeAliasDeclaration(std::string id)
{}

void Interpreter::visitTypeDefinitionDeclaration(std::string id)
{}

void Interpreter::visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count)
{
    auto values = stack.pop(expression_count);
    std::reverse(values.begin(), values.end());
    for (int i = 0; i < expression_count; ++i) {
        symbolTable.add(ids[i], values[i]->getValue());
    }
}

void Interpreter::visitExpressionStatement()
{}

void Interpreter::visitAssignmentStatement(const std::function<long ()>& visitLhs, const std::function<long ()>& visitRhs)
{
    auto lhsSize = visitLhs();
    auto lhs = stack.pop(lhsSize);
    std::reverse(lhs.begin(), lhs.end());

    auto rhsSize = visitRhs();
    auto rhs = stack.pop(rhsSize);
    std::reverse(rhs.begin(), rhs.end());

    std::vector<Value *> evaluatedRhs;
    std::transform(
        rhs.begin(), 
        rhs.end(), 
        std::inserter(evaluatedRhs, evaluatedRhs.end()), 
        [](Value* value) { return value->getValue(); }
    );
    for (int i = 0; i < lhsSize; ++i) {
        dynamic_cast<ReferenceValue *>(lhs[i])->setValue(evaluatedRhs[i]);
    }
}

void Interpreter::visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse)
{
    auto condition = stack.pop();
    auto value = condition->getValue();

    if (dynamic_cast<BoolValue *>(value)->getBool()) {
        visitTrue();
    } else {
        visitFalse();
    }
}

void Interpreter::visitSwitchStatement(const std::function<void ()>& visitExpression, const std::vector<const std::function<void ()>> visitClauses)
{
    visitExpression();
    switchStack.push(stack.pop());
    for (auto visitClause : visitClauses) {
        visitClause();
        if (brk || ret) {
            brk = false;
            break;
        }
    }
    switchStack.pop();
}

void Interpreter::visitSwitchExpressionClause(const std::vector<const std::function<void ()>> visitExpressions, const std::vector<const std::function<void ()>> visitStatements)
{
    for (auto visitExpression : visitExpressions) {
        visitExpression();
        auto value = dynamic_cast<Equal *>(stack.pop()->getValue());

        if (value->equal(switchStack.top()->getValue())) {
            for (auto visitStatement : visitStatements) {
                visitStatement();
                if (cont || brk || ret) {
                    break;
                }
            }

            break;
        }
    }
}

void Interpreter::visitSwitchDefaultClause(const std::vector<const std::function<void ()>> visitStatements)
{
    for (auto visitStatement : visitStatements) {
        visitStatement();
        if (cont || brk || ret) {
            break;
        }
    }
}

void Interpreter::visitReturnStatement(long size)
{
    ret = true;
    stack.push(stack.pop()->getValue());
}

void Interpreter::visitBreakStatement()
{
    brk = true;
}

void Interpreter::visitContinueStatement()
{
    cont = true;
}

void Interpreter::visitEmptyStatement()
{}

void Interpreter::visitForConditionStatement(const std::function<void ()>& visitInit, const std::function<void ()>& visitCondition, const std::function<void ()>& visitPost, const std::function<void ()>& visitBody)
{
    visitInit();

    visitCondition();
    bool conditionMet = dynamic_cast<BoolValue*>(stack.pop()->getValue())->getBool();

    while (conditionMet) {
        visitBody();
        cont = false;

        if (brk || ret) {
            brk = false;
            break;
        }

        visitPost();

        visitCondition();
        conditionMet = dynamic_cast<BoolValue*>(stack.pop()->getValue())->getBool();
    }
}

void Interpreter::visitBoolExpression(bool value)
{
    stack.push(new BoolValue{value});
}

void Interpreter::visitIntExpression(int value)
{
    stack.push(new IntValue{value});
}

void Interpreter::visitFloat32Expression(float value)
{
    stack.push(new Float32Value{value});
}

void Interpreter::visitRuneExpression(char value)
{
    stack.push(new RuneValue{value});
}

void Interpreter::visitStringExpression(char *value, long length)
{
    stack.push(new StringValue{value, length});
}

void Interpreter::visitIdentifierExpression(std::string id)
{
    stack.push(new ReferenceValue{
       [this, id]() -> Value * {
           auto _id = id;
           return this->symbolTable.get(_id);
       },
       [this, id](Value *newValue) -> void {
           auto _id = id;
           this->symbolTable.add(_id, newValue);
       } 
    });
}

void Interpreter::visitCompositLiteralExpression(std::vector<std::string> keys)
{
    auto type = compositeLiteralType.pop();
    auto values = stack.pop(keys.size());
    std::reverse(values.begin(), values.end());

    std::map<std::string, Value *> _values;

    for (int i = 0; i < values.size(); ++i) {
        values[i] = values[i]->getValue(); // Filter references
    }

    switch (type)
    {
    case CompositeLiteralType::Struct:

        for (int i = 0; i < keys.size(); ++i) {
            _values[keys[i]] = values[i];
        }

        stack.push(new StructValue{_values});
        break;
    case CompositeLiteralType::Slice:
        stack.push(new SliceValue{values});
        break;
    case CompositeLiteralType::Array:
        stack.push(new ArrayValue{values});
        break;
    }
}

void Interpreter::VisitFunctionLiteralExpression(const std::function<void ()>& visitSignature, const std::function<void ()>& visitBody)
{
    auto closure = symbolTable.getScope(); 
    stack.push( new FunctionValue{closure, [this, visitSignature, visitBody](auto closure, auto arguments) -> Value * {
        // Remove current scope
        auto closed = functionClosed.pop();
        std::vector<std::map<std::string, Value *>> scopes;

        scopes.push_back(symbolTable.getScope());
        symbolTable.removeScope();

        if (closed) {
            scopes.push_back(symbolTable.getScope());
            symbolTable.removeScope();
        }

        // Run function
        symbolTable.addScope();// closure scope
        
        for (auto var : closure) {
            symbolTable.add(var.first, var.second);
        }

        symbolTable.addScope();

        functionClosed.push(true);
        for (const auto argument : arguments) {
            stack.push(argument);
        }
        visitSignature();
        visitBody();
        symbolTable.removeScope();
        symbolTable.removeScope();

        // restore scope(s)
        std::reverse(scopes.begin(), scopes.end());
        for (auto scope : scopes) {
            symbolTable.addScope(scope);
        }

        functionClosed.push(closed);

        // return the result of the function
        auto returns = returnsByCurrentFunction.pop();
        if (returns == 0) {
            return nullptr;
        } else if (returns == 1) {
            return stack.pop()->getValue();
        } else {
            throw std::exception{};
        }
    }});
}

void Interpreter::visitSelectExpression(std::string id)
{
    auto value = dynamic_cast<Select *>(stack.pop());
    stack.push(value->select(id));
}

void Interpreter::visitIndexExpression()
{
    auto index = stack.pop()->getValue();
    auto value = dynamic_cast<Index *>(stack.pop());
    stack.push(value->index(index));
}

void Interpreter::visitSimpleSliceExpression(bool lowDeclared, bool highDeclared)
{
    Value *high = highDeclared ? stack.pop()->getValue(): nullptr;
    Value *low = lowDeclared ? stack.pop()->getValue() : nullptr;

    auto value = dynamic_cast<SimpleSlice *>(stack.pop());
    stack.push(value->simpleSlice(low, high));
}

void Interpreter::visitFullSliceExpression(bool lowDeclared)
{
    Value *max = stack.pop()->getValue();
    Value *high = stack.pop()->getValue();
    Value *low = lowDeclared ? stack.pop()->getValue() : nullptr;

    auto value = dynamic_cast<FullSlice *>(stack.pop());
    stack.push(value->fullSlice(low, high, max));
}

void Interpreter::visitCallExpression(long size)
{
    auto arguments = stack.pop(size);
    std::reverse(arguments.begin(), arguments.end());
    
    for (int i = 0; i < arguments.size(); ++i) {
        arguments[i] = arguments[i]->getValue();
    }

    auto value = dynamic_cast<Call *>(stack.pop());

    ret = false;
    auto result = value->call(arguments);
    ret = false;

    if (result != nullptr) stack.push(result);
}

void Interpreter::visitConversionExpression()
{
    // FIXME:
}

void Interpreter::visitUnaryPlusExpression()
{
    auto value = dynamic_cast<UnaryPlus *>(stack.pop());
    stack.push(value->unaryPlus());
}

void Interpreter::visitUnaryNegateExpression()
{
    auto value = dynamic_cast<Negate *>(stack.pop());
    stack.push(value->negate());
}

void Interpreter::visitUnaryLogicalNotExpression()
{
    auto value = dynamic_cast<LogicalNot *>(stack.pop());
    stack.push(value->logicalNot());
}

void Interpreter::visitUnaryBitwiseNotExpression()
{
    auto value = dynamic_cast<BitwiseNot *>(stack.pop());
    stack.push(value->bitwiseNot());
}

void Interpreter::visitUnaryDereferenceExpression()
{
    auto value = dynamic_cast<Dereference *>(stack.pop());
    stack.push(value->dereference());
}

void Interpreter::visitUnaryReferenceExpression()
{
    auto value = dynamic_cast<Reference *>(stack.pop());
    stack.push(value->reference());
}

void Interpreter::visitBinaryLogicalOrExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<LogicalOr *>(stack.pop());
    stack.push(lhs->logicalOr(rhs));
}

void Interpreter::visitBinaryLogicalAndExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<LogicalAnd *>(stack.pop());
    stack.push(lhs->logicalAnd(rhs));
}

void Interpreter::visitBinaryEqualExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Equal *>(stack.pop());
    stack.push(lhs->equal(rhs));
}

void Interpreter::visitBinaryNotEqualExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<NotEqual *>(stack.pop());
    stack.push(lhs->notEqual(rhs));
}

void Interpreter::visitBinaryLessThanExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<LessThan *>(stack.pop());
    stack.push(lhs->lessThan(rhs));
}

void Interpreter::visitBinaryLessThanEqualExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<LessThanEqual *>(stack.pop());
    stack.push(lhs->lessThanEqual(rhs));
}

void Interpreter::visitBinaryGreaterThanExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<GreaterThan *>(stack.pop());
    stack.push(lhs->greaterThan(rhs));
}

void Interpreter::visitBinaryGreaterThanEqualExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<GreaterThanEqual *>(stack.pop());
    stack.push(lhs->greaterThanEqual(rhs));
}

void Interpreter::visitBinaryShiftLeftExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<ShiftLeft *>(stack.pop());
    stack.push(lhs->shiftLeft(rhs));
}

void Interpreter::visitBinaryShiftRightExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<ShiftRight *>(stack.pop());
    stack.push(lhs->shiftRight(rhs));
}

void Interpreter::visitBinaryAddExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Add *>(stack.pop());
    stack.push(lhs->add(rhs));
}

void Interpreter::visitBinarySubtractExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Subtract *>(stack.pop());
    stack.push(lhs->subtract(rhs));
}

void Interpreter::visitBinaryBitwiseOrExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<BitwiseOr *>(stack.pop());
    stack.push(lhs->bitwiseOr(rhs));
}

void Interpreter::visitBinaryBitwiseXOrExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<BitwiseXOr *>(stack.pop());
    stack.push(lhs->bitwiseXOr(rhs));
}

void Interpreter::visitBinaryBitwiseAndExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<BitwiseAnd *>(stack.pop());
    stack.push(lhs->bitwiseAnd(rhs));
}

void Interpreter::visitBinaryMultiplyExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Multiply *>(stack.pop());
    stack.push(lhs->multiply(rhs));
}

void Interpreter::visitBinaryDivideExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Divide *>(stack.pop());
    stack.push(lhs->divide(rhs));
}

void Interpreter::visitBinaryModuloExpression()
{
    auto rhs = stack.pop();
    auto lhs = dynamic_cast<Modulo *>(stack.pop());
    stack.push(lhs->modulo(rhs));
}
