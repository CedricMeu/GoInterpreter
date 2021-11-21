#ifndef GOINTERPRETER_AST_BASE_HPP
#define GOINTERPRETER_AST_BASE_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "ast/visitor.hpp"

namespace AST { 

    /** 
     * Base class for ast nodes
     */
    class Node
    { 
    public:
        virtual ~Node() = default;
        virtual void accept(Visitor *visitor) const = 0;

    protected:
        Node() = default;
    };

    /**
     * Base class for type nodes
     */
    class Type : public Node 
    {
    public:
        virtual ~Type() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        Type() = default;
    };

    /**
     * Base class for expression nodes
     */
    class Expression : public Node 
    {
    public:
        virtual ~Expression() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        Expression() = default;
    };

    /**
     * Base class for expression nodes
     */
    class Statement : public Node 
    {
    public:
        virtual ~Statement() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        Statement() = default;
    };

    /**
     * Base class for expression nodes
     */
    class SimpleStatement : public Statement 
    {
    public:
        virtual ~SimpleStatement() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        SimpleStatement() = default;
    };

    /**
     * Base class for expression nodes
     */
    class TopLevelDeclaration : public Node 
    {
    public:
        virtual ~TopLevelDeclaration() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        TopLevelDeclaration() = default;
    };

    /**
     * Base class for expression nodes
     */
    class Declaration : public TopLevelDeclaration 
    {
    public:
        virtual ~Declaration() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        Declaration() = default;
    };

    /**
     * Class for blocks
     */
    class Block : public Node 
    {
    public:
        Block(std::vector<Statement *> statements);
        virtual ~Block();
        virtual void accept(Visitor *visitor) const override;

    protected:
        std::vector<Statement *> statements;
    };

    /**
     * Base class for a program
     */
    class Program : public Node 
    {
    public:
        Program(std::vector<TopLevelDeclaration *> declarations);
        virtual ~Program() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::vector<TopLevelDeclaration *> declarations;
    };
    
}; // namespace AST

#endif // GOINTERPRETER_AST_BASE_HPP