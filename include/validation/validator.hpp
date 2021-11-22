#ifndef GOINTERPRETER_VALIDATION_VALIDATOR_HPP
#define GOINTERPRETER_VALIDATION_VALIDATOR_HPP

#include "ast/visitor.hpp"

class Validator : public AST::Visitor
{
private:

public:
    Validator() = default;
    ~Validator() = default;


    // Program
    void visitProgram(long size) override;

    // Types
    void visitBoolType() override;
    void visitIntType() override;
    void visitFloat32Type() override;
    void visitRuneType() override;
    void visitStringType() override;
    void visitArrayType(long size) override;
    void visitSliceType() override;
    void visitStructType(std::vector<std::string> fields) override;
    void visitPointerType() override;
    void visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns) override;
    void visitMapType() override;
    void visitCustomType(std::string id) override;

    // Block
    void visitInitBlock(long size) override;
    void visitDeinitBlock(long size) override;

    // Declarations
    void visitFunctionDeclaration(std::string id) override;
    void visitTypeAliasDeclaration(std::string id) override;
    void visitTypeDefinitionDeclaration(std::string id) override;
    void visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count) override;

    // Statements
    void visitExpressionStatement() override;
    void visitAssignmentStatement(long lhsSize, long rhsSize) override;
    void visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse) override;
    void visitSwitchStatement(long size) override;
    void visitSwitchCaseClause(long expressionsSize, long statementsSize) override;
    void visitSwitchDefaultClause(long statementsSize) override;
    void visitReturnStatement(long size) override;
    void visitBreakStatement() override;
    void visitContinueStatement() override;
    void visitEmptyStatement() override;
    void visitForConditionStatement() override;

    // Expressions - Literals
    void visitBoolExpression(bool value) override;
    void visitIntExpression(int value) override;
    void visitFloat32Expression(float value) override;
    void visitRuneExpression(char value) override;
    void visitStringExpression(char *value, long length) override;

    // Expressions - Rest
    void visitIdentifierExpression(std::string id) override;
    void visitCompositLiteralExpression(std::vector<std::string> keys) override;
    void VisitFunctionLiteralExpression() override;
    void visitSelectExpression(std::string id) override;
    void visitIndexExpression() override;
    void visitSimpleSliceExpression(bool lowDeclared, bool highDeclared) override;
    void visitFullSliceExpression(bool lowDeclared) override;
    void visitCallExpression(long size) override;
    void visitConversionExpression() override;
    void visitUnaryPlusExpression() override;
    void visitUnaryNegateExpression() override;
    void visitUnaryLogicalNotExpression() override;
    void visitUnaryBitwiseNotExpression() override;
    void visitUnaryDereferenceExpression() override;
    void visitUnaryReferenceExpression() override;
    void visitBinaryLogicalOrExpression() override;
    void visitBinaryLogicalAndExpression() override;
    void visitBinaryEqualExpression() override;
    void visitBinaryNotEqualExpression() override;
    void visitBinaryLessThanExpression() override;
    void visitBinaryLessThanEqualExpression() override;
    void visitBinaryGreaterThanExpression() override;
    void visitBinaryGreaterThanEqualExpression() override;
    void visitBinaryShiftLeftExpression() override;
    void visitBinaryShiftRightExpression() override;
    void visitBinaryAddExpression() override;
    void visitBinarySubtractExpression() override;
    void visitBinaryBitwiseOrExpression() override;
    void visitBinaryBitwiseXOrExpression() override;
    void visitBinaryBitwiseAndExpression() override;
    void visitBinaryMultiplyExpression() override;
    void visitBinaryDivideExpression() override;
    void visitBinaryModuloExpression() override;
};

#endif GOINTERPRETER_VALIDATION_VALIDATOR_HPP