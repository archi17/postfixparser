//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CTOKEN_H
#define POSTFIXPARSER_CTOKEN_H


#include <vector>
#include <string>
#include <iostream>
#include "CSymbol.h"

class CToken;

std::ostream& operator<<(std::ostream& cOstream, const CToken& cToken);

class CToken {
public:
    CToken(const CSymbol cSymbol, const char* pcBeg, const char *pcEnd);

private:
    const CSymbol c_symbol;
    const char *pc_beg;
    const char *pc_end;

    friend std::ostream& operator<<(std::ostream& cOstream, const CToken& cToken);
};


#endif //POSTFIXPARSER_CTOKEN_H
