//
// Created by artur on 03.11.16.
//

#include "CToken.h"

CToken::CToken(CSymbol cSymbol, const char *pcBeg, const char *pcEnd) : c_symbol(cSymbol), pc_beg(pcBeg), pc_end(pcEnd)
{}

std::ostream& operator<<(std::ostream& cOStream, const CToken& cToken) {
    const char* pc_curr = cToken.pc_beg;
    while(pc_curr < cToken.pc_end)
        cOStream << *pc_curr++;

    return cOStream;
}