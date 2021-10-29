#ifndef GOINTERPRETER_AST_EXPRESSIONS_HPP
#define GOINTERPRETER_AST_EXPRESSIONS_HPP

#include "ast/base.hpp"
#include "ast/literals.hpp"

namespace AST {

    class IdentifierExpression : public Expression
    {
    private:
        std::string id;

    public:
        IdentifierExpression(std::string id);
        ~IdentifierExpression() = default;
        virtual void accept(Visitor *visitor) override;
    };
};

#endif // GOINTERPRETER_AST_EXPRESSIONS_HPP