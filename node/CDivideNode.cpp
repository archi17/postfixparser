//
// Created by artur on 04.11.16.
//

#include "CDivideNode.h"

int CDivideNode::iEvaluate() const {
    return pcGetLeftChild()->iEvaluate() / pcGetRightChild()->iEvaluate();
}
