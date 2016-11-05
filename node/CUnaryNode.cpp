//
// Created by artur on 05.11.16.
//

#include "CUnaryNode.h"

void CUnaryNode::vPrintInfix(std::ostream &cOstream) const {
    cOstream << sGetToken();
    pcGetLeftChild()->vPrintInfix(cOstream);
}

int CTildeNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return -pcGetLeftChild()->iEvaluate(cVars);
}