#ifndef GOINTERPRETER_AST_VISITOR_HPP
#define GOINTERPRETER_AST_VISITOR_HPP

#include <string>
#include <vector>
#include <functional> 

namespace AST {

    class Visitor 
    {
    protected:
        Visitor() = default;

    public:
        virtual ~Visitor() = default;

        //***************************************//
        //            Visit functions            //
        //***************************************//
        // Rules:                                //
        // - Nodes are visited depth-first       //
        //      Pre-order (except initblock)     //
        // - lists are visited in reversed order //
        //***************************************//

        // TODO: visit everyting in-order
        //  Otherwise rhs will be evaluated before lhs 
        //  and '++', etc. will not work correctly

        // Program
        virtual void visitProgram(long size) = 0;

        // Types
        virtual void visitBoolType() = 0;
        virtual void visitIntType() = 0;
        virtual void visitFloat32Type() = 0;
        virtual void visitRuneType() = 0;
        virtual void visitStringType() = 0;
        virtual void visitArrayType(long size) = 0;
        virtual void visitSliceType() = 0;
        virtual void visitStructType(std::vector<std::string> fields) = 0;
        virtual void visitPointerType() = 0;
        virtual void visitFunctionType(std::vector<std::string> parameters, std::vector<std::string> returns) = 0;
        virtual void visitMapType() = 0;
        virtual void visitCustomType(std::string id) = 0;

        // Block
        virtual void visitInitBlock(long size) = 0;
        virtual void visitDeinitBlock(long size) = 0;

        // Declarations
        virtual void visitFunctionDeclaration(std::string id) = 0;
        virtual void visitTypeAliasDeclaration(std::string id) = 0;
        virtual void visitTypeDefinitionDeclaration(std::string id) = 0;
        virtual void visitVariableDeclaration(std::vector<std::string> ids, bool typeDeclared, long expression_count) = 0;

        // Statements
        virtual void visitExpressionStatement() = 0;
        virtual void visitAssignmentStatement(long lhsSize, long rhsSize) = 0;
        virtual void visitIfStatement(const std::function <void ()>& visitTrue, const std::function <void ()>& visitFalse) = 0;
        virtual void visitSwitchStatement(long size) = 0;
        virtual void visitSwitchCaseClause(long expressionsSize, long statementsSize) = 0;
        virtual void visitSwitchDefaultClause(long statementsSize) = 0;
        virtual void visitReturnStatement(long size) = 0;
        virtual void visitBreakStatement() = 0;
        virtual void visitContinueStatement() = 0;
        virtual void visitEmptyStatement() = 0;
        virtual void visitForConditionStatement() = 0;

        // Expressions - Literals
        virtual void visitBoolExpression(bool value) = 0;
        virtual void visitIntExpression(int value) = 0;
        virtual void visitFloat32Expression(float value) = 0;
        virtual void visitRuneExpression(char value) = 0;
        virtual void visitStringExpression(char *value, long length) = 0;

        // Expressions - Rest
        virtual void visitIdentifierExpression(std::string id) = 0;
        virtual void visitCompositLiteralExpression(std::vector<std::string> keys) = 0;
        virtual void VisitFunctionLiteralExpression() = 0;
        virtual void visitSelectExpression(std::string id) = 0;
        virtual void visitIndexExpression() = 0;
        virtual void visitSimpleSliceExpression(bool lowDeclared, bool highDeclared) = 0;
        virtual void visitFullSliceExpression(bool lowDeclared) = 0;
        virtual void visitCallExpression(long size) = 0;
        virtual void visitConversionExpression() = 0;
        virtual void visitUnaryPlusExpression() = 0;
        virtual void visitUnaryNegateExpression() = 0;
        virtual void visitUnaryLogicalNotExpression() = 0;
        virtual void visitUnaryBitwiseNotExpression() = 0;
        virtual void visitUnaryDereferenceExpression() = 0;
        virtual void visitUnaryReferenceExpression() = 0;
        virtual void visitBinaryLogicalOrExpression() = 0;
        virtual void visitBinaryLogicalAndExpression() = 0;
        virtual void visitBinaryEqualExpression() = 0;
        virtual void visitBinaryNotEqualExpression() = 0;
        virtual void visitBinaryLessThanExpression() = 0;
        virtual void visitBinaryLessThanEqualExpression() = 0;
        virtual void visitBinaryGreaterThanExpression() = 0;
        virtual void visitBinaryGreaterThanEqualExpression() = 0;
        virtual void visitBinaryShiftLeftExpression() = 0;
        virtual void visitBinaryShiftRightExpression() = 0;
        virtual void visitBinaryAddExpression() = 0;
        virtual void visitBinarySubtractExpression() = 0;
        virtual void visitBinaryBitwiseOrExpression() = 0;
        virtual void visitBinaryBitwiseXOrExpression() = 0;
        virtual void visitBinaryBitwiseAndExpression() = 0;
        virtual void visitBinaryMultiplyExpression() = 0;
        virtual void visitBinaryDivideExpression() = 0;
        virtual void visitBinaryModuloExpression() = 0;

    };

}; // namespace AST

#endif // GOINTERPRETER_AST_VISITOR_HPP