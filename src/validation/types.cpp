#include "validation/types.hpp"

bool Type::composable() const {
    return false;
}

bool BoolType::equals(const Type& other) const 
{
    return instanceof<BoolType>(&other);
}

std::string BoolType::toString() const
{
    return "Bool";
}

bool IntType::equals(const Type& other) const 
{
    return instanceof<IntType>(&other);
}

std::string IntType::toString() const
{
    return "Int";
}

bool Float32Type::equals(const Type& other) const 
{
    return instanceof<Float32Type>(&other);
}

std::string Float32Type::toString() const
{
    return "Float32";
}

bool RuneType::equals(const Type& other) const 
{
    return instanceof<RuneType>(&other);
}

std::string RuneType::toString() const
{
    return "Rune";
}

bool StringType::equals(const Type& other) const 
{
    return instanceof<StringType>(&other);
}

std::string StringType::toString() const
{
    return "String";
}

ArrayType::ArrayType(Type *type, long size) 
    : type{type}, size{size}
{}

ArrayType::~ArrayType()
{
    delete type;
}

bool ArrayType::equals(const Type& other) const
{
    if (!instanceof<ArrayType>(&other)) return false;

    const ArrayType& casted_other = (const ArrayType&) other;

    return this->type->equals(*casted_other.type) && this->size == casted_other.size;
}

std::string ArrayType::toString() const
{
    return "Array<" + this->type->toString() + ">[" + std::to_string(this->size) + "]";
}

bool ArrayType::composable() const 
{
    return true;
}

Type *ArrayType::elementType() const
{
    return type;
}

SliceType::SliceType(Type *type) 
    : type{type}
{}

SliceType::~SliceType()
{
    delete type;
}

bool SliceType::equals(const Type& other) const
{
    if (!instanceof<SliceType>(&other)) return false;

    const SliceType& casted_other = (const SliceType&) other;

    return this->type->equals(*casted_other.type);
}

std::string SliceType::toString() const
{
    return "Slice<" + this->type->toString() + ">";
}

bool SliceType::composable() const {
    return true;
}

Type *SliceType::elementType() const
{
    return type;
}

StructType::StructType(std::vector<std::pair<std::string, Type *>> fields)
    : fields{fields}
{}

StructType::~StructType()
{
    for (const auto field : fields)
    {
        delete field.second;
    }
}

bool StructType::equals(const Type& other) const
{
    if (!instanceof<StructType>(&other)) return false;

    const StructType& casted_other = (const StructType&) other;

    if (this->fields.size() != casted_other.fields.size()) {
        return false;
    }

    for (int i = 0; i < fields.size(); ++i) {
        if (this->fields[i].first != casted_other.fields[i].first
        || !this->fields[i].second->equals(*casted_other.fields[i].second)) {
            return false;
        }
    }

    return true;
}

std::string StructType::toString() const
{
    auto body = std::vector<std::string>{};

    for (const auto field : this->fields) {
        body.push_back(field.first + ":" + field.second->toString());
    }
    std::ostringstream res;
    std::copy(body.begin(), body.end(), std::ostream_iterator<std::string>(res, ", "));
    
    return "Struct{" + res.str() + "}";
}

bool StructType::composable() const {
    return true;
}

bool StructType::hasField(std::string field) const
{
    for (const auto _field : fields)
    {
        if (_field.first == field) return true;
    }

    return false;
}

Type *StructType::typeOfField(std::string field) const
{
    for (const auto _field : fields)
    {
        if (_field.first == field) return _field.second;
    }

    return nullptr;
}

PointerType::PointerType(Type *type) 
    : type{type}
{}

PointerType::~PointerType()
{
    delete type;
}

bool PointerType::equals(const Type& other) const
{
    if (!instanceof<PointerType>(&other)) return false;

    const PointerType& casted_other = (const PointerType&) other;

    return this->type->equals(*casted_other.type);
}

std::string PointerType::toString() const
{
    return this->type->toString() + "*";
}

Type *PointerType::underlyingType() const 
{
    return type;
}

FunctionType::FunctionType(
        std::vector<std::pair<std::string, Type *>> parameters,
        std::vector<std::pair<std::string, Type *>> returns)
    : parameters{parameters}, returns{returns}
{}

FunctionType::~FunctionType()
{
    for (const auto parameter : parameters) 
    {
        delete parameter.second;
    }

    for (const auto _return : returns) 
    {
        delete _return.second;
    }
}

std::vector<Type *> FunctionType::getParameterTypes() const
{
    std::vector<Type *> parameterTypes;

    std::transform(parameters.begin(), parameters.end(), std::inserter(parameterTypes, parameterTypes.end()), [](const std::pair<std::string, Type*>& pair) { return pair.second; });

    return parameterTypes;
}

std::vector<Type *> FunctionType::getReturnTypes() const
{
    std::vector<Type *> returnTypes;

    std::transform(returns.begin(), returns.end(), std::inserter(returnTypes, returnTypes.end()), [](const std::pair<std::string, Type*>& pair) { return pair.second; });
    
    return returnTypes;
}

std::vector<std::pair<std::string, Type *>> FunctionType::getParameters() const
{
    return parameters;
}

std::vector<std::pair<std::string, Type *>> FunctionType::getReturns() const
{
    return returns;
}

bool FunctionType::equals(const Type& other) const 
{
    if (!instanceof<FunctionType>(&other)) return false;

    const FunctionType& casted_other = (const FunctionType&) other;

    if (this->parameters.size() != casted_other.parameters.size()) {
        return false;
    }

    if (this->returns.size() != casted_other.returns.size()) {
        return false;
    }

    for (int i = 0; i < parameters.size(); ++i) {
        if (this->parameters[i].first != casted_other.parameters[i].first
        || !this->parameters[i].second->equals(*casted_other.parameters[i].second)) {
            return false;
        }
    }

    for (int i = 0; i < returns.size(); ++i) {
        if (this->returns[i].first != casted_other.returns[i].first
        || !this->returns[i].second->equals(*casted_other.returns[i].second)) {
            return false;
        }
    }

    return true;
}

std::string FunctionType::toString() const
{
    auto params = std::vector<std::string>{};
    auto rets = std::vector<std::string>{};

    for (const auto param : this->parameters) {
        params.push_back(param.first + ":" + param.second->toString());
    }

    for (const auto ret : this->returns) {
        rets.push_back(ret.first + ":" + ret.second->toString());
    }

    std::ostringstream res_params;
    std::copy(params.begin(), params.end(), std::ostream_iterator<std::string>(res_params, ", "));

    std::ostringstream res_rets;
    std::copy(rets.begin(), rets.end(), std::ostream_iterator<std::string>(res_rets, ", "));
    
    return "Function(" + res_params.str() + ") -> (" + res_rets.str() + ")";
}

MapType::MapType(Type *keyType, Type *elementType)
    : _keyType{keyType}, _elementType{elementType}
{}

MapType::~MapType() 
{
    delete _keyType;
    delete _elementType;
}

bool MapType::equals(const Type& other) const
{
    if (!instanceof<MapType>(&other)) return false;

    const MapType& casted_other = (const MapType&) other;

    return this->_keyType->equals(*casted_other._keyType) && this->_elementType->equals(*casted_other._elementType);
}

std::string MapType::toString() const
{
    return "Map<" + this->_keyType->toString() + ", " + this->_elementType->toString() + ">";
}

bool MapType::composable() const {
    return true;
}

Type *MapType::keyType() const
{
    return _keyType;
}

Type *MapType::elementType() const
{
    return _elementType;
}

int CustomType::idGen = 0;

CustomType::CustomType(Type *type)
    : type{type}, id{idGen++}
{}

CustomType::~CustomType()
{
    delete type;
}

bool CustomType::equals(const Type& other) const
{
    if (!instanceof<CustomType>(&other)) return false;

    const CustomType& casted_other = (const CustomType&) other;

    return this->type->equals(*casted_other.type) && this->id == casted_other.id;
}

Type *CustomType::underlyingType() const 
{
    if (instanceof<CustomType>(type)) {
        return dynamic_cast<CustomType *>(type)->underlyingType();
    } else {
        return type;
    }
}

std::string CustomType::toString() const
{
    return "Custom<" + this->type->toString() + ">";
}

bool CustomType::composable() const 
{
    return type->composable();
}

bool UnresolvedType::equals(const Type& other) const
{
    return false;
}

std::string UnresolvedType::toString() const
{
    return "!Unresolved!";
}