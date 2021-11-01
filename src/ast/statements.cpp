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

AST::SwitchStatement::SwitchCaseClause::SwitchCaseClause(std::vector<Expression *> expressions, std::vector<Statement *> statements)
    : expressions{expressions}, statements{statements}
{}

AST::SwitchStatement::SwitchCaseClause::~SwitchCaseClause()
{
    for (const auto expression : this->expressions) {
        delete expression;
    }

    for (const auto statement : this->statements) {
        delete statement;
    }
}

void AST::SwitchStatement::SwitchCaseClause::accept(Visitor *visitor)
{
    auto revstmt = this->statements;
    std::reverse(revstmt.begin(), revstmt.end());

    for (const auto statement : revstmt)
    {
        statement->accept(visitor);
    }

    auto revexp = this->expressions;
    std::reverse(revexp.begin(), revexp.end());

    for (const auto expression : revexp)
    {
        expression->accept(visitor);
    }

    visitor->visitSwitchCaseClause(this->expressions.size(), this->statements.size());
}

AST::SwitchStatement::SwitchDefaultClause::SwitchDefaultClause(std::vector<Statement *> statements)
    : statements{statements}
{}

AST::SwitchStatement::SwitchDefaultClause::~SwitchDefaultClause()
{
    for (const auto statement : this->statements) {
        delete statement;
    }
}

void AST::SwitchStatement::SwitchDefaultClause::accept(Visitor *visitor)
{
    auto revstmt = this->statements;
    std::reverse(revstmt.begin(), revstmt.end());

    for (const auto statement : revstmt)
    {
        statement->accept(visitor);
    }

    visitor->visitSwitchDefaultClause(this->statements.size());
}

AST::SwitchStatement::SwitchStatement::SwitchStatement(Expression *expression, std::vector<SwitchClause *> clauses)
    : expression{expression}, clauses{clauses}
{}

AST::SwitchStatement::SwitchStatement::~SwitchStatement()
{
    delete expression;

    for (const auto clause : this->clauses) {
        delete clause;
    }
}

void AST::SwitchStatement::SwitchStatement::accept(Visitor *visitor)
{
    auto revclauses = this->clauses;
    std::reverse(revclauses.begin(), revclauses.end());

    for (const auto clause : revclauses) {
        clause->accept(visitor);
    }

    this->expression->accept(visitor);

    visitor->visitSwitchStatement(this->clauses.size());
}

AST::ReturnStatement::ReturnStatement(std::vector<Expression *> expressions)
    : expressions{expressions}
{}

AST::ReturnStatement::~ReturnStatement()
{
    for (const auto expression : this->expressions) {
        delete expression;
    }
}

void AST::ReturnStatement::accept(Visitor* visitor)
{
    auto revexp = this->expressions;
    std::reverse(revexp.begin(), revexp.end());

    for (const auto expression : revexp) {
        expression->accept(visitor);
    }

    visitor->visitReturnStatement(this->expressions.size());
}

void AST::BreakStatement::accept(Visitor* visitor)
{
    visitor->visitBreakStatement();
}

void AST::ContinueStatement::accept(Visitor* visitor)
{
    visitor->visitContinueStatement();
}

void AST::EmptyStatement::accept(Visitor* visitor) 
{
    visitor->visitEmptyStatement();
}

AST::ForConditionStatement::ForConditionStatement(SimpleStatement *init, Expression *condition, SimpleStatement *post, Block *body)
    : init{init}, condition{condition}, post{post}, body{body}
{}

AST::ForConditionStatement::~ForConditionStatement()
{
    delete this->init;
    delete this->condition;
    delete this->post;
    delete this->body;
}

void AST::ForConditionStatement::accept(Visitor* visitor)
{
    this->body->accept(visitor);
    this->post->accept(visitor);
    this->condition->accept(visitor);
    this->init->accept(visitor);

    visitor->visitForConditionStatement();
}
