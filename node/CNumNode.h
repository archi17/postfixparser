//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CNUMNODE_H
#define POSTFIXPARSER_CNUMNODE_H

#include "CNode.h"
#include "../utils.h"


class CNumNode : public CNode {
public:
    CNumNode(const std::string& sToken) : CNode(sToken) {};

    int iEvaluate() const;
};


#endif //POSTFIXPARSER_CNUMNODE_H
