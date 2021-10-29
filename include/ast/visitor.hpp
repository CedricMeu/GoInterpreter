#ifndef GOINTERPRETER_AST_VISITOR_HPP
#define GOINTERPRETER_AST_VISITOR_HPP

#include <string>
#include <vector>

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

        // Statements
        virtual void visitTypeAliasDeclaration(std::string id) = 0;
        virtual void visitTypeDefinitionDeclaration(std::string id) = 0;
        virtual void visitVariableDeclaration(std::vector<std::string> ids, bool type_declared, long expression_count) = 0;

        // Expressions - Literals
        virtual void visitBoolExpression(bool value) = 0;
        virtual void visitIntExpression(int value) = 0;
        virtual void visitFloat32Expression(float value) = 0;
        virtual void visitRuneExpression(char value) = 0;
        virtual void visitStringExpression(char *value, long length) = 0;

        // Expressions - Rest

    };

}; // namespace AST

#endif // GOINTERPRETER_AST_VISITOR_HPP