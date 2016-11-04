//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CNODE_H
#define POSTFIXPARSER_CNODE_H

#include "CToken.h"


class CNode;

class INodeVisitor {
public:
    virtual void vVisit(const CNode* pcNode) = 0;
};

class CNode {
public:
    CNode(const CToken *pcToken);

    void vSetLeftChild(CNode *pcNode)  { pc_left_child  = pcNode; }
    void vSetRightChild(CNode *pcNode) { pc_right_child = pcNode; }

    const CToken* pcGetToken() const { return pc_token; }
    const CNode* pcGetLeftChild() const { return pc_left_child; }
    const CNode* pcGetRightChild() const { return pc_right_child; }

    void vVisitInOrder(INodeVisitor *iVisitor);

private:
    const CToken *pc_token;
    CNode *pc_left_child;
    CNode *pc_right_child;
};


#endif //POSTFIXPARSER_CNODE_H
