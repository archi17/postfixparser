//
// Created by artur on 04.11.16.
//

#include <iostream>
#include "CTree.h"

CTree::CTree(const CNode *pcRoot) : pc_root(pcRoot) {
        if(pc_root != NULL) {
            pc_root->vRegisterVar(c_vars);
            pc_root->vInsertInfix(c_infix);
            pc_root->vLevelInOrder(c_levels, 0);
        }
}

CTree::~CTree() {
    delete pc_root;
}

