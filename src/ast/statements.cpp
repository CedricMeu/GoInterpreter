#include "ast/statements.hpp"

AST::TypeAliasStatement::TypeAliasStatement(std::string id, Type *underlyingType)
    :id{id}, underlyingType{underlyingType}
{}

AST::TypeAliasStatement::~TypeAliasStatement()
{
    delete underlyingType;
}

void AST::TypeAliasStatement::accept(Visitor *visitor)
{
    this->underlyingType->accept(visitor);
    visitor->visitTypeAliasStatement(this->id);
}

AST::TypeDefinitionStatement::TypeDefinitionStatement(std::string id, Type *underlyingType)
    :id{id}, underlyingType{underlyingType}
{}

AST::TypeDefinitionStatement::~TypeDefinitionStatement()
{
    delete underlyingType;
}

void AST::TypeDefinitionStatement::accept(Visitor *visitor)
{
    this->underlyingType->accept(visitor);
    visitor->visitTypeDefinitionStatement(this->id);
}

AST::VariableDeclarationStatement::VariableDeclarationStatement(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions)
    :ids{ids}, type{type}, expressions{expressions}
{}

AST::VariableDeclarationStatement::~VariableDeclarationStatement()
{
    if (type != nullptr) delete type;

    for (const auto expression : expressions)
    {
        delete expression;
    }
}

void AST::VariableDeclarationStatement::accept(Visitor *visitor)
{
    for (const auto expression : expressions)
    {
        expression->accept(visitor);
    }

    if (type != nullptr) 
    {
        type->accept(visitor);
    }

    visitor->visitVariableDeclarationStatement(this->ids, type != nullptr, this->expressions.size());
}