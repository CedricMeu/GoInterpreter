#include <iostream>
#include <cstdio>

#include "main.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: GoInterpreter <file>" << std::endl;
        return EXIT_FAILURE;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        std::cerr << "Cant open file: " << argv[1] << std::endl;   
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

        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }

}
