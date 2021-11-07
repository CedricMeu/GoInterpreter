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
        virtual void accept(Visitor *visitor) override;

    private:
        std::string id;
    };

    class CompositLiteralExpression : public Expression
    {
    public:
        CompositLiteralExpression(Type *type, std::vector<std::pair<std::string, Expression *>> elements);
        virtual ~CompositLiteralExpression() override;
        virtual void accept(Visitor *visitor) override;

    private:
        Type *type;
        std::vector<std::pair<std::string, Expression *>> elements;
    };
};

#endif // GOINTERPRETER_AST_EXPRESSIONS_HPP