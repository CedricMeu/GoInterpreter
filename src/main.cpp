#include <iostream>
#include <cstdio>

#include "main.hpp"

int main() {
    yyin = fopen("/Users/cedricmeukens/Documents/UHasselt/Compilers/GoInterpreter/test/test.go", "r");
    if (yyin == NULL) {
        std::cerr << "Cant open input file" << std::endl;   
        return EXIT_FAILURE;
    }

    yyparse();

    if (tree == nullptr) {
        return EXIT_FAILURE;
    }

    Validator validator{};

    tree->accept(&validator);

    for (auto error : validator.getErrors())
    {
        std::cerr << error << std::endl;
    }

    return EXIT_SUCCESS;
}
