
#include "CParser.h"

int main() {
    CParser c_parser;
    CTree* c_tree = c_parser.vParse("2*+");
    std::cout << c_tree->sToInfix() << std::endl;
    std::map<std::string, int> c_vars;
    c_vars.insert(std::pair<std::string, int>("a", 1));
    c_vars.insert(std::pair<std::string, int>("b", 2));

    std::cout << c_tree->iEvaluate(c_vars) << std::endl;
    std::cout << c_tree->sToLevelInOrder();


    return 0;
}