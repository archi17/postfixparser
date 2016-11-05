//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTREE_H
#define POSTFIXPARSER_CTREE_H


#include "node/CNode.h"

#include <sstream>
#include <string>


class CTree {
public:
    CTree(const CNode *pcRoot);

    std::string sToInfix() const;
    int iEvaluate() const;

private:
    const CNode *pc_root;
};


#endif //POSTFIXPARSER_CTREE_H
