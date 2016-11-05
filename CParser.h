//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H


#include "CLogEntry.h"
#include "CTree.h"
#include "ESymbol.h"
#include "utils.h"

#include "node/CNode.h"
#include "node/CPlusNode.h"
#include "node/CMinusNode.h"
#include "node/CTimesNode.h"
#include "node/CDivideNode.h"
#include "node/CTildeNode.h"
#include "node/CVarNode.h"



class CParser {
public:
    CTree* vParse(const std::string& sExpression);

private:
    long i_pos;
    std::string s_expression;
    ESymbol e_symbol;

    CNode* pc_parse();
    void v_skip(ESymbol eSymbol);
    CNode *v_parse_terminal(ESymbol eSymbol);
};


#endif //POSTFIXPARSER_CPARSER_H
