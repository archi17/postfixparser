//
// Created by artur on 05.11.16.
//

#include <map>
#include "CNode.h"


void CNode::vPrintInfix(std::ostream& cOstream) const {
    cOstream << s_token;
}

void CNode::vRegisterVar(std::set<std::string> &cVars) const {
    // By default do nothing
}

void CNode::vLevelInOrder(std::vector<std::vector<std::string> > &cLevels, int iLevel) const {
    if(iLevel >= cLevels.size())
        cLevels.push_back(std::vector<std::string>());
    cLevels[iLevel].push_back(sGetToken());
}

int CNumNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return iToInt(sGetToken());
}

int CVarNode::iEvaluate(std::map<std::string, int> &cVars) const {
    return cVars[sGetToken()];
}

void CVarNode::vRegisterVar(std::set<std::string> &cVars) const {
    cVars.insert(sGetToken());
}
