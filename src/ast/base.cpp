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

    for (const auto statement : this->statements)
    {
        statement->accept(visitor);
    }

    visitor->visitDeinitBlock(this->statements.size());
}