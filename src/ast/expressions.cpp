#include "ast/expressions.hpp"

AST::IdentifierExpression::IdentifierExpression(std::string id)
    : id{id}
{}

void AST::IdentifierExpression::accept(Visitor *visitor)
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

void AST::CompositLiteralExpression::accept(Visitor *visitor)
{
    std::vector<std::string> keys;
    std::vector<Expression *> expressions;

    for (const auto pair : this->elements) {
        keys.push_back(pair.first);
        expressions.push_back(pair.second);
    }
    
    std::reverse(expressions.begin(), expressions.end());

    for (const auto expression : expressions) {
        expression->accept(visitor);
    }

    type->accept(visitor);

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

void AST::FunctionLiteralExpression::accept(Visitor *visitor)
{
    body->accept(visitor);
    signature->accept(visitor);
    visitor->VisitFunctionLiteralExpression();
}