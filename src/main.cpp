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

    if (tree != nullptr) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }

    
}
