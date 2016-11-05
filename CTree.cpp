//
// Created by artur on 04.11.16.
//

#include <iostream>
#include "CTree.h"

CTree::CTree(const CNode *pcRoot) : pc_root(pcRoot){

}

std::string CTree::sToInfix() const {
    std::ostringstream c_ostream;
    if(pc_root != 0)
        pc_root->vPrintInfix(c_ostream);
    return c_ostream.str();
}

int CTree::iEvaluate() const {
    return pc_root->iEvaluate();
}