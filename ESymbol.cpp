//
// Created by artur on 05.11.16.
//

#include <cctype>
#include "ESymbol.h"

ESymbol eGetSymbol(char chChar) {
    ESymbol c_symbol = S_ERROR;

    if(isalpha(chChar))
        c_symbol = S_VAR;
    else if(isdigit(chChar))
        c_symbol = S_NUM;
    else if(isspace(chChar))
        c_symbol = S_WHITESPACE;
    else if(chChar == '+')
        c_symbol = S_PLUS;
    else if(chChar == '-')
        c_symbol = S_MINUS;
    else if(chChar == '*')
        c_symbol = S_TIMES;
    else if(chChar == '/')
        c_symbol = S_DIVIDE;
    else if(chChar == '~')
        c_symbol = S_TILDE;

    return c_symbol;
}