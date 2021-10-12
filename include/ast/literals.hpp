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
        virtual auto print() -> std::string;
    };

    class IntExpression : public Expression
    {
    private:
        int value;

    public:
        IntExpression(int value);
        ~IntExpression() = default;
        virtual auto print() -> std::string;
    };

    class Float32Expression : public Expression
    {
    private:
        float value;

    public:
        Float32Expression(float value);
        ~Float32Expression() = default;
        virtual auto print() -> std::string;
    };

    class RuneExpression : public Expression
    {
    private:
        char value;

    public:
        RuneExpression(char value);
        ~RuneExpression() = default;
        virtual auto print() -> std::string;
    };
    
};

#endif // GOINTERPRETER_AST_LITERALS_HPP