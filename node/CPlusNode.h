//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CPLUSNODE_H
#define POSTFIXPARSER_CPLUSNODE_H


#include "CBinaryNode.h"

class CPlusNode : public CBinaryNode{
public:
    CPlusNode(const std::string& sToken) : CBinaryNode(sToken) {};

    int iEvaluate() const;
};


#endif //POSTFIXPARSER_CPLUSNODE_H
