#include "ast/literals.hpp"

AST::BoolExpression::BoolExpression(bool value)
    :value{value}
{}

void AST::BoolExpression::accept(Visitor *visitor)
{
    visitor->visitBoolExpression(this->value);
}

AST::IntExpression::IntExpression(int value)
    :value{value}
{}

void AST::IntExpression::accept(Visitor *visitor)
{
    visitor->visitIntExpression(this->value);
}

AST::Float32Expression::Float32Expression(float value)
    :value{value}
{}

void AST::Float32Expression::accept(Visitor *visitor)
{
    visitor->visitFloat32Expression(this->value);
}

AST::RuneExpression::RuneExpression(char value)
    :value{value}
{}

void AST::RuneExpression::accept(Visitor *visitor)
{
    visitor->visitRuneExpression(this->value);
}

AST::StringExpression::StringExpression(char *value, long length)
    :value{value}, length{length}
{}

AST::StringExpression::~StringExpression()
{
    delete value;
}

void AST::StringExpression::accept(Visitor *visitor)
{
    visitor->visitStringExpression(this->value, this->length);
}