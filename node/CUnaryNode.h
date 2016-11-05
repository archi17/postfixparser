//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CUNARYNODE_H
#define POSTFIXPARSER_CUNARYNODE_H

#include "CNode.h"

class CUnaryNode : public CNode {
public:
    CUnaryNode(const std::string& sToken) : CNode(sToken) {};

    void vSetLeftChild(const CNode* cNode) { pc_left_child = cNode; }
    const CNode* pcGetLeftChild() const { return pc_left_child; }

    virtual void vInsertInfix(CInfix& cInfix) const;

private:
    const CNode* pc_left_child;
};


class CTildeNode : public CUnaryNode {
public:
    CTildeNode(const std::string& sToken) : CUnaryNode(sToken) {}
    int iEvaluate(CDefinedVariables &cVars) const;
};

#endif //POSTFIXPARSER_CUNARYNODE_H
