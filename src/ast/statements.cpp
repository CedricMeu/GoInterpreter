#include "ast/statements.hpp"

AST::DeclarationStatement::DeclarationStatement(Declaration *declaration)
    : declaration{declaration}
{}

AST::DeclarationStatement::~DeclarationStatement()
{
    delete declaration;
}

void AST::DeclarationStatement::accept(Visitor *visitor) 
{
    this->declaration->accept(visitor);
}