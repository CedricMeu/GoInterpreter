#ifndef GOINTERPRETER_AST_EXPRESSIONS_HPP
#define GOINTERPRETER_AST_EXPRESSIONS_HPP

#include "ast/base.hpp"
#include "ast/literals.hpp"

namespace AST {

    class IdentifierExpression : public Expression
    {
    public:
        IdentifierExpression(std::string id);
        virtual ~IdentifierExpression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::string id;
    };

    class CompositLiteralExpression : public Expression
    {
    public:
        CompositLiteralExpression(Type *type, std::vector<std::pair<std::string, Expression *>> elements);
        virtual ~CompositLiteralExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Type *type;
        std::vector<std::pair<std::string, Expression *>> elements;
    };

    class FunctionLiteralExpression : public Expression {
    public:
        FunctionLiteralExpression(Type *signature, Block *body);
        virtual ~FunctionLiteralExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Type *signature;
        Block *body;
    };

    class SelectExpression : public Expression 
    {
    public:
        SelectExpression(Expression *expression, std::string id);
        virtual ~SelectExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
        std::string id;
    };

    class IndexExpression : public Expression 
    {
    public:
        IndexExpression(Expression *expression, Expression *index);
        virtual ~IndexExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
        Expression *index;
    };

    class SimpleSliceExpression : public Expression 
    {
    public:
        SimpleSliceExpression(Expression *expression, Expression *low, Expression *high);
        virtual ~SimpleSliceExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
        Expression *low;
        Expression *high;
    };

    class FullSliceExpression : public Expression 
    {
    public:
        FullSliceExpression(Expression *expression, Expression *low, Expression *high, Expression *max);
        virtual ~FullSliceExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
        Expression *low;
        Expression *high;
        Expression *max;
    };

    class CallExpression : public Expression 
    {
    public:
        CallExpression(Expression *expression, std::vector<Expression *> arguments);
        virtual ~CallExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
        std::vector<Expression *> arguments;
    };

    class ConversionExpression : public Expression
    {
    public:
        ConversionExpression(Type *type, Expression* expression);
        virtual ~ConversionExpression() override;
        virtual void accept(Visitor *visitor) const override;
    
    private:
        Type *type;
        Expression *expression;
    };
};

#endif // GOINTERPRETER_AST_EXPRESSIONS_HPP