#include "ast/expressions.hpp"

AST::IdentifierExpression::IdentifierExpression(std::string id)
    : id{id}
{}

void AST::IdentifierExpression::accept(Visitor *visitor)
{
    visitor->visitIdentifierExpression(this->id);
}