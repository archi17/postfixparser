//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H


#include "tree/ESymbol.h"
#include "CError.h"
#include "utils.h"

#include "tree/CTree.h"
#include "tree/CUnaryNode.h"
#include "tree/CBinaryNode.h"

#include <vector>

typedef std::vector<CError> CErrors;

class CParser {
public:
    CTree* pcParse(const std::string &sExpression);
    const CErrors& cGetErrors() const { return c_errors; }

private:
    long i_pos;
    ESymbol e_symbol;
    std::string s_expression;
    CErrors c_errors;

    void v_skip(ESymbol eSymbol);
    CNode* pc_parse_expression();
    CNode* pc_parse_terminal(ESymbol eSymbol);
    CNode* pc_parse_or_default();
    CBinaryNode* pc_parse_children(CBinaryNode *cBinaryNode);

    void v_error(EErrorType eErrorType, long iPos);
};


#endif //POSTFIXPARSER_CPARSER_H
