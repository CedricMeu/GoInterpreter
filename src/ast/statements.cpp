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

AST::ExpressionStatement::ExpressionStatement(Expression *expression)
    :expression{expression}
{}

AST::ExpressionStatement::~ExpressionStatement()
{
    delete expression;
}

void AST::ExpressionStatement::accept(Visitor *visitor)
{
    expression->accept(visitor);
    visitor->visitExpressionStatement();
}

AST::AssignmentStatement::AssignmentStatement(std::vector<Expression *> lhs, std::vector<Expression *> rhs)
    : lhs{lhs}, rhs{rhs}
{}

AST::AssignmentStatement::~AssignmentStatement()
{
    for (const auto expression : this->lhs)
    {
        delete expression;
    }

    for (const auto expression : this->rhs)
    {
        delete expression;
    }
}

void AST::AssignmentStatement::accept(Visitor *visitor)
{
    
    auto revrhs = this->rhs;
    std::reverse(revrhs.begin(), revrhs.end());

    for (const auto expression : revrhs)
    {
        expression->accept(visitor);
    }

    auto revlhs = this->lhs;
    std::reverse(revlhs.begin(), revlhs.end());

    for (const auto expression : revlhs)
    {
        expression->accept(visitor);
    }

    visitor->visitAssignmentStatement(this->lhs.size(), this->rhs.size());
}

AST::IfStatement::IfStatement(Expression *condition, Block *trueBody, Block *falseBody)
    : condition{condition}, trueBody{trueBody}, falseBody{falseBody}
{}

AST::IfStatement::~IfStatement()
{
    delete this->condition;
    delete this->trueBody;
    delete this->falseBody;
}

void AST::IfStatement::accept(Visitor *visitor)
{
    condition->accept(visitor);

    auto visitTrue = [this, visitor](){
        this->trueBody->accept(visitor);
    };

    auto visitFalse = [this, visitor](){
        this->falseBody->accept(visitor);
    };

    visitor->visitIfStatement(visitTrue, visitFalse);
}
