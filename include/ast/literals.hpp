#ifndef GOINTERPRETER_AST_LITERALS_HPP
#define GOINTERPRETER_AST_LITERALS_HPP

#include <string>
#include <iomanip>
#include <sstream>
#include "ast/base.hpp"

namespace AST {

    class BoolExpression : public Expression
    {
    public:
        BoolExpression(bool value);
        virtual ~BoolExpression() override = default;
        virtual void accept(Visitor *visitor) const override;
    private:
        bool value;
    };

    class IntExpression : public Expression
    {
    public:
        IntExpression(int value);
        virtual ~IntExpression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        int value;
    };

    class Float32Expression : public Expression
    {
    public:
        Float32Expression(float value);
        virtual ~Float32Expression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        float value;
    };

    class RuneExpression : public Expression
    {
    public:
        RuneExpression(char value);
        virtual ~RuneExpression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        char value;
    };

    class StringExpression : public Expression 
    {
    public:
        StringExpression(char *value, long lenght);
        virtual ~StringExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        char *value;
        long length;
    };
    
};

#endif // GOINTERPRETER_AST_LITERALS_HPP