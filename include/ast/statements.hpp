#ifndef GOINTERPRETER_AST_STATEMENTS_HPP
#define GOINTERPRETER_AST_STATEMENTS_HPP

#include "ast/base.hpp"

namespace AST {

    class DeclarationStatement : public Statement 
    {
    private:
        Declaration *declaration;

    public:
        DeclarationStatement(Declaration *declaration);
        virtual ~DeclarationStatement();
        virtual void accept(Visitor *visitor) override;
    };

    class ExpressionStatement : public Statement 
    {
    private:
        Expression *expression;

    public:
        ExpressionStatement(Expression *expression);
        ~ExpressionStatement();
        virtual void accept(Visitor *visitor) override;
    };

    class AssignmentStatement : public Statement
    {
    private:
        std::vector<Expression *> lhs;
        std::vector<Expression *> rhs;

    public:
        AssignmentStatement(std::vector<Expression *> lhs, std::vector<Expression *> rhs);
        ~AssignmentStatement();
        virtual void accept(Visitor *visitor) override;
    };

    class IfStatement : public Statement
    {
    private:
        Expression *condition;
        Block *trueBody;
        Block *falseBody;

    public:
        IfStatement(Expression *condition, Block *trueBody, Block *falseBody);
        ~IfStatement();
        virtual void accept(Visitor *visitor) override;
    };

};

#endif // GOINTERPRETER_AST_STATEMENTS_HPP