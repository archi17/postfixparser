//
// Created by artur on 04.11.16.
//

#include "CDivideNode.h"
#include "../ESymbol.h"

int CDivideNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() / pcGetRightChild()->iEvaluate();
}

void CDivideNode::vPrintInfix(std::ostream &cOstream) const {
    const CNode* pc_left_child = pcGetLeftChild();
    ESymbol e_left_symbol = eGetSymbol(pcGetLeftChild()->sGetToken()[0]);
    if(e_left_symbol == S_PLUS || e_left_symbol == S_MINUS) {
        cOstream << "(";
        pc_left_child->vPrintInfix(cOstream);
        cOstream << ")";
    } else {
        pc_left_child->vPrintInfix(cOstream);
    }

    cOstream << sGetToken();

    const CNode* pc_right_child = pcGetRightChild();
    ESymbol e_right_symbol = eGetSymbol(pcGetRightChild()->sGetToken()[0]);
    if(e_right_symbol == S_PLUS || e_right_symbol == S_MINUS) {
        cOstream << "(";
        pc_right_child->vPrintInfix(cOstream);
        cOstream << ")";
    } else {
        pc_right_child->vPrintInfix(cOstream);
    }
}
