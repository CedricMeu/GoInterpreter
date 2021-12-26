#include "ast/declarations.hpp"

AST::FunctionDeclaration::FunctionDeclaration(std::string id, Type *signature, Block *body)
    : id{id}, signature{signature}, body{body}
{}

AST::FunctionDeclaration::~FunctionDeclaration()
{
    delete signature;
    delete body;
}

void AST::FunctionDeclaration::accept(Visitor *visitor) const
{
    visitor->visitFunctionDeclaration(this->id, [this, visitor]() {
        this->signature->accept(visitor);
    }, [this, visitor]() {
        this->body->accept(visitor);
    });
}

AST::TypeAliasDeclaration::TypeAliasDeclaration(std::string id, Type *underlyingType)
    :id{id}, underlyingType{underlyingType}
{}

AST::TypeAliasDeclaration::~TypeAliasDeclaration()
{
    delete underlyingType;
}

void AST::TypeAliasDeclaration::accept(Visitor *visitor) const
{
    this->underlyingType->accept(visitor);
    visitor->visitTypeAliasDeclaration(this->id);
}

AST::TypeDefinitionDeclaration::TypeDefinitionDeclaration(std::string id, Type *underlyingType)
    :id{id}, underlyingType{underlyingType}
{}

AST::TypeDefinitionDeclaration::~TypeDefinitionDeclaration()
{
    delete underlyingType;
}

void AST::TypeDefinitionDeclaration::accept(Visitor *visitor) const
{
    this->underlyingType->accept(visitor);
    visitor->visitTypeDefinitionDeclaration(this->id);
}

AST::VariableDeclaration::VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions)
    :ids{ids}, type{type}, expressions{expressions}
{}

AST::VariableDeclaration::~VariableDeclaration()
{
    if (type != nullptr) delete type;

    for (const auto expression : expressions)
    {
        delete expression;
    }
}

void AST::VariableDeclaration::accept(Visitor *visitor) const
{
    if (type != nullptr) 
    {
        type->accept(visitor);
    }

    for (const auto expression : this->expressions)
    {
        expression->accept(visitor);
    }

    visitor->visitVariableDeclaration(this->ids, type != nullptr, this->expressions.size());
}