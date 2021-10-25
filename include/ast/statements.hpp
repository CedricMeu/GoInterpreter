#ifndef GOINTERPRETER_AST_STATEMENTS_HPP
#define GOINTERPRETER_AST_STATEMENTS_HPP

#include <string>
#include <vector>
#include "ast/base.hpp"

namespace AST
{

    class TypeSpecStatement : public Statement {
    protected: 
        TypeSpecStatement() = default;

    public:
        virtual ~TypeSpecStatement() = default;
        virtual void accept(Visitor *visitor) override = 0;
    };

    class TypeAliasStatement : public TypeSpecStatement
    {
    private:
        std::string id;
        Type *underlyingType;

    public:
        TypeAliasStatement(std::string id, Type *underlyingType);
        ~TypeAliasStatement();
        virtual void accept(Visitor *visitor) override;
    };

    class TypeDefinitionStatement : public TypeSpecStatement
    {
    private:
        std::string id;
        Type *underlyingType;

    public:
        TypeDefinitionStatement(std::string id, Type *underlyingType);
        ~TypeDefinitionStatement();
        virtual void accept(Visitor *visitor) override;
    };

    class VariableDeclarationStatement : public Statement 
    {
    private:
        std::vector<std::string> ids;
        Type *type;
        std::vector<Expression *> expressions;

    public:
        VariableDeclarationStatement(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions);
        ~VariableDeclarationStatement();
        virtual void accept(Visitor *visitor) override;
    };

};

#endif // GOINTERPRETER_AST_STATEMENTS_HPP