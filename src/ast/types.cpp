#include "ast/types.hpp"

auto AST::BoolType::print() -> std::string 
{
    return "BoolType";
}

auto AST::IntType::print() -> std::string 
{
    return "IntType";
}

auto AST::Float32Type::print() -> std::string 
{
    return "Float32Type";
}

auto AST::RuneType::print() -> std::string 
{
    return "RuneType";
}

auto AST::StringType::print() -> std::string 
{
    return "StringType";
}

AST::ArrayType::ArrayType(long size, Type *type): type{type}, size{size} 
{}

AST::ArrayType::~ArrayType()
{
    delete this->type;
}

auto AST::ArrayType::print() -> std::string 
{
    return "ArrayType[" + std::to_string(this->size) + "]<" + this->type->print() + ">";
}

AST::SliceType::SliceType(Type *type): type{type}
{}

AST::SliceType::~SliceType()
{
    delete this->type;
}

auto AST::SliceType::print() -> std::string 
{
    return "SliceType[]<" + this->type->print() + ">";
}

AST::StructType::StructType(std::vector<std::pair<std::string, Type *>> fields): fields{fields}
{}

AST::StructType::~StructType()
{
    for (const auto pair : this->fields) {
        delete pair.second;
    }
}

auto AST::StructType::print() -> std::string
{
    std::string result = "struct<";

    for (const auto pair : this->fields) {
        result += pair.first + ":" + pair.second->print()+", ";
    }

    return result + ">";
}

AST::PointerType::PointerType(Type *type): type{type}
{}

AST::PointerType::~PointerType()
{
    delete this->type;
}

auto AST::PointerType::print() -> std::string 
{
    return "PointerType<" + this->type->print() + ">";
}

AST::FunctionType::FunctionType(
    std::vector<std::pair<std::string, Type *>> parameters, 
    std::vector<std::pair<std::string, Type *>> returns): parameters{parameters}, returns{returns}
{}

AST::FunctionType::~FunctionType()
{
    for (const auto ppair : this->parameters) {
        delete ppair.second;
    }

    for (const auto rpair : this->returns) {
        delete rpair.second;
    }
}

auto AST::FunctionType::print() -> std::string
{
    std::string result = "func<";

    for (const auto ppair : this->parameters) {
        result += ppair.first + ":" + ppair.second->print()+", ";
    }

    result += "-> ";

    for (const auto rpair : this->returns) {
        result += rpair.first + ":" + rpair.second->print()+", ";
    }

    return result + ">";
}

AST::MapType::MapType(Type *keyType, Type *elementType): keyType{keyType}, elementType{elementType}
{}

AST::MapType::~MapType()
{
    delete keyType;
    delete elementType;
}

auto AST::MapType::print() -> std::string
{
    return "MapType[<" + keyType->print() + ">]<" + elementType->print() + ">";
}

AST::CustomType::CustomType(const char *id): id{std::string{id}} 
{}

auto AST::CustomType::print() -> std::string 
{
    return "Custom(" + this->id + ")";
}