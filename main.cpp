
#include "CParser.h"
#include <iostream>

int main() {
    CParser c_parser;
    CTree* c_tree = c_parser.vParse("ab 2 3--");
    std::cout << c_tree->sToInfix() << std::endl;
    //std::cout << c_tree->iEvaluate() << std::endl;

    return 0;
}