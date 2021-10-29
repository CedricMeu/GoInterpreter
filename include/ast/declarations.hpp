#ifndef GOINTERPRETER_AST_DECLARATIONS_HPP
#define GOINTERPRETER_AST_DECLARATIONS_HPP

#include <string>
#include <vector>
#include "ast/base.hpp"

namespace AST {

    class FunctionDeclaration : public TopLevelDeclaration 
    {
    private:
        std::string id;
        Type *signature;
        Block *body;
    public:
        FunctionDeclaration(std::string id, Type *signature, Block *body);
        ~FunctionDeclaration();
        virtual void accept(Visitor *visitor) override;
    };

    class TypeSpecDeclaration : public Declaration 
    {
    protected: 
        TypeSpecDeclaration() = default;

    public:
        virtual ~TypeSpecDeclaration() = default;
        virtual void accept(Visitor *visitor) override = 0;
    };

    class TypeAliasDeclaration : public TypeSpecDeclaration
    {
    private:
        std::string id;
        Type *underlyingType;

    public:
        TypeAliasDeclaration(std::string id, Type *underlyingType);
        ~TypeAliasDeclaration();
        virtual void accept(Visitor *visitor) override;
    };

    class TypeDefinitionDeclaration : public TypeSpecDeclaration
    {
    private:
        std::string id;
        Type *underlyingType;

    public:
        TypeDefinitionDeclaration(std::string id, Type *underlyingType);
        ~TypeDefinitionDeclaration();
        virtual void accept(Visitor *visitor) override;
    };

    class VariableDeclaration : public Declaration 
    {
    private:
        std::vector<std::string> ids;
        Type *type;
        std::vector<Expression *> expressions;

    public:
        VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions);
        ~VariableDeclaration();
        virtual void accept(Visitor *visitor) override;
    };

}; // namespace AST

#endif // GOINTERPRETER_AST_DECLARATIONS_HPP