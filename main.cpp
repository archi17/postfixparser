#include "CParser.h"
#include <iostream>

int main() {

    CParser c_parser;
    CTree *c_tree = c_parser.pcParse("a b c + *+");
    CInfix c_infix = c_tree->cToInfix();

    CInfix::const_iterator c_beg = c_infix.begin();
    CInfix::const_iterator c_end = c_infix.end();
    while(c_beg != c_end) {
        std::cout << *c_beg++ << " ";
    }

    return 0;
}