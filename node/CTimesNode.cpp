//
// Created by artur on 04.11.16.
//

#include "CTimesNode.h"

int CTimesNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() * pcGetRightChild()->iEvaluate();
}
