//
// Created by artur on 03.11.16.
//

#include "CParser.h"

// "ab d c++"
void CParser::vTokenize(const char *sExpression) {
    const char *pc_curr = sExpression;
    while(*pc_curr != '\0') {
        const char *pc_beg = pc_curr;
        CSymbol c_symbol = c_get_symbol(pc_curr++);
        while(*pc_curr != '\0' && c_get_symbol(pc_curr) == c_symbol && (c_symbol == VAR || c_symbol == NUM))
            pc_curr++;

        if(c_symbol != WHITESPACE)
            c_tokens.push_back(new CToken(c_symbol, pc_beg, pc_curr));
    }
}

CSymbol CParser::c_get_symbol(const char *pcChar) {
    CSymbol c_symbol = ERROR;

    if(isalpha(*pcChar))
        c_symbol = VAR;
    else if(isdigit(*pcChar))
        c_symbol = NUM;
    else if(isspace(*pcChar))
        c_symbol = WHITESPACE;
    else if(*pcChar == '+')
        c_symbol = PLUS;
    else if(*pcChar == '-')
        c_symbol = MINUS;
    else if(*pcChar == '*')
        c_symbol = TIMES;
    else if(*pcChar == '/')
        c_symbol = DIVIDE;
    else if(*pcChar == '~')
        c_symbol = TILDE;

    return c_symbol;
}