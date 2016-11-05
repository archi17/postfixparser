//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CBINARYNODE_H
#define POSTFIXPARSER_CBINARYNODE_H

#include "CUnaryNode.h"
#include "ESymbol.h"


class CBinaryNode : public CUnaryNode {
public:
    CBinaryNode(const std::string& sToken) : CUnaryNode(sToken) {}
    virtual ~CBinaryNode() { delete pc_right_child; }

    void vSetRightChild(const CNode* cNode) { pc_right_child = cNode; }
    const CNode* pcGetRightChild() const { return pc_right_child; }

    virtual void vLevelInOrder(CLevels& cLevels, int iLevel) const ;
    virtual void vInsertInfix(CInfix& cInfix) const;
    virtual void vRegisterVar(CVariables &cVars) const;

private:
    const CNode* pc_right_child;
};

class CTimesNode : public CBinaryNode{
public:
    CTimesNode(const std::string& sToken) : CBinaryNode(sToken) {}
    int iEvaluate(CDefinedVariables& cVars) const;
    void vInsertInfix(CInfix& cInfix) const;
};

class CPlusNode : public CBinaryNode{
public:
    CPlusNode(const std::string& sToken) : CBinaryNode(sToken) {};
    int iEvaluate(CDefinedVariables& cVars) const;
};

class CMinusNode : public CBinaryNode {
public:
    CMinusNode(const std::string& sToken) : CBinaryNode(sToken) {};
    int iEvaluate(CDefinedVariables &cVars) const;
    void vInsertInfix(CInfix& cInfix) const;
};

class CDivideNode : public CBinaryNode {
public:
    CDivideNode(const std::string& sToken) : CBinaryNode(sToken) {}
    int iEvaluate(CDefinedVariables &cVars) const;
    void vInsertInfix(CInfix& cInfix) const;
};

void vInsertNode(CInfix &cInfix, const CNode *cNode);

void vInsertBinaryNode(CInfix &cInfix, const CBinaryNode *cBinaryNode);

#endif //POSTFIXPARSER_CBINARYNODE_H
