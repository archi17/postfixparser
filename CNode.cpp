//
// Created by artur on 03.11.16.
//

#include "CNode.h"

CNode::CNode(const CToken *pcToken) : pc_token(pcToken), pc_left_child(0), pc_right_child(0) {

}

void CNode::vVisitInOrder(INodeVisitor *iVisitor) {
    if(pc_left_child != 0)
        pc_left_child->vVisitInOrder(iVisitor);

    iVisitor->vVisit(this);

    if(pc_right_child != 0)
        pc_right_child->vVisitInOrder(iVisitor);
}
