//
// Created by artur on 05.11.16.
//

#include <map>
#include "CNode.h"

void CNode::vInsertInfix(CInfix& cInfix) const {
    cInfix.push_back(s_token);
}

void CNode::vRegisterVar(CVariables& cVars) const {
    // By default do nothing
}

void CNode::vLevelInOrder(CLevels& cLevels, int iLevel) const {
    if(iLevel >= cLevels.size())
        cLevels.push_back(std::vector<std::string>());
    cLevels[iLevel].push_back(sGetToken());
}

int CNumNode::iEvaluate(CDefinedVariables& cVars) const {
    return iToInt(sGetToken());
}

int CVarNode::iEvaluate(CDefinedVariables& cVars) const {
    return cVars[sGetToken()];
}

void CVarNode::vRegisterVar(CVariables& cVars) const {
    cVars.insert(sGetToken());
}
