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

        // Expressions - Literals
        virtual void visitBoolExpression(bool value) = 0;
        virtual void visitIntExpression(int value) = 0;
        virtual void visitFloat32Expression(float value) = 0;
        virtual void visitRuneExpression(char value) = 0;
        virtual void visitStringExpression(char *value, long length) = 0;

        // Expressions - Rest
        virtual void visitIdentifierExpression(std::string id) = 0;

    };

}; // namespace AST

#endif // GOINTERPRETER_AST_VISITOR_HPP