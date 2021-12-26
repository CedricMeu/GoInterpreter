#include "ast/statements.hpp"

AST::DeclarationStatement::DeclarationStatement(Declaration *declaration)
    : declaration{declaration}
{}

AST::DeclarationStatement::~DeclarationStatement()
{
    delete declaration;
}

void AST::DeclarationStatement::accept(Visitor *visitor) const
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

void AST::ExpressionStatement::accept(Visitor *visitor) const
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

void AST::AssignmentStatement::accept(Visitor *visitor) const
{

    auto visitLhs = [this, visitor](){
        for (const auto expression : this->lhs)
        {
            expression->accept(visitor);
        }

        return this->lhs.size();
    };

    auto visitRhs = [this, visitor](){
        for (const auto expression : this->rhs)
        {
            expression->accept(visitor);
        }

        return this->rhs.size();
    };

    visitor->visitAssignmentStatement(visitLhs, visitRhs);
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

void AST::IfStatement::accept(Visitor *visitor) const
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

AST::SwitchStatement::SwitchExpressionClause::SwitchExpressionClause(std::vector<Expression *> expressions, std::vector<Statement *> statements)
    : expressions{expressions}, statements{statements}
{}

AST::SwitchStatement::SwitchExpressionClause::~SwitchExpressionClause()
{
    for (const auto expression : this->expressions) {
        delete expression;
    }

    for (const auto statement : this->statements) {
        delete statement;
    }
}

void AST::SwitchStatement::SwitchExpressionClause::accept(Visitor *visitor) const
{
    std::vector<const std::function<void ()>> visitExpressions{};
    std::vector<const std::function<void ()>> visitStatements{};

    for (const auto expression : this->expressions) {
        visitExpressions.push_back([expression, visitor]() {
            expression->accept(visitor);
        });
    }

    for (const auto statement : this->statements) {
        visitStatements.push_back([statement, visitor]() {
            statement->accept(visitor);
        });
    }

    visitor->visitSwitchExpressionClause(visitExpressions, visitStatements);
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

void AST::SwitchStatement::SwitchDefaultClause::accept(Visitor *visitor) const
{
    std::vector<const std::function<void ()>> visitStatements{};

    for (const auto statement : this->statements) {
        visitStatements.push_back([statement, visitor]() {
            statement->accept(visitor);
        });
    }

    visitor->visitSwitchDefaultClause(visitStatements);
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

void AST::SwitchStatement::SwitchStatement::accept(Visitor *visitor) const
{  
    std::vector<const std::function<void ()>> visitClauses{};

    for (const auto clause : this->clauses) {
        visitClauses.push_back([clause, visitor]() {
            clause->accept(visitor);
        });
    }

    visitor->visitSwitchStatement([this, visitor]() {
        this->expression->accept(visitor);
    }, visitClauses);
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

void AST::ReturnStatement::accept(Visitor *visitor) const
{
    for (const auto expression : this->expressions) {
        expression->accept(visitor);
    }

    visitor->visitReturnStatement(this->expressions.size());
}

void AST::BreakStatement::accept(Visitor *visitor) const
{
    visitor->visitBreakStatement();
}

void AST::ContinueStatement::accept(Visitor *visitor) const
{
    visitor->visitContinueStatement();
}

void AST::EmptyStatement::accept(Visitor *visitor) const
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

void AST::ForConditionStatement::accept(Visitor *visitor) const
{
    visitor->visitForConditionStatement([this, visitor]() {
        this->init->accept(visitor);
    }, [this, visitor]() {
        this->condition->accept(visitor);
    }, [this, visitor]() {
        this->post->accept(visitor);
    }, [this, visitor]() {
        this->body->accept(visitor);
    });
}
