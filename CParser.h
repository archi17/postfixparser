//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H

#include <string>
#include <vector>
#include "CNode.h"

class CParser {
public:

    void vTokenize(const char *sExpression);
    const std::vector<CToken *>& cGetTokens() { return c_tokens; }

private:
    std::vector<CToken*> c_tokens;

    CSymbol c_get_symbol(const char *pcChar);
};


#endif //POSTFIXPARSER_CPARSER_H
