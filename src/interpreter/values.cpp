#include "interpreter/values.hpp"

Value *Value::getValue()
{
    return this;
}

BoolValue::BoolValue(bool value)
    : value{value}
{}

bool BoolValue::getBool()
{
    return value;
}

Value *BoolValue::logicalNot()
{
    return new BoolValue{!value};
}

Value *BoolValue::logicalOr(Value *other)
{
    return new BoolValue{value || dynamic_cast<BoolValue *>(other->getValue())->value};
}

Value *BoolValue::logicalAnd(Value *other)
{
    return new BoolValue{value && dynamic_cast<BoolValue *>(other->getValue())->value};
}

Value *BoolValue::equal(Value *other)
{
    return new BoolValue{value == dynamic_cast<BoolValue *>(other->getValue())->value};
}

Value *BoolValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<BoolValue *>(other->getValue())->value};
}

IntValue::IntValue(long value)
    : value{value}
{}

long IntValue::getInt()
{
    return value;
}

Value *IntValue::unaryPlus()
{
    return new IntValue{value};
}

Value *IntValue::negate()
{
    return new IntValue{-value};
}

Value *IntValue::bitwiseNot()
{
    return new IntValue{~value};
}

Value *IntValue::equal(Value *other)
{
    return new BoolValue{value == dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::shiftLeft(Value *other)
{
    return new IntValue{value << dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::shiftRight(Value *other)
{
    return new IntValue{value >> dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::add(Value *other)
{
    return new IntValue{value + dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::subtract(Value *other)
{
    return new IntValue{value - dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::bitwiseOr(Value *other)
{
    return new IntValue{value | dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::bitwiseXOr(Value *other)
{
    return new IntValue{value ^ dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::bitwiseAnd(Value *other)
{
    return new IntValue{value & dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::multiply(Value *other)
{
    return new IntValue{value * dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::divide(Value *other)
{
    return new IntValue{value / dynamic_cast<IntValue *>(other->getValue())->value};
}

Value *IntValue::modulo(Value *other)
{
    return new IntValue{value % dynamic_cast<IntValue *>(other->getValue())->value};
}

Float32Value::Float32Value(float value)
    : value{value}
{}

float Float32Value::getFloat()
{
    return value;
}

Value *Float32Value::unaryPlus()
{
    return new Float32Value{value};
}

Value *Float32Value::negate()
{
    return new Float32Value{-value};
}

Value *Float32Value::equal(Value *other)
{
    return new BoolValue{value == dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::add(Value *other)
{
    return new Float32Value{value + dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::subtract(Value *other)
{
    return new Float32Value{value - dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::multiply(Value *other)
{
    return new Float32Value{value * dynamic_cast<Float32Value *>(other->getValue())->value};
}

Value *Float32Value::divide(Value *other)
{
    return new Float32Value{value / dynamic_cast<Float32Value *>(other->getValue())->value};
}

RuneValue::RuneValue(char value)
    : value{value}
{}

char RuneValue::getChar()
{
    return value;
}

Value *RuneValue::equal(Value *other)
{
    return new BoolValue{value == dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<RuneValue *>(other->getValue())->value};
}

Value *RuneValue::add(Value *other)
{
    return new RuneValue{static_cast<char>( value + dynamic_cast<RuneValue *>(other->getValue())->value)};
}

Value *RuneValue::subtract(Value *other)
{
    return new RuneValue{static_cast<char>( value - dynamic_cast<RuneValue *>(other->getValue())->value)};
}

Value *RuneValue::multiply(Value *other)
{
    return new RuneValue{static_cast<char>( value * dynamic_cast<RuneValue *>(other->getValue())->value)};
}

Value *RuneValue::divide(Value *other)
{
    return new RuneValue{static_cast<char>( value / dynamic_cast<RuneValue *>(other->getValue())->value)};
}

StringValue::StringValue(char *value, long size)
    : value{value}, size{size}
{
    this->value = new char[size];

    for (int i = 0; i < size; ++i) {
        this->value[i] = value[i];
    }
}

StringValue::~StringValue()
{
    delete value;
}

StringValue::String StringValue::getString()
{
    return {value, size};
}

long StringValue::compare(StringValue *lhs, StringValue *rhs)
{

    for (int i = 0; i < lhs->size && i < rhs->size; ++i) {
        if (lhs->value[i] < rhs->value[i]) {
            return -1;
        } else if (lhs->value[i] > rhs->value[i]) {
            return 1;
        }
    }

    if (lhs->size < rhs->size) {
        return -1;
    } else if (lhs->size > rhs->size) {
        return 1;
    } else {
        return 0;
    }
}

Value *StringValue::index(Value *index)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= size) {
        throw std::runtime_error("Index out of bounds");
    }

    return new RuneValue{value[indexValue]};
}

void StringValue::setIndex(Value *index, Value *newValue)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= size) {
        throw std::runtime_error("Index out of bounds");
    }

    value[indexValue] = dynamic_cast<RuneValue *>(newValue->getValue())->getChar();
}

Value *StringValue::simpleSlice(Value *low, Value *high)
{
    // TODO: out of range
    auto lowValue = 0;
    auto newSize = size;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    if (high != nullptr) {
        newSize = dynamic_cast<IntValue *>(high->getValue())->getInt() - lowValue;
    }

    auto newValue = new char[newSize];
    
    for (int i = 0; i < newSize; ++i) {
        newValue[i] = value[i + lowValue];
    }

    return new StringValue{newValue, newSize};
}

Value *StringValue::fullSlice(Value *low, Value *high, Value *max)
{
    // TODO: out of range
    auto lowValue = 0;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    auto highSize = dynamic_cast<IntValue *>(high->getValue())->getInt() - lowValue;
    auto maxSize = dynamic_cast<IntValue *>(max->getValue())->getInt();

    auto newSize = highSize < maxSize ? highSize : maxSize;

    auto newValue = new char[newSize];
    
    for (int i = 0; i < newSize; ++i) {
        newValue[i] = value[i + lowValue];
    }

    return new StringValue{newValue, newSize};
}



Value *StringValue::equal(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) == 0};
}

Value *StringValue::notEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) != 0};
}

Value *StringValue::lessThan(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) < 0};
}

Value *StringValue::greaterThan(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) > 0};
}

Value *StringValue::lessThanEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) <= 0};
}

Value *StringValue::greaterThanEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    return new BoolValue{compare(this, otherString) >= 0};
}

Value *StringValue::add(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other->getValue());
    auto newValue = new char[this->size + otherString->size + 1];

    for (int i = 0; i < this->size; ++i) {
        newValue[i] = this->value[i];
    }

    for (int j = 0; j < otherString->size; ++j) {
        newValue[this->size + j] = otherString->value[j];
    }

    newValue[this->size + otherString->size] = '\0';

    return new StringValue{newValue, this->size + otherString->size};
}

ArrayValue::ArrayValue(std::vector<Value *> values)
    :   values{std::move(values)}
{}

std::vector<Value *> ArrayValue::getArray()
{
    return values;
}

Value *ArrayValue::index(Value *index)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= values.size()) {
        throw std::runtime_error("Index out of bounds");
    }

    return values[indexValue];
}

void ArrayValue::setIndex(Value *index, Value *newValue)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= values.size()) {
        throw std::runtime_error("Index out of bounds");
    }

    values[indexValue] = newValue->getValue();
}

Value *ArrayValue::simpleSlice(Value *low, Value *high)
{
    long lowValue = 0;
    long highValue = values.size();

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    if (high != nullptr) {
        highValue = dynamic_cast<IntValue *>(high->getValue())->getInt();
    }

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue; ++i) {
        newArray.push_back(values[i]->getValue());
    }

    return new SliceValue{newArray};
}

Value *ArrayValue::fullSlice(Value *low, Value *high, Value *max)
{
    long lowValue = 0;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    long highValue = dynamic_cast<IntValue *>(high->getValue())->getInt();
    long maxValue = dynamic_cast<IntValue *>(max->getValue())->getInt();

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue && i-lowValue < maxValue; ++i) {
        newArray.push_back(values[i]->getValue());
    }

    return new SliceValue{newArray};
}

Value *ArrayValue::equal(Value *other)
{
    auto otherArray = dynamic_cast<ArrayValue *>(other->getValue());

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{false};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i]->getValue())->equal(otherArray->values[i]->getValue()))->getBool()) {
            return new BoolValue{false};
        }
    }

    return new BoolValue{true};
}

Value *ArrayValue::notEqual(Value *other)
{
    auto otherArray = dynamic_cast<ArrayValue *>(other->getValue());

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{true};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i]->getValue())->equal(otherArray->values[i]->getValue()))->getBool()) {
            return new BoolValue{true};
        }
    }

    return new BoolValue{false};
}

SliceValue::SliceValue(std::vector<Value *> values)
    : values{std::move(values)}
{}

std::vector<Value *> SliceValue::getSlice()
{
    return values;
}

Value *SliceValue::index(Value *index)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= values.size()) {
        throw std::runtime_error("Index out of bounds");
    }

    return values[indexValue];
}

void SliceValue::setIndex(Value *index, Value *newValue)
{
    auto indexValue = dynamic_cast<IntValue *>(index->getValue())->getInt();

    if (indexValue >= values.size()) {
        throw std::runtime_error("Index out of bounds");
    }

    values[indexValue] = newValue;
}

Value *SliceValue::simpleSlice(Value *low, Value *high)
{
    long lowValue = 0;
    long highValue = values.size();

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    if (high != nullptr) {
        highValue = dynamic_cast<IntValue *>(high->getValue())->getInt();
    }

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue; ++i) {
        newArray.push_back(values[i]->getValue());
    }

    return new SliceValue{newArray};
}

Value *SliceValue::fullSlice(Value *low, Value *high, Value *max)
{
    long lowValue = 0;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low->getValue())->getInt();
    }

    long highValue = dynamic_cast<IntValue *>(high->getValue())->getInt();
    long maxValue = dynamic_cast<IntValue *>(max->getValue())->getInt();

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue && i-lowValue < maxValue; ++i) {
        newArray.push_back(values[i]->getValue());
    }

    return new SliceValue{newArray};
}

Value *SliceValue::equal(Value *other)
{
    auto otherArray = dynamic_cast<SliceValue *>(other->getValue());

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{false};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i]->getValue())->equal(otherArray->values[i]->getValue()))->getBool()) {
            return new BoolValue{false};
        }
    }

    return new BoolValue{true};
}

Value *SliceValue::notEqual(Value *other)
{
    auto otherArray = dynamic_cast<SliceValue *>(other->getValue());

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{true};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i]->getValue())->equal(otherArray->values[i]->getValue()))->getBool()) {
            return new BoolValue{true};
        }
    }

    return new BoolValue{false};
}

StructValue::StructValue(std::map<std::string, Value *> fields)
    : fields{fields}
{}

Value *StructValue::select(std::string id)
{
    return fields[id];
}

void StructValue::setSelect(std::string id, Value *newValue)
{
    fields[id] = newValue->getValue();
}

Value *StructValue::equal(Value *other)
{
    auto otherStruct = dynamic_cast<StructValue *>(other->getValue());

    std::vector<std::string> thisKeys{};
    std::vector<std::string> otherKeys{};

    std::vector<Value *> thisValues{};
    std::vector<Value *> otherValues{};

    for (const auto thisPair : fields) {
        thisKeys.push_back(thisPair.first);
        thisValues.push_back(thisPair.second);
    }

    for (const auto otherPair : otherStruct->fields) {
        thisKeys.push_back(otherPair.first);
        thisValues.push_back(otherPair.second);
    }

    return new BoolValue{std::equal(thisKeys.begin(), thisKeys.end(), otherKeys.begin()) && std::equal(thisValues.begin(), thisValues.end(), otherValues.begin(), [](Value *first, Value *second) {
        return dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(first->getValue())->equal(second->getValue()))->getBool();
    })};
}

Value *StructValue::notEqual(Value *other)
{
    auto otherStruct = dynamic_cast<StructValue *>(other->getValue());

    std::vector<std::string> thisKeys{};
    std::vector<std::string> otherKeys{};

    std::vector<Value *> thisValues{};
    std::vector<Value *> otherValues{};

    for (const auto thisPair : fields) {
        thisKeys.push_back(thisPair.first);
        thisValues.push_back(thisPair.second);
    }

    for (const auto otherPair : otherStruct->fields) {
        thisKeys.push_back(otherPair.first);
        thisValues.push_back(otherPair.second);
    }

    return new BoolValue{!std::equal(thisKeys.begin(), thisKeys.end(), otherKeys.begin()) && std::equal(thisValues.begin(), thisValues.end(), otherValues.begin(), [](Value *first, Value *second) {
        return dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(first->getValue())->equal(second->getValue()))->getBool();
    })};
}

FunctionValue::FunctionValue(const std::map<std::string, Value *>& closure, const std::function<Value *(std::map<std::string, Value *> closure, std::vector<Value *> arguments)>& call)
    : _closure{std::move(closure)}, _call{std::move(call)}
{}

Value *FunctionValue::call(std::vector<Value *> arguments) 
{
    return _call(_closure, arguments);
}

MapValue::MapValue(std::vector<std::pair<Value *, Value *>> fields)
    : fields{std::move(fields)}
{}

Value *MapValue::index(Value *index) 
{
    for (const auto& field : fields) {
        auto fieldIndex = dynamic_cast<Equal *>(field.first);

        if (dynamic_cast<BoolValue *>(fieldIndex->equal(index->getValue()))->getBool()) {
            return field.second;
        }
    }
    
    throw std::runtime_error("Index out of bounds");
}

void MapValue::setIndex(Value *index, Value *newValue)
{
    for (int i = 0; i < fields.size(); ++i) {
        auto fieldIndex = dynamic_cast<Equal *>(fields[i].first);

        if (dynamic_cast<BoolValue *>(fieldIndex->equal(index->getValue()))->getBool()) {
            fields[i] = std::make_pair(fields[i].first, newValue->getValue());
        }
    }

    throw std::runtime_error("Index out of bounds");
}

ReferenceValue::ReferenceValue(const std::function<Value* ()> getter, const std::function<void (Value *)> setter)
    : getter{getter}, setter{setter}
{}

Value *ReferenceValue::getValue()
{
    return getter();
}

void ReferenceValue::setValue(Value *value)
{
    setter(value);
}

Value *ReferenceValue::index(Value *index)
{
    return new ReferenceValue{
        [this, index]() {
            auto value = dynamic_cast<Index *>(this->getValue());
            return value->index(index->getValue());
        },
        [this, index](Value *newValue) {
            auto value = dynamic_cast<Index *>(this->getValue());

            value->setIndex(index->getValue(), newValue->getValue());

            setValue(dynamic_cast<Value *>(value));
        }
    };
}

void ReferenceValue::setIndex(Value *index, Value *newValue)
{
    // TODO:
    throw std::exception{};
}

Value *ReferenceValue::select(std::string id)
{
    return new ReferenceValue{
        [this, id]() {
            auto value = dynamic_cast<Select *>(this->getValue());
            return value->select(id);
        },
        [this, id](Value * newValue) {
            auto value = dynamic_cast<Select *>(this->getValue());

            value->setSelect(id, newValue->getValue());

            setValue(dynamic_cast<Value *>(value));
        }
    };
}

void ReferenceValue::setSelect(std::string id, Value *newValue)
{
    // TODO:
    throw std::exception{};
}

Value *ReferenceValue::simpleSlice(Value *low, Value *high)
{
    auto value = dynamic_cast<SimpleSlice *>(this->getValue());
    return value->simpleSlice(low->getValue(), high->getValue());
}

Value *ReferenceValue::fullSlice(Value *low, Value *high, Value *max)
{
    auto value = dynamic_cast<FullSlice *>(this->getValue());
    return value->fullSlice(low->getValue(), high->getValue(), max->getValue());
}

Value *ReferenceValue::call(std::vector<Value *> parameters)
{
    auto value = dynamic_cast<Call *>(this->getValue());
    return value->call(parameters);
}

Value *ReferenceValue::unaryPlus()
{
    auto value = dynamic_cast<UnaryPlus *>(this->getValue());
    return value->unaryPlus();
}

Value *ReferenceValue::negate()
{
    auto value = dynamic_cast<Negate *>(this->getValue());
    return value->negate();
}

Value *ReferenceValue::logicalNot()
{
    auto value = dynamic_cast<LogicalNot *>(this->getValue());
    return value->logicalNot();
}

Value *ReferenceValue::bitwiseNot()
{
    auto value = dynamic_cast<BitwiseNot *>(this->getValue());
    return value->bitwiseNot();
}

Value *ReferenceValue::dereference()
{
    auto value = dynamic_cast<Dereference *>(this->getValue());
    return value->dereference();
}

Value *ReferenceValue::reference()
{
    auto value = dynamic_cast<Reference *>(this->getValue());
    return value->reference();
}

Value *ReferenceValue::logicalOr(Value *other)
{
    auto value = dynamic_cast<LogicalOr *>(this->getValue());
    return value->logicalOr(other->getValue());
}

Value *ReferenceValue::logicalAnd(Value *other)
{
    auto value = dynamic_cast<LogicalAnd *>(this->getValue());
    return value->logicalAnd(other->getValue());
}

Value *ReferenceValue::equal(Value *other)
{
    auto value = dynamic_cast<Equal *>(this->getValue());
    return value->equal(other->getValue());
}

Value *ReferenceValue::notEqual(Value *other)
{
    auto value = dynamic_cast<NotEqual *>(this->getValue());
    return value->notEqual(other->getValue());
}

Value *ReferenceValue::lessThan(Value *other)
{
    auto value = dynamic_cast<LessThan *>(this->getValue());
    return value->lessThan(other->getValue());
}

Value *ReferenceValue::greaterThan(Value *other)
{
    auto value = dynamic_cast<GreaterThan *>(this->getValue());
    return value->greaterThan(other->getValue());
}

Value *ReferenceValue::lessThanEqual(Value *other)
{
    auto value = dynamic_cast<LessThanEqual *>(this->getValue());
    return value->lessThanEqual(other->getValue());
}

Value *ReferenceValue::greaterThanEqual(Value *other)
{
    auto value = dynamic_cast<GreaterThanEqual *>(this->getValue());
    return value->greaterThanEqual(other->getValue());
}

Value *ReferenceValue::shiftLeft(Value *other)
{
    auto value = dynamic_cast<ShiftLeft *>(this->getValue());
    return value->shiftLeft(other->getValue());
}

Value *ReferenceValue::shiftRight(Value *other)
{
    auto value = dynamic_cast<ShiftRight *>(this->getValue());
    return value->shiftRight(other->getValue());
}

Value *ReferenceValue::add(Value *other)
{
    auto value = dynamic_cast<Add *>(this->getValue());
    return value->add(other->getValue());
}

Value *ReferenceValue::subtract(Value *other)
{
    auto value = dynamic_cast<Subtract *>(this->getValue());
    return value->subtract(other->getValue());
}

Value *ReferenceValue::bitwiseOr(Value *other)
{
    auto value = dynamic_cast<BitwiseOr *>(this->getValue());
    return value->bitwiseOr(other->getValue());
}

Value *ReferenceValue::bitwiseXOr(Value *other)
{
    auto value = dynamic_cast<BitwiseXOr *>(this->getValue());
    return value->bitwiseXOr(other->getValue());
}

Value *ReferenceValue::bitwiseAnd(Value *other)
{
    auto value = dynamic_cast<BitwiseAnd *>(this->getValue());
    return value->bitwiseAnd(other->getValue());
}

Value *ReferenceValue::multiply(Value *other)
{
    auto value = dynamic_cast<Multiply *>(this->getValue());
    return value->multiply(other->getValue());
}

Value *ReferenceValue::divide(Value *other)
{
    auto value = dynamic_cast<Divide *>(this->getValue());
    return value->divide(other->getValue());
}

Value *ReferenceValue::modulo(Value *other)
{
    auto value = dynamic_cast<Modulo *>(this->getValue());
    return value->modulo(other->getValue());
}
