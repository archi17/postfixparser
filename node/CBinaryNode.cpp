//
// Created by artur on 05.11.16.
//

#include "CBinaryNode.h"

const char LEFT_PAREN = '(';
const char RIGHT_PAREN = ')';

void CBinaryNode::vPrintInfix(std::ostream &cOstream) const {
    pcGetLeftChild()->vPrintInfix(cOstream);
    cOstream << sGetToken();
    pcGetRightChild()->vPrintInfix(cOstream);
}

void CBinaryNode::vRegisterVar(std::set<std::string> &cVars) const {
    // Let children register themselves.
    pcGetLeftChild()->vRegisterVar(cVars);
    pcGetRightChild()->vRegisterVar(cVars);
}

void CBinaryNode::vLevelInOrder(std::vector<std::vector<std::string> > &cLevels, int iLevel) const {
    if(iLevel >= cLevels.size())
        cLevels.push_back(std::vector<std::string>());

    pcGetLeftChild()->vLevelInOrder(cLevels, iLevel + 1);
    cLevels[iLevel].push_back(sGetToken());
    pcGetRightChild()->vLevelInOrder(cLevels, iLevel + 1);
}

int CPlusNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) + pcGetRightChild()->iEvaluate(cVars);
}

int CMinusNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) - pcGetRightChild()->iEvaluate(cVars);
}

int CTimesNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) * pcGetRightChild()->iEvaluate(cVars);
}

int CDivideNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return pcGetLeftChild()->iEvaluate(cVars) / pcGetRightChild()->iEvaluate(cVars);
}

void CMinusNode::vPrintInfix(std::ostream &cOstream) const {

    pcGetLeftChild()->vPrintInfix(cOstream);
    cOstream << sGetToken();

    const CNode* pc_right_child = pcGetRightChild();
    ESymbol e_right_symbol = eGetSymbol(pcGetRightChild()->sGetToken()[0]);
    if(e_right_symbol == S_MINUS) {
        cOstream << LEFT_PAREN;
        pc_right_child->vPrintInfix(cOstream);
        cOstream << RIGHT_PAREN;
    } else {
        pc_right_child->vPrintInfix(cOstream);
    }
}

void CTimesNode::vPrintInfix(std::ostream &cOstream) const {
    vPrintBinaryNode(cOstream, this);
}

void CDivideNode::vPrintInfix(std::ostream &cOstream) const {
    vPrintBinaryNode(cOstream, this);
}

void vPrintNode(std::ostream &cOstream, const CNode *cNode) {
    ESymbol e_symbol = eGetSymbol(cNode->sGetToken()[0]);
    if(e_symbol == S_PLUS || e_symbol == S_MINUS) {
        cOstream << LEFT_PAREN;
        cNode->vPrintInfix(cOstream);
        cOstream << RIGHT_PAREN;
    } else {
        cNode->vPrintInfix(cOstream);
    }
}

void vPrintBinaryNode(std::ostream &cOstream, const CBinaryNode *cBinaryNode) {
    vPrintNode(cOstream, cBinaryNode->pcGetLeftChild());
    cOstream << cBinaryNode->sGetToken();
    vPrintNode(cOstream, cBinaryNode->pcGetRightChild());
}