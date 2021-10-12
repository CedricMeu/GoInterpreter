#include "ast/literals.hpp"

AST::BoolExpression::BoolExpression(bool value): value{value}
{}

auto AST::BoolExpression::print() -> std::string
{
    return "Bool(" + std::string{this->value ? "true" : "false"} + ")";
}

AST::IntExpression::IntExpression(int value): value{value}
{}

auto AST::IntExpression::print() -> std::string
{
    return "Int(" + std::to_string(this->value) + ")";
}

AST::Float32Expression::Float32Expression(float value): value{value}
{}

auto AST::Float32Expression::print() -> std::string
{
    return "Float32(" + std::to_string(this->value) + ")";
}

AST::RuneExpression::RuneExpression(char value): value{value}
{}

auto AST::RuneExpression::print() -> std::string
{
    return "Rune(" + std::to_string(this->value) + ")";
}