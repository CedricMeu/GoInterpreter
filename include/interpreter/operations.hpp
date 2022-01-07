#ifndef GOINTERPRETER_INTERPRETER_OPERATIONS_HPP
#define GOINTERPRETER_INTERPRETER_OPERATIONS_HPP

#include <string>
#include <vector>

class Value; // need to hoist this

class Select
{
public:
    virtual Value *select(std::string id) = 0;
    virtual void setSelect(std::string id, Value *newValue) = 0;
};

class Index
{
public:
    virtual Value *index(Value *index) = 0;
    virtual void setIndex(Value *index, Value *newValue) = 0;
};

class SimpleSlice
{
public:
    // `low` and `high` might be nullpointers
    virtual Value *simpleSlice(Value *low, Value *high) = 0;
};

class FullSlice
{
public:
    // `low` might be nullpointer
    virtual Value *fullSlice(Value *low, Value *high, Value *max) = 0;
};

class Call
{
public:
    virtual Value *call(std::vector<Value *> arguments) = 0;
};

class UnaryPlus
{
public:
    virtual Value *unaryPlus() = 0;
};

class Negate
{
public:
    virtual Value *negate() = 0;
};

class LogicalNot
{
public:
    virtual Value *logicalNot() = 0;
};

class BitwiseNot
{
public:
    virtual Value *bitwiseNot() = 0;
};

class Dereference
{
public:
    virtual Value *dereference() = 0;
};

class Reference
{
public:
    virtual Value *reference() = 0;
};

class LogicalOr
{
public:
    virtual Value *logicalOr(Value *other) = 0;
};

class LogicalAnd
{
public:
    virtual Value *logicalAnd(Value *other) = 0;
};

class Equal
{
public:
    virtual Value *equal(Value *other) = 0;
};

class NotEqual
{
public:
    virtual Value *notEqual(Value *other) = 0;
};

class LessThan
{
public:
    virtual Value *lessThan(Value *other) = 0;
};

class LessThanEqual
{
public:
    virtual Value *lessThanEqual(Value *other) = 0;
};

class GreaterThan
{
public:
    virtual Value *greaterThan(Value *other) = 0;
};

class GreaterThanEqual
{
public:
    virtual Value *greaterThanEqual(Value *other) = 0;
};

class ShiftLeft
{
public:
    virtual Value *shiftLeft(Value *other) = 0;
};

class ShiftRight
{
public:
    virtual Value *shiftRight(Value *other) = 0;
};

class Add
{
public:
    virtual Value *add(Value *other) = 0;
};

class Subtract
{
public:
    virtual Value *subtract(Value *other) = 0;
};

class BitwiseOr
{
public:
    virtual Value *bitwiseOr(Value *other) = 0;
};

class BitwiseXOr
{
public:
    virtual Value *bitwiseXOr(Value *other) = 0;
};

class BitwiseAnd
{
public:
    virtual Value *bitwiseAnd(Value *other) = 0;
};

class Multiply
{
public:
    virtual Value *multiply(Value *other) = 0;
};

class Divide
{
public:
    virtual Value *divide(Value *other) = 0;
};

class Modulo
{
public:
    virtual Value *modulo(Value *other) = 0;
};


#endif // GOINTERPRETER_INTERPRETER_OPERATIONS_HPP