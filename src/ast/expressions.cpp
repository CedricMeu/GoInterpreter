#include "ast/expressions.hpp"

AST::IdentifierExpression::IdentifierExpression(std::string id)
    : id{id}
{}

void AST::IdentifierExpression::accept(Visitor *visitor) const
{
    visitor->visitIdentifierExpression(this->id);
}

AST::CompositLiteralExpression::CompositLiteralExpression(Type *type, std::vector<std::pair<std::string, Expression *>> elements)
    : type{type}, elements{elements}
{}

AST::CompositLiteralExpression::~CompositLiteralExpression()
{
    delete type;
    for(const auto pair : elements) {
        delete pair.second;
    }
}

void AST::CompositLiteralExpression::accept(Visitor *visitor) const
{
    type->accept(visitor);
    
    std::vector<std::string> keys;
    std::vector<Expression *> expressions;

    for (const auto pair : this->elements) {
        keys.push_back(pair.first);
        expressions.push_back(pair.second);
    }

    for (const auto expression : expressions) {
        expression->accept(visitor);
    }

    visitor->visitCompositLiteralExpression(keys);
}

AST::FunctionLiteralExpression::FunctionLiteralExpression(Type *signature, Block* body)
    : signature{signature}, body{body}
{}

AST::FunctionLiteralExpression::~FunctionLiteralExpression()
{
    delete signature;
    delete body;
}

void AST::FunctionLiteralExpression::accept(Visitor *visitor) const
{
    visitor->VisitFunctionLiteralExpression([this, visitor]() {
        signature->accept(visitor);
    }, [this, visitor]() {
        body->accept(visitor);
    });
}
        
AST::SelectExpression::SelectExpression(Expression *expression, std::string id)
    : expression{expression}, id{id}
{}

AST::SelectExpression::~SelectExpression()
{
    delete expression;
}

void AST::SelectExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);
    visitor->visitSelectExpression(id);
}

AST::IndexExpression::IndexExpression(Expression *expression, Expression *index)
    : expression{expression}, index{index}
{}

AST::IndexExpression::~IndexExpression()
{
    delete expression;
    delete index;
}

void AST::IndexExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);
    index->accept(visitor);
    visitor->visitIndexExpression();
}

AST::SimpleSliceExpression::SimpleSliceExpression(Expression *expression, Expression *low, Expression *high)
    : expression{expression}, low{low}, high{high}
{}

AST::SimpleSliceExpression::~SimpleSliceExpression()
{
    delete expression;
    delete low;
    delete high;
}

void AST::SimpleSliceExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);
    if (low != nullptr) low->accept(visitor);
    if (high != nullptr) high->accept(visitor);
    visitor->visitSimpleSliceExpression(low != nullptr, high != nullptr);
}

AST::FullSliceExpression::FullSliceExpression(Expression *expression, Expression *low, Expression *high, Expression *max)
    : expression{expression}, low{low}, high{high}, max{max}
{}

AST::FullSliceExpression::~FullSliceExpression()
{
    delete expression;
    delete low;
    delete high;
    delete max;
}

void AST::FullSliceExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);
    if (low != nullptr) low->accept(visitor);
    high->accept(visitor);
    max->accept(visitor);
    visitor->visitFullSliceExpression(low != nullptr);
}

AST::CallExpression::CallExpression(Expression *expression, std::vector<Expression *> arguments)
    : expression{expression}, arguments{arguments}
{}

AST::CallExpression::~CallExpression()
{
    delete expression;
    
    for (const auto argument : arguments)
    {
        delete argument;
    }
}

void AST::CallExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);

    for (const auto argument : this->arguments) {
        argument->accept(visitor);
    }

    visitor->visitCallExpression(arguments.size());
}

AST::ConversionExpression::ConversionExpression(Type *type, Expression* expression)
    : type{type}, expression{expression}
{}

AST::ConversionExpression::~ConversionExpression()
{
    delete type;
    delete expression;
}

void AST::ConversionExpression::accept(Visitor *visitor) const
{
    type->accept(visitor);
    expression->accept(visitor);
    visitor->visitConversionExpression();
}


AST::UnaryExpression::UnaryExpression(Operation operation, Expression * expression)
    : operation{operation}, expression{expression}
{}

AST::UnaryExpression::~UnaryExpression()
{
    delete expression;
}

void AST::UnaryExpression::accept(Visitor *visitor) const
{
    expression->accept(visitor);
    switch (operation)
    {
    case Operation::PLUS:
        visitor->visitUnaryPlusExpression();
        break;
    case Operation::NEGATE:
        visitor->visitUnaryNegateExpression();
        break;
    case Operation::L_NOT:
        visitor->visitUnaryLogicalNotExpression();
        break;
    case Operation::BW_NOT:
        visitor->visitUnaryBitwiseNotExpression();
        break;
    case Operation::DEREFERENCE:
        visitor->visitUnaryDereferenceExpression();
        break;
    case Operation::REFERENCE:
        visitor->visitUnaryReferenceExpression();
        break;
    }
}

AST::BinaryExpression::BinaryExpression(Operation operation, Expression *lhs, Expression* rhs)
    : operation{operation}, lhs{lhs}, rhs{rhs}
{}

AST::BinaryExpression::~BinaryExpression()
{
    delete lhs;
    delete rhs;
}

void AST::BinaryExpression::accept(Visitor *visitor) const
{
    lhs->accept(visitor);
    rhs->accept(visitor);

    switch (operation)
    {
    case Operation::L_OR:
        visitor->visitBinaryLogicalOrExpression();
        break;
    case Operation::L_AND:
        visitor->visitBinaryLogicalAndExpression();
        break;
    case Operation::EQ:
        visitor->visitBinaryEqualExpression();
        break;
    case Operation::NEQ:
        visitor->visitBinaryNotEqualExpression();
        break;
    case Operation::LT:
        visitor->visitBinaryLessThanExpression();
        break;
    case Operation::LTE:
        visitor->visitBinaryLessThanEqualExpression();
        break;
    case Operation::GT:
        visitor->visitBinaryGreaterThanExpression();
        break;
    case Operation::GTE:
        visitor->visitBinaryGreaterThanEqualExpression();
        break;
    case Operation::SHIFT_LEFT:
        visitor->visitBinaryShiftLeftExpression();
        break;
    case Operation::SHIFT_RIGHT:
        visitor->visitBinaryShiftRightExpression();
        break;
    case Operation::ADD:
        visitor->visitBinaryAddExpression();
        break;
    case Operation::SUB:
        visitor->visitBinarySubtractExpression();
        break;
    case Operation::BW_OR:
        visitor->visitBinaryBitwiseOrExpression();
        break;
    case Operation::BW_XOR:
        visitor->visitBinaryBitwiseXOrExpression();
        break;
    case Operation::BW_AND:
        visitor->visitBinaryBitwiseAndExpression();
        break;
    case Operation::MULT:
        visitor->visitBinaryMultiplyExpression();
        break;
    case Operation::DIV:
        visitor->visitBinaryDivideExpression();
        break;
    case Operation::MOD:
        visitor->visitBinaryModuloExpression();
        break;
    }
}
