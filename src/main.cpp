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

    Logger::Logger logger;
    tree->accept(&logger);
    std::cout << logger.getLogString() << std::endl;

    return EXIT_SUCCESS;
}
