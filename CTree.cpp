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


std::string CTree::sToLevelInOrder() const {
    std::vector<std::vector<std::string> > c_levels;
    if(pc_root != 0)
        pc_root->vLevelInOrder(c_levels, 0);

    std::ostringstream c_ostream;
    for(int i = 0; i < c_levels.size(); i++) {
        std::vector<std::string> c_level = c_levels[i];
        for(int j = 0; j < c_level.size(); j++) {
            c_ostream << c_level[j] << " ";
        }

        c_ostream << "\n";
    }

    return c_ostream.str();
}

int CTree::iEvaluate(std::map<std::string, int>& cVars) const {
    return pc_root->iEvaluate(cVars);
}

std::set<std::string> CTree::sGetVariables() const {
    std::set<std::string> c_variables;
    pc_root->vRegisterVar(c_variables);
    return c_variables;
}

