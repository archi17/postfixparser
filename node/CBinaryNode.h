//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CBINARYNODE_H
#define POSTFIXPARSER_CBINARYNODE_H

#include "CUnaryNode.h"
#include "../ESymbol.h"

#include <iostream>

class CBinaryNode : public CUnaryNode {
public:
    CBinaryNode(const std::string& sToken) : CUnaryNode(sToken) {}

    void vSetRightChild(const CNode* cNode) { pc_right_child = cNode; }
    const CNode* pcGetRightChild() const { return pc_right_child; }

    virtual void vLevelInOrder(std::vector<std::vector<std::string> > &cLevels, int iLevel) const ;
    virtual void vPrintInfix(std::ostream& cOstream) const;
    void vRegisterVar(std::set<std::string> &cVars) const;

private:
    const CNode* pc_right_child;
};

class CTimesNode : public CBinaryNode{
public:
    CTimesNode(const std::string& sToken) : CBinaryNode(sToken) {}
    int iEvaluate(std::map<std::string, int> &cVars) const;
    void vPrintInfix(std::ostream& cOstream) const;
};

class CPlusNode : public CBinaryNode{
public:
    CPlusNode(const std::string& sToken) : CBinaryNode(sToken) {};
    int iEvaluate(std::map<std::string, int> &cVars) const;
};

class CMinusNode : public CBinaryNode {
public:
    CMinusNode(const std::string& sToken) : CBinaryNode(sToken) {};
    int iEvaluate(std::map<std::string, int> &cVars) const;
    void vPrintInfix(std::ostream& cOstream) const;
};

class CDivideNode : public CBinaryNode {
public:
    CDivideNode(const std::string& sToken) : CBinaryNode(sToken) {}
    int iEvaluate(std::map<std::string, int> &cVars) const;
    void vPrintInfix(std::ostream& cOstream) const;
};

void vPrintNode(std::ostream &cOstream, const CNode *cNode);

void vPrintBinaryNode(std::ostream &cOstream, const CBinaryNode *cBinaryNode);

#endif //POSTFIXPARSER_CBINARYNODE_H
