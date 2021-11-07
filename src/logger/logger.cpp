#include "logger/logger.hpp"

std::string Logger::Logger::tab(std::string str) const
{
    return "\t" + str;
}

std::string Logger::Logger::getLogString() const
{
    std::string result = "";
    
    for (const auto &block : this->infoBlockStack)
    {
        for (const auto &line : block)
        {
            result += line + '\n';
        }
    }

    return result;
}

void Logger::Logger::visitProgram(long size) 
{
    Logger::Logger::InfoBlock result = {"Program"};

    result.push_back("- declarations: ");

    for (int i = 0; i < size; ++i)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
} 

void Logger::Logger::visitBoolType()
{
    this->infoBlockStack.push_back({"BoolType"});
}

void Logger::Logger::visitIntType()
{
    this->infoBlockStack.push_back({"IntType"});
}

void Logger::Logger::visitFloat32Type()
{
    this->infoBlockStack.push_back({"Float32Type"});
}

void Logger::Logger::visitRuneType()
{
    this->infoBlockStack.push_back({"RuneType"});
}

void Logger::Logger::visitStringType()
{
    this->infoBlockStack.push_back({"StringType"});
}

void Logger::Logger::visitArrayType(long size)
{
    Logger::Logger::InfoBlock result = {"ArrayType"};

    result.push_back("- size: " + std::to_string(size));
    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitSliceType()
{
    Logger::Logger::InfoBlock result = {"SliceType"};

    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitStructType(std::vector<std::string> fields)
{
    Logger::Logger::InfoBlock result = {"StructType"};

    result.push_back("- fields: ");

    for (const auto &field : fields)
    {
        result.push_back(this->tab("- \"" + field + "\":"));
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(this->tab(line)));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitPointerType()
{
    Logger::Logger::InfoBlock result = {"PointerType"};

    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns)
{
    Logger::Logger::InfoBlock result = {"FunctionType"};

    result.push_back("- parameters: ");

    for (const auto &parameter : parameters)
    {
        result.push_back(this->tab("- \"" + parameter + "\":"));
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(this->tab(line)));
        }
        this->infoBlockStack.pop_back();
    }

    result.push_back("- returns: ");

    for (const auto &ret : returns)
    {
        result.push_back(this->tab("- \"" + ret + "\":"));
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(this->tab(line)));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitMapType()
{
    Logger::Logger::InfoBlock result = {"MapType"};

    result.push_back("- key type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- element type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitCustomType(std::string id)
{
    Logger::Logger::InfoBlock result = {"CustomType"};

    result.push_back("- id: " + id);

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitInitBlock(long size)
{
    // Nothing
}

void Logger::Logger::visitDeinitBlock(long size)
{
    Logger::Logger::InfoBlock result = {"Block"};

    result.push_back("- statements: ");

    for (int i = 0; i < size; ++i)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitFunctionDeclaration(std::string id)
{
    Logger::Logger::InfoBlock result = {"Function"};

    result.push_back("- id: " + id);

    result.push_back("- signature: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- body: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitTypeAliasDeclaration(std::string id)
{
    Logger::Logger::InfoBlock result = {"TypeAlias"};

    result.push_back("- id: " + id);

    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitTypeDefinitionDeclaration(std::string id)
{
    Logger::Logger::InfoBlock result = {"TypeDefinition"};

    result.push_back("- id: " + id);

    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count)
{
    Logger::Logger::InfoBlock result = {"VariableDeclaration"};

    if (typeDeclared)
    {
        result.push_back("- type: ");

        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    result.push_back("- ids: ");

    for (int i = 0; i < ids.size(); i++)
    {
        const auto id = ids[i];

        result.push_back(this->tab("- \"" + id + "\":"));
        if (i < expression_count) {
            for (const auto &line : this->infoBlockStack.back())
            {
                result.push_back(this->tab(this->tab(line)));
            }
            this->infoBlockStack.pop_back();
        }
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitExpressionStatement()
{
    Logger::Logger::InfoBlock result = {"ExpressionStatement"};

    result.push_back("- expression: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitAssignmentStatement(long lhsSize, long rhsSize)
{
    Logger::Logger::InfoBlock result = {"AssignmentStatement"};

    result.push_back("- lhs: ");

    for (int i = 0; i < lhsSize; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    result.push_back("- rhs: ");

    for (int i = 0; i < rhsSize; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse)
{
    Logger::Logger::InfoBlock result = {"IfStatement"};

    result.push_back("- condition: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    visitTrue();

    result.push_back("- true: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    visitFalse();

    result.push_back("- false: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitSwitchStatement(long size)
{
    Logger::Logger::InfoBlock result = {"SwitchStatement"};

    result.push_back("- expression");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- cases: ");

    for (int i = 0; i < size; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitSwitchCaseClause(long expressionsSize, long statementsSize)
{
    Logger::Logger::InfoBlock result = {"CaseClause"};

    result.push_back("- expressions: ");

    for (int i = 0; i < expressionsSize; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    result.push_back("- statements: ");

    for (int i = 0; i < statementsSize; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitSwitchDefaultClause(long statementsSize)
{
    Logger::Logger::InfoBlock result = {"DefaultClause"};

    result.push_back("- statements: ");

    for (int i = 0; i < statementsSize; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitReturnStatement(long size)
{
    Logger::Logger::InfoBlock result = {"ReturnStatement"};

    result.push_back("- expressions: ");

    for (int i = 0; i < size; i++)
    {
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(line));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result); 
}

void Logger::Logger::visitBreakStatement()
{
    Logger::Logger::InfoBlock result = {"BreakStatement"};
    this->infoBlockStack.push_back(result); 
}

void Logger::Logger::visitContinueStatement()
{
    Logger::Logger::InfoBlock result = {"ContinueStatement"};
    this->infoBlockStack.push_back(result); 
}

void Logger::Logger::visitEmptyStatement()
{
    Logger::Logger::InfoBlock result = {"EmptyStatement"};
    this->infoBlockStack.push_back(result); 
}

void Logger::Logger::visitForConditionStatement()
{
    Logger::Logger::InfoBlock result = {"ForConditionStatement"};

    result.push_back("- init: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- condition: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- post: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- body: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    this->infoBlockStack.push_back(result); 
}

void Logger::Logger::visitBoolExpression(bool value)
{
    Logger::Logger::InfoBlock result = {std::string{"BoolLiteral: "} + (value ? "true" : "false")};

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitIntExpression(int value)
{
    Logger::Logger::InfoBlock result = {"IntLiteral: " + std::to_string(value)};

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitFloat32Expression(float value)
{
    Logger::Logger::InfoBlock result = {"FloatLiteral: " + std::to_string(value)};

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitRuneExpression(char value)
{
    Logger::Logger::InfoBlock result = {"RuneLiteral: " + std::to_string(value)};

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitStringExpression(char *value, long length)
{
    std::string str;

    for (int i = 0; i < length; ++i)
    {
        if (value[i] != '\0') {
            str += value[i];
        }
    }
    
    Logger::Logger::InfoBlock result = {"StringLiteral: " + str};

    result.push_back("- length: " + std::to_string(length));

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitIdentifierExpression(std::string id)
{
    Logger::Logger::InfoBlock result = {"IdentifierExpression"};

    result.push_back("- id: " + id);

    this->infoBlockStack.push_back(result);
}

void Logger::Logger::visitCompositLiteralExpression(std::vector<std::string> keys)
{
    Logger::Logger::InfoBlock result = {"CompositLiteralExpression"};

    result.push_back("- type: ");

    for (const auto &line : this->infoBlockStack.back())
    {
        result.push_back(this->tab(line));
    }
    this->infoBlockStack.pop_back();

    result.push_back("- elements: ");

    for (const auto &key : keys)
    {
        result.push_back(this->tab("- \"" + key + "\":"));
        for (const auto &line : this->infoBlockStack.back())
        {
            result.push_back(this->tab(this->tab(line)));
        }
        this->infoBlockStack.pop_back();
    }

    this->infoBlockStack.push_back(result);
}