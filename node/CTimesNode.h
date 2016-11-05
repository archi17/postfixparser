//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CTIMESNODE_H
#define POSTFIXPARSER_CTIMESNODE_H


#include "CBinaryNode.h"

class CTimesNode : public CBinaryNode{
public:
    CTimesNode(const std::string& sToken) : CBinaryNode(sToken) {}

    int iEvaluate() const;
};


#endif //POSTFIXPARSER_CTIMESNODE_H
