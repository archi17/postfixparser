//
// Created by artur on 05.11.16.
//

#include "CUnaryNode.h"

const std::string LEFT_PAREN = "(";
const std::string RIGHT_PAREN = ")";

void CUnaryNode::vInsertInfix(CInfix& cInfix) const {
    cInfix.push_back(sGetToken());
    const CNode *c_node = pc_left_child;
    ESymbol e_symbol = eGetSymbol(c_node->sGetToken()[0]);
    if(e_symbol != S_VAR && e_symbol != S_NUM) {
        cInfix.push_back(LEFT_PAREN);
        c_node->vInsertInfix(cInfix);
        cInfix.push_back(RIGHT_PAREN);
    } else {
        c_node->vInsertInfix(cInfix);
    }
}

int CTildeNode::iEvaluate(CDefinedVariables &cVars) const {
    return -pcGetLeftChild()->iEvaluate(cVars);
}