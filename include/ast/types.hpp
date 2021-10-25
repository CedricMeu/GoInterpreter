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
        virtual void accept(Visitor *visitor) override;
    };

    class IntType : public Type
    {
    public:
        IntType() = default;
        virtual ~IntType() = default;
        virtual void accept(Visitor *visitor) override;
    };

    class Float32Type : public Type
    {
    public:
        Float32Type() = default;
        virtual ~Float32Type() = default;
        virtual void accept(Visitor *visitor) override;
    };

    class RuneType : public Type
    {
    public:
        RuneType() = default;
        virtual ~RuneType() = default;
        virtual void accept(Visitor *visitor) override;
    };

    class StringType : public Type
    {
    public:
        StringType() = default;
        virtual ~StringType() = default;
        virtual void accept(Visitor *visitor) override;
    };

    class ArrayType : public Type
    {
    private:
        Type *type;
        const long size;
    public:
        ArrayType(long size, Type *type);
        virtual ~ArrayType();
        virtual void accept(Visitor *visitor) override;
    };

    class SliceType : public Type
    {
    private:
        Type *type;
    public:
        SliceType(Type *type);
        virtual ~SliceType();
        virtual void accept(Visitor *visitor) override;
    };
    
    class StructType : public Type
    {
    private:
        std::vector<std::pair<std::string, Type *>> fields;

    public:
        explicit StructType(std::vector<std::pair<std::string, Type *>> fields);
        virtual ~StructType();
        virtual void accept(Visitor *visitor) override;
    };
    
    class PointerType : public Type
    {
    private:
        Type *type;

    public:
        explicit PointerType(Type *type);
        virtual ~PointerType();
        virtual void accept(Visitor *visitor) override;
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
        virtual void accept(Visitor *visitor) override;
    };
    
    class MapType : public Type
    {
    private:
        Type *keyType;
        Type *elementType;

    public:
        MapType(Type* keyType, Type* elementType);
        virtual ~MapType();
        virtual void accept(Visitor *visitor) override;
    };
    
    class CustomType : public Type
    {
    private:
        const std::string id;

    public:
        explicit CustomType(const char *id);
        virtual ~CustomType() = default;
        virtual void accept(Visitor *visitor) override;
    };

}; // namespace AST

#endif // GOINTERPRETER_AST_TYPES_HPP