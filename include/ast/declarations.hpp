#ifndef GOINTERPRETER_AST_DECLARATIONS_HPP
#define GOINTERPRETER_AST_DECLARATIONS_HPP

#include <string>
#include <vector>
#include "ast/base.hpp"

namespace AST {

    class FunctionDeclaration : public TopLevelDeclaration 
    {
    public:
        FunctionDeclaration(std::string id, Type *signature, Block *body);
        virtual ~FunctionDeclaration() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::string id;
        Type *signature;
        Block *body;
    };

    class TypeSpecDeclaration : public Declaration 
    {
    public:
        virtual ~TypeSpecDeclaration() override = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected: 
        TypeSpecDeclaration() = default;
    };

    class TypeAliasDeclaration : public TypeSpecDeclaration
    {
    public:
        TypeAliasDeclaration(std::string id, Type *underlyingType);
        virtual ~TypeAliasDeclaration() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::string id;
        Type *underlyingType;
    };

    class TypeDefinitionDeclaration : public TypeSpecDeclaration
    {
    public:
        TypeDefinitionDeclaration(std::string id, Type *underlyingType);
        virtual ~TypeDefinitionDeclaration() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::string id;
        Type *underlyingType;
    };

    class VariableDeclaration : public Declaration 
    {
    public:
        VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions);
        virtual ~VariableDeclaration() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::vector<std::string> ids;
        Type *type;
        std::vector<Expression *> expressions;
    };

}; // namespace AST

#endif // GOINTERPRETER_AST_DECLARATIONS_HPP