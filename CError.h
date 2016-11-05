//
// Created by artur on 05.11.16.
//

#ifndef POSTFIXPARSER_CERROR_H
#define POSTFIXPARSER_CERROR_H

enum EErrorType {
    ERR_MISSING_OPERAND, ERR_ILLEGAL_SYMBOL, ERR_UNEXPECTED_SYMBOL
};

class CError {
public:
    CError(EErrorType eType, int iPos) : e_type(eType), i_pos(iPos) {}

    EErrorType eGetType() const { return e_type; }
    int iGetPos() const { return i_pos; }

private:
    EErrorType  e_type;
    int i_pos;
};


#endif //POSTFIXPARSER_CERROR_H
