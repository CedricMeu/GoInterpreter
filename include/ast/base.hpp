#ifndef GOINTERPRETER_AST_BASE_HPP
#define GOINTERPRETER_AST_BASE_HPP

#include <string>
#include <vector>
#include "ast/visitor.hpp"

namespace AST { 

    /** 
     * Base class for ast nodes
     */
    class Node
    { 
    protected:
        Node() = default;

    public:
        virtual ~Node() = default;
        virtual void accept(Visitor *visitor) = 0;
    };

    /**
     * Base class for type nodes
     */
    class Type : public Node {
    protected:
        Type() = default;

    public:
        virtual ~Type() = default;
        virtual void accept(Visitor *visitor) = 0;
    };

    /**
     * Base class for expression nodes
     */
    class Expression : public Node {
    protected:
        Expression() = default;
        
    public:
        virtual ~Expression() = default;
        virtual void accept(Visitor *visitor) = 0;
    };

    /**
     * Base class for expression nodes
     */
    class Statement : public Node {
    protected:
        Statement() = default;
        
    public:
        virtual ~Statement() = default;
        virtual void accept(Visitor *visitor) = 0;
    };

    /**
     * Class for blocks
     */
    class Block : public Node {
    protected:
        std::vector<Statement *> statements;
        
    public:
        Block(std::vector<Statement *> statements);
        virtual ~Block();
        virtual void accept(Visitor *visitor);
    };
    
}; // namespace AST

#endif // GOINTERPRETER_AST_BASE_HPP