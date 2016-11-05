//
// Created by artur on 04.11.16.
//

#include "CMinusNode.h"
#include "../ESymbol.h"

int CMinusNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() - pcGetRightChild()->iEvaluate();
}

void CMinusNode::vPrintInfix(std::ostream &cOstream) const {

    pcGetLeftChild()->vPrintInfix(cOstream);
    cOstream << sGetToken();

    const CNode* pc_right_child = pcGetRightChild();
    ESymbol e_right_symbol = eGetSymbol(pcGetRightChild()->sGetToken()[0]);
    if(e_right_symbol == S_MINUS) {
        cOstream << "(";
        pc_right_child->vPrintInfix(cOstream);
        cOstream << ")";
    } else {
        pc_right_child->vPrintInfix(cOstream);
    }
}
