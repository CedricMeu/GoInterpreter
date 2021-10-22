#ifndef GOINTERPRETER_AST_LITERALS_HPP
#define GOINTERPRETER_AST_LITERALS_HPP

#include <string>
#include <iomanip>
#include <sstream>
#include "ast/base.hpp"

namespace AST {

    class BoolExpression : public Expression
    {
    private:
        bool value;

    public:
        BoolExpression(bool value);
        ~BoolExpression() = default;
        virtual void accept(Visitor *visitor);
    };

    class IntExpression : public Expression
    {
    private:
        int value;

    public:
        IntExpression(int value);
        ~IntExpression() = default;
        virtual void accept(Visitor *visitor);
    };

    class Float32Expression : public Expression
    {
    private:
        float value;

    public:
        Float32Expression(float value);
        ~Float32Expression() = default;
        virtual void accept(Visitor *visitor);
    };

    class RuneExpression : public Expression
    {
    private:
        char value;

    public:
        RuneExpression(char value);
        ~RuneExpression() = default;
        virtual void accept(Visitor *visitor);
    };

    class StringExpression : public Expression 
    {
    private:
        char *value;
        long length;

    public:
        StringExpression(char *value, long lenght);
        ~StringExpression();
        virtual void accept(Visitor *visitor);
    };
    
};

#endif // GOINTERPRETER_AST_LITERALS_HPP