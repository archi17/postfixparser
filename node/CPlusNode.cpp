//
// Created by artur on 04.11.16.
//

#include "CPlusNode.h"

int CPlusNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() + pcGetRightChild()->iEvaluate();
}
