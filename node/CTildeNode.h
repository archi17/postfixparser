//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTILDENODE_H
#define POSTFIXPARSER_CTILDENODE_H


#include "CUnaryNode.h"

class CTildeNode : public CUnaryNode {
public:
    CTildeNode(const std::string& sToken) : CUnaryNode(sToken) {}

    int iEvaluate() const;
};


#endif //POSTFIXPARSER_CTILDENODE_H
