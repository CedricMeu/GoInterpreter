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
    return new BoolValue{value || dynamic_cast<BoolValue *>(other)->value};
}

Value *BoolValue::logicalAnd(Value *other)
{
    return new BoolValue{value && dynamic_cast<BoolValue *>(other)->value};
}

Value *BoolValue::equal(Value *other)
{
    return new BoolValue{value == dynamic_cast<BoolValue *>(other)->value};
}

Value *BoolValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<BoolValue *>(other)->value};
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
    return new BoolValue{value == dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::shiftLeft(Value *other)
{
    return new IntValue{value << dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::shiftRight(Value *other)
{
    return new IntValue{value >> dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::add(Value *other)
{
    return new IntValue{value + dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::subtract(Value *other)
{
    return new IntValue{value - dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::bitwiseOr(Value *other)
{
    return new IntValue{value | dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::bitwiseXOr(Value *other)
{
    return new IntValue{value ^ dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::bitwiseAnd(Value *other)
{
    return new IntValue{value & dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::multiply(Value *other)
{
    return new IntValue{value * dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::divide(Value *other)
{
    return new IntValue{value / dynamic_cast<IntValue *>(other)->value};
}

Value *IntValue::modulo(Value *other)
{
    return new IntValue{value % dynamic_cast<IntValue *>(other)->value};
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
    return new BoolValue{value == dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::add(Value *other)
{
    return new Float32Value{value + dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::subtract(Value *other)
{
    return new Float32Value{value - dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::multiply(Value *other)
{
    return new Float32Value{value * dynamic_cast<Float32Value *>(other)->value};
}

Value *Float32Value::divide(Value *other)
{
    return new Float32Value{value / dynamic_cast<Float32Value *>(other)->value};
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
    return new BoolValue{value == dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::notEqual(Value *other)
{
    return new BoolValue{value != dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::lessThan(Value *other)
{
    return new BoolValue{value < dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::greaterThan(Value *other)
{
    return new BoolValue{value > dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::lessThanEqual(Value *other)
{
    return new BoolValue{value <= dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::greaterThanEqual(Value *other)
{
    return new BoolValue{value >= dynamic_cast<RuneValue *>(other)->value};
}

Value *RuneValue::add(Value *other)
{
    return new RuneValue{static_cast<char>( value + dynamic_cast<RuneValue *>(other)->value)};
}

Value *RuneValue::subtract(Value *other)
{
    return new RuneValue{static_cast<char>( value - dynamic_cast<RuneValue *>(other)->value)};
}

Value *RuneValue::multiply(Value *other)
{
    return new RuneValue{static_cast<char>( value * dynamic_cast<RuneValue *>(other)->value)};
}

Value *RuneValue::divide(Value *other)
{
    return new RuneValue{static_cast<char>( value / dynamic_cast<RuneValue *>(other)->value)};
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
    // TODO: out of range
    return new RuneValue{value[dynamic_cast<IntValue *>(index)->getInt()]};
}

void StringValue::setIndex(Value *index, Value *newValue)
{
    // TODO: out of range
    value[dynamic_cast<IntValue *>(index)->getInt()] = dynamic_cast<RuneValue *>(newValue)->getChar();
}

Value *StringValue::simpleSlice(Value *low, Value *high)
{
    // TODO: out of range
    auto lowValue = 0;
    auto newSize = size;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    if (high != nullptr) {
        newSize = dynamic_cast<IntValue *>(high)->getInt() - lowValue;
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
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    auto highSize = dynamic_cast<IntValue *>(high)->getInt() - lowValue;
    auto maxSize = dynamic_cast<IntValue *>(max)->getInt();

    auto newSize = highSize < maxSize ? highSize : maxSize;

    auto newValue = new char[newSize];
    
    for (int i = 0; i < newSize; ++i) {
        newValue[i] = value[i + lowValue];
    }

    return new StringValue{newValue, newSize};
}



Value *StringValue::equal(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) == 0};
}

Value *StringValue::notEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) != 0};
}

Value *StringValue::lessThan(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) < 0};
}

Value *StringValue::greaterThan(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) > 0};
}

Value *StringValue::lessThanEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) <= 0};
}

Value *StringValue::greaterThanEqual(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
    return new BoolValue{compare(this, otherString) >= 0};
}

Value *StringValue::add(Value *other)
{
    auto otherString = dynamic_cast<StringValue *>(other);
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
    // TODO: out of range
    return values[dynamic_cast<IntValue *>(index)->getInt()];
}

void ArrayValue::setIndex(Value *index, Value *newValue)
{
    // TODO: out of range
    values[dynamic_cast<IntValue *>(index)->getInt()] = newValue;
}

Value *ArrayValue::simpleSlice(Value *low, Value *high)
{
    long lowValue = 0;
    long highValue = values.size();

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    if (high != nullptr) {
        highValue = dynamic_cast<IntValue *>(high)->getInt();
    }

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue; ++i) {
        newArray.push_back(values[i]);
    }

    return new SliceValue{newArray};
}

Value *ArrayValue::fullSlice(Value *low, Value *high, Value *max)
{
    long lowValue = 0;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    long highValue = dynamic_cast<IntValue *>(high)->getInt();
    long maxValue = dynamic_cast<IntValue *>(max)->getInt();

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue && i-lowValue < maxValue; ++i) {
        newArray.push_back(values[i]);
    }

    return new SliceValue{newArray};
}

Value *ArrayValue::equal(Value *other)
{
    auto otherArray = dynamic_cast<ArrayValue *>(other);

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{false};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i])->equal(otherArray->values[i]))->getBool()) {
            return new BoolValue{false};
        }
    }

    return new BoolValue{true};
}

Value *ArrayValue::notEqual(Value *other)
{
    auto otherArray = dynamic_cast<ArrayValue *>(other);

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{true};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i])->equal(otherArray->values[i]))->getBool()) {
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
    return values[dynamic_cast<IntValue *>(index)->getInt()];
}

void SliceValue::setIndex(Value *index, Value *newValue)
{
    // TODO: out of range
    values[dynamic_cast<IntValue *>(index)->getInt()] = newValue;
}

Value *SliceValue::simpleSlice(Value *low, Value *high)
{
    long lowValue = 0;
    long highValue = values.size();

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    if (high != nullptr) {
        highValue = dynamic_cast<IntValue *>(high)->getInt();
    }

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue; ++i) {
        newArray.push_back(values[i]);
    }

    return new SliceValue{newArray};
}

Value *SliceValue::fullSlice(Value *low, Value *high, Value *max)
{
    long lowValue = 0;

    if (low != nullptr) {
        lowValue = dynamic_cast<IntValue *>(low)->getInt();
    }

    long highValue = dynamic_cast<IntValue *>(high)->getInt();
    long maxValue = dynamic_cast<IntValue *>(max)->getInt();

    std::vector<Value *> newArray;

    for (int i = lowValue; i < highValue && i-lowValue < maxValue; ++i) {
        newArray.push_back(values[i]);
    }

    return new SliceValue{newArray};
}

Value *SliceValue::equal(Value *other)
{
    auto otherArray = dynamic_cast<SliceValue *>(other);

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{false};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i])->equal(otherArray->values[i]))->getBool()) {
            return new BoolValue{false};
        }
    }

    return new BoolValue{true};
}

Value *SliceValue::notEqual(Value *other)
{
    auto otherArray = dynamic_cast<SliceValue *>(other);

    if (values.size() != otherArray->values.size()) {
        return new BoolValue{true};
    }

    for (int i = 0; i < values.size(); i++)
    {
        if (!dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(values[i])->equal(otherArray->values[i]))->getBool()) {
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
    fields[id] = newValue;
}

Value *StructValue::equal(Value *other)
{
    auto otherStruct = dynamic_cast<StructValue *>(other);

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
        return dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(first)->equal(second))->getBool();
    })};
}

Value *StructValue::notEqual(Value *other)
{
    auto otherStruct = dynamic_cast<StructValue *>(other);

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
        return dynamic_cast<BoolValue *>(dynamic_cast<Equal *>(first)->equal(second))->getBool();
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

        if (dynamic_cast<BoolValue *>(fieldIndex->equal(index))->getBool()) {
            return field.second;
        }
    }

    return nullptr;
    // TODO: out of range
}

void MapValue::setIndex(Value *index, Value *newValue)
{
    for (int i = 0; i < fields.size(); ++i) {
        auto fieldIndex = dynamic_cast<Equal *>(fields[i].first);

        if (dynamic_cast<BoolValue *>(fieldIndex->equal(index))->getBool()) {
            fields[i] = std::make_pair(fields[i].first, newValue);
        }
    }
    // TODO: out of range
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
            return value->index(index);
        },
        [this, index](Value *newValue) {
            auto value = dynamic_cast<Index *>(this->getValue());

            value->setIndex(index, newValue);

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

            value->setSelect(id, newValue);

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
    return value->simpleSlice(low, high);
}

Value *ReferenceValue::fullSlice(Value *low, Value *high, Value *max)
{
    auto value = dynamic_cast<FullSlice *>(this->getValue());
    return value->fullSlice(low, high, max);
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
    return value->logicalOr(other);
}

Value *ReferenceValue::logicalAnd(Value *other)
{
    auto value = dynamic_cast<LogicalAnd *>(this->getValue());
    return value->logicalAnd(other);
}

Value *ReferenceValue::equal(Value *other)
{
    auto value = dynamic_cast<Equal *>(this->getValue());
    return value->equal(other);
}

Value *ReferenceValue::notEqual(Value *other)
{
    auto value = dynamic_cast<NotEqual *>(this->getValue());
    return value->notEqual(other);
}

Value *ReferenceValue::lessThan(Value *other)
{
    auto value = dynamic_cast<LessThan *>(this->getValue());
    return value->lessThan(other);
}

Value *ReferenceValue::greaterThan(Value *other)
{
    auto value = dynamic_cast<GreaterThan *>(this->getValue());
    return value->greaterThan(other);
}

Value *ReferenceValue::lessThanEqual(Value *other)
{
    auto value = dynamic_cast<LessThanEqual *>(this->getValue());
    return value->lessThanEqual(other);
}

Value *ReferenceValue::greaterThanEqual(Value *other)
{
    auto value = dynamic_cast<GreaterThanEqual *>(this->getValue());
    return value->greaterThanEqual(other);
}

Value *ReferenceValue::shiftLeft(Value *other)
{
    auto value = dynamic_cast<ShiftLeft *>(this->getValue());
    return value->shiftLeft(other);
}

Value *ReferenceValue::shiftRight(Value *other)
{
    auto value = dynamic_cast<ShiftRight *>(this->getValue());
    return value->shiftRight(other);
}

Value *ReferenceValue::add(Value *other)
{
    auto value = dynamic_cast<Add *>(this->getValue());
    return value->add(other);
}

Value *ReferenceValue::subtract(Value *other)
{
    auto value = dynamic_cast<Subtract *>(this->getValue());
    return value->subtract(other);
}

Value *ReferenceValue::bitwiseOr(Value *other)
{
    auto value = dynamic_cast<BitwiseOr *>(this->getValue());
    return value->bitwiseOr(other);
}

Value *ReferenceValue::bitwiseXOr(Value *other)
{
    auto value = dynamic_cast<BitwiseXOr *>(this->getValue());
    return value->bitwiseXOr(other);
}

Value *ReferenceValue::bitwiseAnd(Value *other)
{
    auto value = dynamic_cast<BitwiseAnd *>(this->getValue());
    return value->bitwiseAnd(other);
}

Value *ReferenceValue::multiply(Value *other)
{
    auto value = dynamic_cast<Multiply *>(this->getValue());
    return value->multiply(other);
}

Value *ReferenceValue::divide(Value *other)
{
    auto value = dynamic_cast<Divide *>(this->getValue());
    return value->divide(other);
}

Value *ReferenceValue::modulo(Value *other)
{
    auto value = dynamic_cast<Modulo *>(this->getValue());
    return value->modulo(other);
}
