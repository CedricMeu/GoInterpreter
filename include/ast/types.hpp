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
        virtual ~BoolType() override = default;
        virtual void accept(Visitor *visitor) override;
    };

    class IntType : public Type
    {
    public:
        IntType() = default;
        virtual ~IntType() override = default;
        virtual void accept(Visitor *visitor) override;
    };

    class Float32Type : public Type
    {
    public:
        Float32Type() = default;
        virtual ~Float32Type() override= default;
        virtual void accept(Visitor *visitor) override;
    };

    class RuneType : public Type
    {
    public:
        RuneType() = default;
        virtual ~RuneType() override= default;
        virtual void accept(Visitor *visitor) override;
    };

    class StringType : public Type
    {
    public:
        StringType() = default;
        virtual ~StringType() override= default;
        virtual void accept(Visitor *visitor) override;
    };

    class ArrayType : public Type
    {
    public:
        ArrayType(long size, Type *type);
        virtual ~ArrayType() override;
        virtual void accept(Visitor *visitor) override;

    private:
        Type *type;
        const long size;
    };

    class SliceType : public Type
    {
    public:
        SliceType(Type *type);
        virtual ~SliceType() override;
        virtual void accept(Visitor *visitor) override;

    private:
        Type *type;
    };
    
    class StructType : public Type
    {
    public:
        explicit StructType(std::vector<std::pair<std::string, Type *>> fields);
        virtual ~StructType() override;
        virtual void accept(Visitor *visitor) override;

    private:
        std::vector<std::pair<std::string, Type *>> fields;
    };
    
    class PointerType : public Type
    {
    public:
        explicit PointerType(Type *type);
        virtual ~PointerType() override;
        virtual void accept(Visitor *visitor) override;

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
        virtual void accept(Visitor *visitor) override;

    private:
        std::vector<std::pair<std::string, Type *>> parameters;
        std::vector<std::pair<std::string, Type *>> returns;
    };
    
    class MapType : public Type
    {
    public:
        MapType(Type* keyType, Type* elementType);
        virtual ~MapType() override;
        virtual void accept(Visitor *visitor) override;

    private:
        Type *keyType;
        Type *elementType;
    };
    
    class CustomType : public Type
    {
    public:
        explicit CustomType(const char *id);
        virtual ~CustomType() override= default;
        virtual void accept(Visitor *visitor) override;

    private:
        const std::string id;
    };

}; // namespace AST

#endif // GOINTERPRETER_AST_TYPES_HPP