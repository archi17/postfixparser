#include <iostream>
#include <vector>
#include "CParser.h"

void print(const std::vector<CToken *>& cTokens);

int main() {
    CParser c_parser;
    c_parser.vTokenize("trzy jeden dwa + 22+ *  ad ");
    const std::vector<CToken *> c_tokens = c_parser.cGetTokens();
    print(c_tokens);
    return 0;
}

void print(const std::vector<CToken *>& cTokens) {
    for(int i = 0; i < cTokens.size(); i++) {
        std::cout << *cTokens[i] << std::endl;
    }
}