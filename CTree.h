//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTREE_H
#define POSTFIXPARSER_CTREE_H


#include "node/CNode.h"

#include <sstream>
#include <string>
#include <vector>

class CTree {
public:
    CTree(const CNode *pcRoot);

    std::string sToInfix() const;
    std::string sToLevelInOrder() const;
    std::set<std::string> sGetVariables() const;
    int iEvaluate(std::map<std::string, int>& cVars) const;

private:
    const CNode *pc_root;
};


#endif //POSTFIXPARSER_CTREE_H
