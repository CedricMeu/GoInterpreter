#ifndef GOINTERPRETER_AST_BASE_HPP
#define GOINTERPRETER_AST_BASE_HPP

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
        virtual auto print() -> std::string = 0;
    };

    /**
     * Base class for type nodes
     */
    class Type : public Node {
    protected:
        Type() = default;

    public:
        virtual ~Type() = default;
        virtual auto print() -> std::string = 0;
    };
    
} // namespace AST

#endif // GOINTERPRETER_AST_BASE_HPP