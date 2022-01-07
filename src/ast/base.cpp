#include "ast/base.hpp"

AST::Block::Block(std::vector<Statement *> statements)
    :statements{statements}
{}

AST::Block::~Block()
{
    for (const auto statement : statements)
    {
        delete statement;
    }
}

void AST::Block::accept(Visitor *visitor) const
{
    std::vector<const std::function<void ()>> visitStatements;

    for (const auto statement : this->statements)
    {
        visitStatements.push_back([visitor, statement]() {
            statement->accept(visitor);
        });
    }

    visitor->visitBlock(visitStatements);
}

AST::Program::Program(std::vector<TopLevelDeclaration *> declarations)
    : declarations{declarations}
{}

AST::Program::~Program()
{
    for (const auto declaration : this->declarations)
    {
        delete declaration;
    }
}

void AST::Program::accept(Visitor *visitor) const
{
    for (const auto declaration : this->declarations)
    {
        declaration->accept(visitor);
    }

    visitor->visitProgram(this->declarations.size());
}
