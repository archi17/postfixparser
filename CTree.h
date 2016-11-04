//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTREE_H
#define POSTFIXPARSER_CTREE_H


#include "CNode.h"

class CTree {
public:
    CTree(const CNode *pcRoot);

private:
    const CNode *pc_root;
};


#endif //POSTFIXPARSER_CTREE_H
