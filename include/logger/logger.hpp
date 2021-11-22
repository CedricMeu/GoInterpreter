#ifndef GOINTERPRETER_LOGGER_LOGGER_HPP
#define GOINTERPRETER_LOGGER_LOGGER_HPP

#include "ast/visitor.hpp"

namespace Logger {

    class Logger : public AST::Visitor 
    {
    private:
        typedef std::vector<std::string> InfoBlock;

        std::vector<InfoBlock> infoBlockStack;

        std::string tab(std::string str) const;

    public:
        Logger() = default;
        virtual ~Logger() override = default;

        std::string getLogString() const;
        
        // Program
        virtual void visitProgram(long size) override;

        // Types
        virtual void visitBoolType() override;
        virtual void visitIntType() override;
        virtual void visitFloat32Type() override;
        virtual void visitRuneType() override;
        virtual void visitStringType() override;
        virtual void visitArrayType(long size) override;
        virtual void visitSliceType() override;
        virtual void visitStructType(std::vector<std::string> fields) override;
        virtual void visitPointerType() override;
        virtual void visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns) override;
        virtual void visitMapType() override;
        virtual void visitCustomType(std::string id) override;

        // Block
        virtual void visitInitBlock(long size) override;
        virtual void visitDeinitBlock(long size) override;

        // Declarations
        virtual void visitFunctionDeclaration(std::string id) override;
        virtual void visitTypeAliasDeclaration(std::string id) override;
        virtual void visitTypeDefinitionDeclaration(std::string id) override;
        virtual void visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count) override;

        // Statements
        virtual void visitExpressionStatement() override;
        virtual void visitAssignmentStatement(long lhsSize, long rhsSize) override;
        virtual void visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse) override;
        virtual void visitSwitchStatement(long size) override;
        virtual void visitSwitchCaseClause(long expressionsSize, long statementsSize) override;
        virtual void visitSwitchDefaultClause(long statementsSize) override;
        virtual void visitReturnStatement(long size) override;
        virtual void visitBreakStatement() override;
        virtual void visitContinueStatement() override;
        virtual void visitEmptyStatement() override;
        virtual void visitForConditionStatement() override;

        // Expressions - Literals
        virtual void visitBoolExpression(bool value) override;
        virtual void visitIntExpression(int value) override;
        virtual void visitFloat32Expression(float value) override;
        virtual void visitRuneExpression(char value) override;
        virtual void visitStringExpression(char *value, long length) override;

        // Expressions - Rest
        virtual void visitIdentifierExpression(std::string id) override;
        virtual void visitCompositLiteralExpression(std::vector<std::string> keys) override;
        virtual void VisitFunctionLiteralExpression() override;
        virtual void visitSelectExpression(std::string id) override;
        virtual void visitIndexExpression() override;
        virtual void visitSimpleSliceExpression(bool lowDeclared, bool highDeclared) override;
        virtual void visitFullSliceExpression(bool lowDeclared) override;
        virtual void visitCallExpression(long size) override;
        virtual void visitConversionExpression() override;
        virtual void visitUnaryPlusExpression() override;
        virtual void visitUnaryNegateExpression() override;
        virtual void visitUnaryLogicalNotExpression() override;
        virtual void visitUnaryBitwiseNotExpression() override;
        virtual void visitUnaryDereferenceExpression() override;
        virtual void visitUnaryReferenceExpression() override;
        virtual void visitBinaryLogicalOrExpression() override;
        virtual void visitBinaryLogicalAndExpression() override;
        virtual void visitBinaryEqualExpression() override;
        virtual void visitBinaryNotEqualExpression() override;
        virtual void visitBinaryLessThanExpression() override;
        virtual void visitBinaryLessThanEqualExpression() override;
        virtual void visitBinaryGreaterThanExpression() override;
        virtual void visitBinaryGreaterThanEqualExpression() override;
        virtual void visitBinaryShiftLeftExpression() override;
        virtual void visitBinaryShiftRightExpression() override;
        virtual void visitBinaryAddExpression() override;
        virtual void visitBinarySubtractExpression() override;
        virtual void visitBinaryBitwiseOrExpression() override;
        virtual void visitBinaryBitwiseXOrExpression() override;
        virtual void visitBinaryBitwiseAndExpression() override;
        virtual void visitBinaryMultiplyExpression() override;
        virtual void visitBinaryDivideExpression() override;
        virtual void visitBinaryModuloExpression() override;
        
    };

}; // namespace Logger

#endif // GOINTERPRETER_LOGGER_LOGGER_HPP