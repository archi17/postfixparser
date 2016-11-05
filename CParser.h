//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H


#include "node/ESymbol.h"
#include "utils.h"

#include "node/CTree.h"
#include "node/CUnaryNode.h"
#include "node/CBinaryNode.h"

class CParser {
public:
    CTree* vParse(const std::string& sExpression);

private:
    long i_pos;
    ESymbol e_symbol;
    std::string s_expression;

    void v_skip(ESymbol eSymbol);
    CNode* pc_parse_expression();
    CNode *pc_parse_terminal(ESymbol eSymbol);
    CNode *pc_parse_or_default();
    CBinaryNode *pc_parse_children(CBinaryNode *cBinaryNode);
};


#endif //POSTFIXPARSER_CPARSER_H
