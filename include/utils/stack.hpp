#ifndef GOINTERPRETER_UTILS_LINKED_LIST_HPP
#define GOINTERPRETER_UTILS_LINKED_LIST_HPP

#include <vector>

template<typename T>
class Stack 
{
public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const
    {
        return values.empty();
    }

    T pop()
    {
        auto value = values.back();
        values.pop_back();
        return value;
    }

    T top()
    {
        return values.back();
    }

    std::vector<T> pop(int amount)
    {
        std::vector<T> result;
        for (int i = 0; i < amount; ++i)
        {
            result.push_back(this->pop());
        }
        return result;
    }

    void push(T value)
    {
        values.push_back(value);
    }

private:
    std::vector<T> values;
};

#endif // GOINTERPRETER_UTILS_LINKED_LIST_HPP