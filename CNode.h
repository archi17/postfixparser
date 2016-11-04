//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CNODE_H
#define POSTFIXPARSER_CNODE_H


#include "CToken.h"

class CNode {
public:
    CNode(const CToken *pcToken);

    void vSetLeftChild(const CNode *pcNode)  { pc_left_child  = pcNode; }
    void vSetRightChild(const CNode *pcNode) { pc_right_child = pcNode; }

    const CNode* pcGetLeftChild() const { return pc_left_child; }
    const CNode* pcGetRightChild() const { return pc_right_child; }

private:
    const CToken *pc_token;
    const CNode *pc_left_child;
    const CNode *pc_right_child;
};


#endif //POSTFIXPARSER_CNODE_H
