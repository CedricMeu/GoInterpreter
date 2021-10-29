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
        virtual ~Logger() = default;

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

        // Statements

        // Declarations
        virtual void visitFunctionDeclaration(std::string id) override;
        virtual void visitTypeAliasDeclaration(std::string id) override;
        virtual void visitTypeDefinitionDeclaration(std::string id) override;
        virtual void visitVariableDeclaration(std::vector<std::string> ids, bool type_declared, long expression_count) override;

        // Expressions - Literals
        virtual void visitBoolExpression(bool value) override;
        virtual void visitIntExpression(int value) override;
        virtual void visitFloat32Expression(float value) override;
        virtual void visitRuneExpression(char value) override;
        virtual void visitStringExpression(char *value, long length) override;

        // Expressions - Rest

    };

}; // namespace Logger

#endif // GOINTERPRETER_LOGGER_LOGGER_HPP