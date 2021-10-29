#ifndef GOINTERPRETER_AST_STATEMENTS_HPP
#define GOINTERPRETER_AST_STATEMENTS_HPP

#include "ast/base.hpp"

namespace AST {

    class DeclarationStatement : public Statement {
    private:
        Declaration *declaration;

    public:
        DeclarationStatement(Declaration *declaration);
        virtual ~DeclarationStatement();
        virtual void accept(Visitor *visitor) override;
    };

};

#endif // GOINTERPRETER_AST_STATEMENTS_HPP