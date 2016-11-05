//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTREE_H
#define POSTFIXPARSER_CTREE_H


#include "CNode.h"

#include <sstream>
#include <string>

class CTree {
public:
    CTree(const CNode *pcRoot);

    int iEvaluate(CDefinedVariables& cVars) const {  return pc_root->iEvaluate(cVars); }

    const CInfix& cToInfix() const { return c_infix; }
    const CLevels& cToLevels() const { return c_levels; }
    const CVariables& sGetVars() const { return c_vars; }

private:
    const CNode *pc_root;
    CVariables c_vars;
    CInfix c_infix;
    CLevels c_levels;
};


#endif //POSTFIXPARSER_CTREE_H
