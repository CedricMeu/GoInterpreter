#ifndef GOINTERPRETER_VALIDATION_SCOPE_HPP
#define GOINTERPRETER_VALIDATION_SCOPE_HPP

#include <stdexcept>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

template<typename T>
class SymbolTable
{
public:
    SymbolTable() = default;
    ~SymbolTable() = default;

    void addScope();
    void removeScope();

    bool contains(std::string& key) const;
    T get(std::string& key) const;
    void add(std::string& key, T value);
    std::vector<T> allValues();

private:
    std::vector<std::map<std::string, T>> scopes;
};

template<typename T>
void SymbolTable<T>::addScope()
{
    this->scopes.push_back(std::map<std::string, T>{});
}

template<typename T>
void SymbolTable<T>::removeScope()
{
    this->scopes.pop_back();
}

template<typename T>
bool SymbolTable<T>::contains(std::string& key) const
{
    auto _scopes = this->scopes;

    std::reverse(_scopes.begin(), _scopes.end());

    for (const auto scope : _scopes)
    {
        if (scope.contains(key))
        {
            return true;
        }
    }

    return false;
}

template<typename T>
T SymbolTable<T>::get(std::string& key) const
{
    auto _scopes = this->scopes;

    std::reverse(_scopes.begin(), _scopes.end());

    for (auto scope : _scopes)
    {
        if (scope.contains(key))
        {
            return scope[key];
        }
    }

    throw new std::out_of_range{key};
}

template<typename T>
void SymbolTable<T>::add(std::string& key, T value)
{
    this->scopes.back()[key] = value;
}

template<typename T>
std::vector<T> SymbolTable<T>::allValues()
{
    std::vector<T> result;

    for (const auto scope : this->scopes)
    {
        for (const auto pair : scope)
        {
            result.push_back(pair.second);
        }
    }

    return result;
}

#endif // GOINTERPRETER_VALIDATION_SCOPE_HPP