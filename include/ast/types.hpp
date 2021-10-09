#ifndef GOINTERPRETER_AST_TYPES_HPP
#define GOINTERPRETER_AST_TYPES_HPP

#include <string>
#include <map>
#include <vector>
#include "ast/base.hpp"

namespace AST {

    class BoolType : public Type
    {
    public:
        BoolType() = default;
        virtual ~BoolType() = default;
        virtual auto print() -> std::string;
    };

    class UIntType : public Type
    {
    public:
        UIntType() = default;
        virtual ~UIntType() = default;
        virtual auto print() -> std::string;
    };

    class IntType : public Type
    {
    public:
        IntType() = default;
        virtual ~IntType() = default;
        virtual auto print() -> std::string;
    };

    class Float32Type : public Type
    {
    public:
        Float32Type() = default;
        virtual ~Float32Type() = default;
        virtual auto print() -> std::string;
    };

    class Float64Type : public Type
    {
    public:
        Float64Type() = default;
        virtual ~Float64Type() = default;
        virtual auto print() -> std::string;
    };

    class Complex64Type : public Type
    {
    public:
        Complex64Type() = default;
        virtual ~Complex64Type() = default;
        virtual auto print() -> std::string;
    };

    class ByteType : public Type
    {
    public:
        ByteType() = default;
        virtual ~ByteType() = default;
        virtual auto print() -> std::string;
    };

    class RuneType : public Type
    {
    public:
        RuneType() = default;
        virtual ~RuneType() = default;
        virtual auto print() -> std::string;
    };

    class StringType : public Type
    {
    public:
        StringType() = default;
        virtual ~StringType() = default;
        virtual auto print() -> std::string;
    };

    class ArrayType : public Type
    {
    private:
        Type *type;
        const long size;
    public:
        ArrayType(long size, Type *type);
        virtual ~ArrayType();
        virtual auto print() -> std::string;
    };

    class SliceType : public Type
    {
    private:
        Type *type;
    public:
        SliceType(Type *type);
        virtual ~SliceType();
        virtual auto print() -> std::string;
    };
    
    class StructType : public Type
    {
    private:
        std::vector<std::pair<std::string, Type *>> fields;

    public:
        explicit StructType(std::vector<std::pair<std::string, Type *>> fields);
        virtual ~StructType();
        virtual auto print() -> std::string;
    };
    
    class PointerType : public Type
    {
    private:
        Type *type;

    public:
        explicit PointerType(Type *type);
        virtual ~PointerType();
        virtual auto print() -> std::string;
    };
    
    class FunctionType : public Type
    {
    private:
        std::vector<std::pair<std::string, Type *>> parameters;
        std::vector<std::pair<std::string, Type *>> returns;

    public:
        FunctionType(
            std::vector<std::pair<std::string, Type *>> parameters, 
            std::vector<std::pair<std::string, Type *>> returns);
        virtual ~FunctionType();
        virtual auto print() -> std::string;
    };
    
    class MapType : public Type
    {
    private:
        Type *keyType;
        Type *elementType;

    public:
        MapType(Type* keyType, Type* elementType);
        virtual ~MapType();
        virtual auto print() -> std::string;
    };
    
    class CustomType : public Type
    {
    private:
        const std::string id;

    public:
        explicit CustomType(const char *id);
        virtual ~CustomType() = default;
        virtual auto print() -> std::string;
    };

} // namespace AST

#endif // GOINTERPRETER_AST_TYPES_HPP