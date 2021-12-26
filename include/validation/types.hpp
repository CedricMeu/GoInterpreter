#ifndef GOINTERPRETER_VALIDATION_TYPES_HPP
#define GOINTERPRETER_VALIDATION_TYPES_HPP

#include <typeinfo>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>

#include "utils/instanceof.hpp"

class Type
{
public:
    virtual ~Type() = default;
    virtual bool equals(const Type& other) const = 0;
    virtual std::string toString() const = 0;
    virtual bool composable() const;

protected:
    Type() = default;

private:
};

class BoolType : public Type
{
public:
    BoolType() = default;
    virtual ~BoolType() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

class IntType : public Type
{
public:
    IntType() = default;
    virtual ~IntType() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

class Float32Type : public Type
{
public:
    Float32Type() = default;
    virtual ~Float32Type() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

class RuneType : public Type
{
public:
    RuneType() = default;
    virtual ~RuneType() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

class StringType : public Type
{
public:
    StringType() = default;
    virtual ~StringType() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

class ArrayType : public Type
{
public:
    ArrayType(Type *type, long size);
    virtual ~ArrayType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    virtual bool composable() const override;
    Type *elementType() const;

private:
    Type *type;
    long size;
};

class SliceType : public Type
{
public:
    SliceType(Type *type);
    virtual ~SliceType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    virtual bool composable() const override;
    Type *elementType() const;

private:
    Type *type;
};

class StructType : public Type
{
public:
    StructType(std::vector<std::pair<std::string, Type *>> fields);
    virtual ~StructType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    virtual bool composable() const override;

    bool hasField(std::string field) const;
    Type *typeOfField(std::string field) const;

private:
    std::vector<std::pair<std::string, Type *>> fields;
};

class PointerType : public Type
{
public:
    PointerType(Type *type);
    virtual ~PointerType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    Type *underlyingType() const;

private:
    Type *type;
};

class FunctionType : public Type
{
public:
    FunctionType(
        std::vector<std::pair<std::string, Type *>> parameters,
        std::vector<std::pair<std::string, Type *>> returns);
    virtual ~FunctionType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;

    std::vector<Type *> getParameterTypes() const;
    std::vector<Type *> getReturnTypes() const;

    std::vector<std::pair<std::string, Type *>> getParameters() const;
    std::vector<std::pair<std::string, Type *>> getReturns() const;

private:
    std::vector<std::pair<std::string, Type *>> parameters;
    std::vector<std::pair<std::string, Type *>> returns;
};

class MapType : public Type
{
public:
    MapType(Type *keyType, Type *elementType);
    virtual ~MapType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    virtual bool composable() const override;
    Type *keyType() const;
    Type *elementType() const;

private:
    Type *_keyType;
    Type *_elementType;
};

class CustomType : public Type
{
public:
    CustomType(Type *type);
    virtual ~CustomType() override;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
    virtual bool composable() const override;
    Type *underlyingType() const;

private:
    static int idGen;
    int id;
    Type *type;
};

class UnresolvedType : public Type
{
public:
    UnresolvedType() = default;
    virtual ~UnresolvedType() override = default;
    virtual bool equals(const Type& other) const override;
    virtual std::string toString() const override;
};

#endif // GOINTERPRETER_VALIDATION_TYPES_HPP
