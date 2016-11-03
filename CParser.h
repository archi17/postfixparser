//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H


class CParser {
public:
    enum Symbol {
        VAR, LITERAL, PLUS, MINUS, TIMES, DIVIDE, TILDE, WHITESPACE, ERROR
    };

    void v_parse();
};


#endif //POSTFIXPARSER_CPARSER_H
