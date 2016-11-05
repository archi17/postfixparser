//
// Created by artur on 05.11.16.
//

#include "CUnaryNode.h"

void CUnaryNode::vInsertInfix(CInfix& cInfix) const {
    cInfix.push_back(sGetToken());
    pcGetLeftChild()->vInsertInfix(cInfix);
}

int CTildeNode::iEvaluate(CDefinedVariables &cVars) const {
    return -pcGetLeftChild()->iEvaluate(cVars);
}