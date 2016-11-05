//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CVARNODE_H
#define POSTFIXPARSER_CVARNODE_H


#include "CNode.h"

class CVarNode : public CNode {
public:
    CVarNode(const std::string& sToken) : CNode(sToken) {}

    int iEvaluate() const;
};


#endif //POSTFIXPARSER_CVARNODE_H
