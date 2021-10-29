#include "ast/base.hpp"

AST::Block::Block(std::vector<Statement *> statements)
    :statements{statements}
{}

AST::Block::~Block()
{
    for (const auto statement : this->statements)
    {
        delete statement;
    }
}

void AST::Block::accept(Visitor *visitor)
{
    visitor->visitInitBlock(this->statements.size());

    auto rev = this->statements;
    std::reverse(rev.begin(), rev.end());

    for (const auto statement : rev)
    {
        statement->accept(visitor);
    }

    visitor->visitDeinitBlock(this->statements.size());
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

void AST::Program::accept(Visitor *visitor)
{
    auto rev = this->declarations;
    std::reverse(rev.begin(), rev.end());

    for (const auto declaration : rev)
    {
        declaration->accept(visitor);
    }

    visitor->visitProgram(this->declarations.size());
}
