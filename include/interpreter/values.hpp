#ifndef GOINTERPRETER_INTERPRETER_VALUES_HPP
#define GOINTERPRETER_INTERPRETER_VALUES_HPP

#include <vector>
#include <map>
#include <functional> 

#include "interpreter/operations.hpp"
#include "utils/instanceof.hpp"

class Value
{
protected:
    Value() = default;

public:
    virtual Value *getValue();
    virtual ~Value() = default;
};

class BoolValue : public Value, public LogicalNot, public LogicalOr, public LogicalAnd, public Equal, public NotEqual
{
public:
    BoolValue(bool value);
    ~BoolValue() = default;
    bool getBool();

    Value *logicalNot() override;
    Value *logicalOr(Value *other) override;
    Value *logicalAnd(Value *other) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;

private:
    bool value;
};

class IntValue : public Value, public UnaryPlus, public Negate, public BitwiseNot, public Equal, public NotEqual, public LessThan, public GreaterThan, public LessThanEqual, public GreaterThanEqual, public ShiftLeft, public ShiftRight, public Add, public Subtract, public BitwiseOr, public BitwiseXOr, public BitwiseAnd, public Multiply, public Divide, public Modulo
{
public:
    IntValue(long value);
    ~IntValue() = default;
    long getInt();

    Value *unaryPlus() override;
    Value *negate() override;
    Value *bitwiseNot() override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;
    Value *lessThan(Value *other) override;
    Value *greaterThan(Value *other) override;
    Value *lessThanEqual(Value *other) override;
    Value *greaterThanEqual(Value *other) override;
    Value *shiftLeft(Value *other) override;
    Value *shiftRight(Value *other) override;
    Value *add(Value *other) override;
    Value *subtract(Value *other) override;
    Value *bitwiseOr(Value *other) override;
    Value *bitwiseXOr(Value *other) override;
    Value *bitwiseAnd(Value *other) override;
    Value *multiply(Value *other) override;
    Value *divide(Value *other) override;
    Value *modulo(Value *other) override;

private:
    long value;
};

class Float32Value : public Value, public UnaryPlus, public Negate, public Equal, public NotEqual, public LessThan, public GreaterThan, public LessThanEqual, public GreaterThanEqual, public Add, public Subtract, public Multiply, public Divide
{
public:
    Float32Value(float value);
    ~Float32Value() = default;
    float getFloat();

    Value *unaryPlus() override;
    Value *negate() override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;
    Value *lessThan(Value *other) override;
    Value *greaterThan(Value *other) override;
    Value *lessThanEqual(Value *other) override;
    Value *greaterThanEqual(Value *other) override;
    Value *add(Value *other) override;
    Value *subtract(Value *other) override;
    Value *multiply(Value *other) override;
    Value *divide(Value *other) override;

private:
    float value;
};

class RuneValue : public Value, public Equal, public NotEqual, public LessThan, public GreaterThan, public LessThanEqual, public GreaterThanEqual, public Add, public Subtract, public Multiply, public Divide
{
public:
    RuneValue(char value);
    ~RuneValue() = default;
    char getChar();

    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;
    Value *lessThan(Value *other) override;
    Value *greaterThan(Value *other) override;
    Value *lessThanEqual(Value *other) override;
    Value *greaterThanEqual(Value *other) override;
    Value *add(Value *other) override;
    Value *subtract(Value *other) override;
    Value *multiply(Value *other) override;
    Value *divide(Value *other) override;

private:
    char value;
};

class StringValue : public Value, public Index, public SimpleSlice, public FullSlice, public Equal, public NotEqual, public LessThan, public GreaterThan, public LessThanEqual, public GreaterThanEqual, public Add
{
public:
    typedef struct String { 
        char * value; 
        long size; 
    } String;

    StringValue(char *value, long size);
    ~StringValue();
    String getString();

    static long compare(StringValue *lhs, StringValue *rhs);

    Value *index(Value *index) override;
    void setIndex(Value *index, Value *newValue) override;
    Value *simpleSlice(Value *low, Value *high) override;
    Value *fullSlice(Value *low, Value *high, Value *max) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;
    Value *lessThan(Value *other) override;
    Value *greaterThan(Value *other) override;
    Value *lessThanEqual(Value *other) override;
    Value *greaterThanEqual(Value *other) override;
    Value *add(Value *other) override;

private:
    char *value;
    long size;
};

class ArrayValue : public Value, public Index, public SimpleSlice, public FullSlice, public Equal, public NotEqual
{
public:
    ArrayValue(std::vector<Value *> values);
    ~ArrayValue() = default;
    std::vector<Value *> getArray();

    Value *index(Value *index) override;
    void setIndex(Value *index, Value *newValue) override;
    Value *simpleSlice(Value *low, Value *high) override;
    Value *fullSlice(Value *low, Value *high, Value *max) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;

private:
    std::vector<Value *> values;
};

class SliceValue : public Value, public Index, public SimpleSlice, public FullSlice, public Equal, public NotEqual
{
public:
    SliceValue(std::vector<Value *> values);
    ~SliceValue() = default;
    std::vector<Value *> getSlice();

    Value *index(Value *index) override;
    void setIndex(Value *index, Value *newValue) override;
    Value *simpleSlice(Value *low, Value *high) override;
    Value *fullSlice(Value *low, Value *high, Value *max) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;

private:
    std::vector<Value *> values;
};

class StructValue : public Value, public Select, public Equal, public NotEqual
{
public:
    StructValue(std::map<std::string, Value *> fields);
    ~StructValue() = default;

    Value *select(std::string id) override;
    void setSelect(std::string id, Value *newValue) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;

private:
    std::map<std::string, Value *> fields;
};

// TODO:
// class PointerValue : public Value, public Dereference, public Equal, public NotEqual
// {
// public:
//     PointerValue() = default;
//     ~PointerValue() = default;

//     Value *dereference() override;
//     Value *equal(Value *other) override;
//     Value *notEqual(Value *other) override;

// private:
// };

class FunctionValue : public Value, public Call
{
public:
    FunctionValue(const std::map<std::string, Value *>& closure, const std::function<Value *(std::map<std::string, Value *> closure, std::vector<Value *> arguments)>& call);
    ~FunctionValue() = default;

    Value *call(std::vector<Value *> arguments) override;

private:
    const std::function<Value *(std::map<std::string, Value *> closure, std::vector<Value *> arguments)> _call;
    const std::map<std::string, Value *> _closure;
};

class MapValue : public Value, public Index
{
public:
    MapValue(std::vector<std::pair<Value *, Value *>> fields);
    ~MapValue() = default;

    Value *index(Value *index) override;
    void setIndex(Value *index, Value *newValue) override;

private:
    std::vector<std::pair<Value *, Value *>> fields;
};

class ReferenceValue : public Value, public Index, public Select, public SimpleSlice, public FullSlice, public Call, public UnaryPlus, public Negate, public LogicalNot, public BitwiseNot, public Dereference, public Reference, public LogicalOr, public LogicalAnd, public Equal, public NotEqual, public LessThan, public LessThanEqual, public GreaterThan, public GreaterThanEqual, public ShiftLeft, public ShiftRight, public Add, public Subtract, public BitwiseOr, public BitwiseXOr, public BitwiseAnd, public Multiply, public Divide, public Modulo
{
public:
    ReferenceValue(const std::function<Value* ()> getter, const std::function<void (Value *)> setter);
    ~ReferenceValue() = default;
    Value *getValue() override;
    void setValue(Value *value);

    Value *select(std::string id) override;
    void setSelect(std::string id, Value *newValue) override;
    Value *index(Value *index) override;
    void setIndex(Value *index, Value *newValue) override;
    Value *simpleSlice(Value *low, Value *high) override;
    Value *fullSlice(Value *low, Value *high, Value *max) override;
    Value *call(std::vector<Value *> parameters) override;
    Value *unaryPlus() override;
    Value *negate() override;
    Value *logicalNot() override;
    Value *bitwiseNot() override;
    Value *dereference() override;
    Value *reference() override;
    Value *logicalOr(Value *other) override;
    Value *logicalAnd(Value *other) override;
    Value *equal(Value *other) override;
    Value *notEqual(Value *other) override;
    Value *lessThan(Value *other) override;
    Value *greaterThan(Value *other) override;
    Value *lessThanEqual(Value *other) override;
    Value *greaterThanEqual(Value *other) override;
    Value *shiftLeft(Value *other) override;
    Value *shiftRight(Value *other) override;
    Value *add(Value *other) override;
    Value *subtract(Value *other) override;
    Value *bitwiseOr(Value *other) override;
    Value *bitwiseXOr(Value *other) override;
    Value *bitwiseAnd(Value *other) override;
    Value *multiply(Value *other) override;
    Value *divide(Value *other) override;
    Value *modulo(Value *other) override;

private:
    const std::function<Value* ()> getter; 
    const std::function<void (Value *)> setter;
};

#endif // GOINTERPRETER_INTERPRETER_VALUES_HPP
