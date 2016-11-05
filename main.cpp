
#include "CParser.h"
#include <iostream>

int main() {
    CParser c_parser;
    CTree* c_tree = c_parser.vParse("ad 1234 + c *");
    std::cout << c_tree->sToInfix() << std::endl;
    //std::cout << c_tree->iEvaluate() << std::endl;

    return 0;
}