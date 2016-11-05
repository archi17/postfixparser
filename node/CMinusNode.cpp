//
// Created by artur on 04.11.16.
//

#include "CMinusNode.h"

int CMinusNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() - pcGetRightChild()->iEvaluate();
}
