#include <iostream>
#include <cstdio>

#include "main.hpp"

int main() {
    yyin = fopen("/Users/cedricmeukens/Documents/UHasselt/Compilers/GoInterpreter/test/test.go", "r");
    if (yyin == NULL) {
        std::cerr << "Cant open input file" << std::endl;   
        return EXIT_FAILURE;
    }

    // Parse file
    yyparse();

    if (tree == nullptr) {
        return EXIT_FAILURE;
    }

    // Validate program
    Validator validator{};
    tree->accept(&validator);

    for (auto error : validator.getErrors())
    {
        std::cerr << error << std::endl;
    }

    // Run if no errors
    if (validator.getErrors().empty()) {
        Interpreter interpreter{};
        tree->accept(&interpreter);
    }

    return EXIT_SUCCESS;
}
