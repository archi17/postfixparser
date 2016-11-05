//
// Created by artur on 05.11.16.
//

#include "CBinaryNode.h"

const std::string LEFT_PAREN = "(";
const std::string RIGHT_PAREN = ")";

void CBinaryNode::vInsertInfix(CInfix& cInfix) const {
    pcGetLeftChild()->vInsertInfix(cInfix);
    cInfix.push_back(sGetToken());
    pcGetRightChild()->vInsertInfix(cInfix);
}

void CBinaryNode::vRegisterVar(CVariables& cVars) const {
    // Let children register themselves.
    pcGetLeftChild()->vRegisterVar(cVars);
    pcGetRightChild()->vRegisterVar(cVars);
}

void CBinaryNode::vLevelInOrder(CLevels &cLevels, int iLevel) const {
    if(iLevel >= cLevels.size())
        cLevels.push_back(std::vector<std::string>());

    pcGetLeftChild()->vLevelInOrder(cLevels, iLevel + 1);
    cLevels[iLevel].push_back(sGetToken());
    pcGetRightChild()->vLevelInOrder(cLevels, iLevel + 1);
}

int CPlusNode::iEvaluate(CDefinedVariables& cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) + pcGetRightChild()->iEvaluate(cVars);
}

int CMinusNode::iEvaluate(CDefinedVariables& cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) - pcGetRightChild()->iEvaluate(cVars);
}

int CTimesNode::iEvaluate(CDefinedVariables& cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) * pcGetRightChild()->iEvaluate(cVars);
}

int CDivideNode::iEvaluate(CDefinedVariables& cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) / pcGetRightChild()->iEvaluate(cVars);
}

void CMinusNode::vInsertInfix(CInfix& cInfix) const {

    pcGetLeftChild()->vInsertInfix(cInfix);
    cInfix.push_back(sGetToken());

    const CNode* pc_right_child = pcGetRightChild();
    ESymbol e_right_symbol = eGetSymbol(pcGetRightChild()->sGetToken()[0]);
    if(e_right_symbol == S_MINUS) {
        cInfix.push_back(LEFT_PAREN);
        pc_right_child->vInsertInfix(cInfix);
        cInfix.push_back(RIGHT_PAREN);
    } else {
        pc_right_child->vInsertInfix(cInfix);
    }
}

void CTimesNode::vInsertInfix(CInfix& cInfix) const {
    vInsertBinaryNode(cInfix, this);
}

void CDivideNode::vInsertInfix(CInfix& cInfix) const {
    vInsertBinaryNode(cInfix, this);
}

void vInsertNode(CInfix& cInfix, const CNode *cNode) {
    ESymbol e_symbol = eGetSymbol(cNode->sGetToken()[0]);
    if(e_symbol == S_PLUS || e_symbol == S_MINUS) {
        cInfix.push_back(LEFT_PAREN);
        cNode->vInsertInfix(cInfix);
        cInfix.push_back(RIGHT_PAREN);
    } else {
        cNode->vInsertInfix(cInfix);
    }
}

void vInsertBinaryNode(CInfix &cInfix, const CBinaryNode *cBinaryNode) {
    vInsertNode(cInfix, cBinaryNode->pcGetLeftChild());
    cInfix.push_back(cBinaryNode->sGetToken());
    vInsertNode(cInfix, cBinaryNode->pcGetRightChild());
}