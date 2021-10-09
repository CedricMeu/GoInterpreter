#include <iostream>
#include <cstdio>

#include "main.hpp"

int main() {
    yyin = fopen("test/test.go", "r");
    if (yyin == NULL) {
        std::cerr << "Cant open input file" << std::endl;   
        return EXIT_FAILURE;
    }

    yyparse();

    std::cout << tree->print() << std::endl;

    return EXIT_SUCCESS;
}
