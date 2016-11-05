//
// Created by artur on 04.11.16.
//

#include "CTildeNode.h"

int CTildeNode::iEvaluate() const {
    return -pcGetLeftChild()->iEvaluate();
}
