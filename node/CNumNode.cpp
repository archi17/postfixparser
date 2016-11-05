//
// Created by artur on 04.11.16.
//

#include "CNumNode.h"

int CNumNode::iEvaluate() const {
    return iToInt(sGetToken());
}
