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
    bool scopeContains(std::string& key) const;
    T get(const std::string& key) const;
    void add(const std::string& key, T value);
    std::vector<T> allValues();
    std::map<std::string, T> getScope() const;
    void addScope(std::map<std::string, T> scope);

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
bool SymbolTable<T>::scopeContains(std::string& key) const
{
    return scopes.back().contains(key);
}

template<typename T>
T SymbolTable<T>::get(const std::string& key) const
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
void SymbolTable<T>::add(const std::string& key, T value)
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


template<typename T>
std::map<std::string, T> SymbolTable<T>::getScope() const
{
    return scopes.back();
}

template<typename T>
void SymbolTable<T>::addScope(std::map<std::string, T> scope)
{
    scopes.push_back(scope);
}

#endif // GOINTERPRETER_VALIDATION_SCOPE_HPP