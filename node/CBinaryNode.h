//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CBINARYNODE_H
#define POSTFIXPARSER_CBINARYNODE_H

#include "CUnaryNode.h"

class CBinaryNode : public CUnaryNode {
public:
    CBinaryNode(const std::string& sToken) : CUnaryNode(sToken) {}

    void vSetRightChild(const CNode* cNode) { pc_right_child = cNode; }
    const CNode* pcGetRightChild() const { return pc_right_child; }

    virtual void vPrintInfix(std::ostream& cOstream) const;

private:
    const CNode* pc_right_child;
};

#endif //POSTFIXPARSER_CBINARYNODE_H
