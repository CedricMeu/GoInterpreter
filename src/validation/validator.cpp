#include "validation/validator.hpp"

void Validator::visitProgram(long size)
{}

void Validator::visitBoolType()
{}

void Validator::visitIntType()
{}

void Validator::visitFloat32Type()
{}

void Validator::visitRuneType()
{}

void Validator::visitStringType()
{}

void Validator::visitArrayType(long size)
{}

void Validator::visitSliceType()
{}

void Validator::visitStructType(std::vector<std::string> fields)
{}

void Validator::visitPointerType()
{}

void Validator::visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns)
{}

void Validator::visitMapType()
{}

void Validator::visitCustomType(std::string id)
{}

void Validator::visitInitBlock(long size)
{}

void Validator::visitDeinitBlock(long size)
{}

void Validator::visitFunctionDeclaration(std::string id)
{}

void Validator::visitTypeAliasDeclaration(std::string id)
{}

void Validator::visitTypeDefinitionDeclaration(std::string id)
{}

void Validator::visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count)
{}

void Validator::visitExpressionStatement()
{}

void Validator::visitAssignmentStatement(long lhsSize, long rhsSize)
{}

void Validator::visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse)
{}

void Validator::visitSwitchStatement(long size)
{}

void Validator::visitSwitchCaseClause(long expressionsSize, long statementsSize)
{}

void Validator::visitSwitchDefaultClause(long statementsSize)
{}

void Validator::visitReturnStatement(long size)
{}

void Validator::visitBreakStatement()
{}

void Validator::visitContinueStatement()
{}

void Validator::visitEmptyStatement()
{}

void Validator::visitForConditionStatement()
{}

void Validator::visitBoolExpression(bool value)
{}

void Validator::visitIntExpression(int value)
{}

void Validator::visitFloat32Expression(float value)
{}

void Validator::visitRuneExpression(char value)
{}

void Validator::visitStringExpression(char *value, long length)
{}

void Validator::visitIdentifierExpression(std::string id)
{}

void Validator::visitCompositLiteralExpression(std::vector<std::string> keys)
{}

void Validator::VisitFunctionLiteralExpression()
{}

void Validator::visitSelectExpression(std::string id)
{}

void Validator::visitIndexExpression()
{}

void Validator::visitSimpleSliceExpression(bool lowDeclared, bool highDeclared)
{}

void Validator::visitFullSliceExpression(bool lowDeclared)
{}

void Validator::visitCallExpression(long size)
{}

void Validator::visitConversionExpression()
{}

void Validator::visitUnaryPlusExpression()
{}

void Validator::visitUnaryNegateExpression()
{}

void Validator::visitUnaryLogicalNotExpression()
{}

void Validator::visitUnaryBitwiseNotExpression()
{}

void Validator::visitUnaryDereferenceExpression()
{}

void Validator::visitUnaryReferenceExpression()
{}

void Validator::visitBinaryLogicalOrExpression()
{}

void Validator::visitBinaryLogicalAndExpression()
{}

void Validator::visitBinaryEqualExpression()
{}

void Validator::visitBinaryNotEqualExpression()
{}

void Validator::visitBinaryLessThanExpression()
{}

void Validator::visitBinaryLessThanEqualExpression()
{}

void Validator::visitBinaryGreaterThanExpression()
{}

void Validator::visitBinaryGreaterThanEqualExpression()
{}

void Validator::visitBinaryShiftLeftExpression()
{}

void Validator::visitBinaryShiftRightExpression()
{}

void Validator::visitBinaryAddExpression()
{}

void Validator::visitBinarySubtractExpression()
{}

void Validator::visitBinaryBitwiseOrExpression()
{}

void Validator::visitBinaryBitwiseXOrExpression()
{}

void Validator::visitBinaryBitwiseAndExpression()
{}

void Validator::visitBinaryMultiplyExpression()
{}

void Validator::visitBinaryDivideExpression()
{}

void Validator::visitBinaryModuloExpression()
{}
