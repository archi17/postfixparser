//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_SYMBOL_H
#define POSTFIXPARSER_SYMBOL_H

enum ESymbol {
    S_VAR, S_NUM, S_PLUS, S_MINUS, S_TIMES, S_DIVIDE, S_TILDE, S_WHITESPACE, S_ERROR
};

ESymbol eGetSymbol(char chChar);

#endif //POSTFIXPARSER_SYMBOL_H
