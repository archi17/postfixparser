//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CDIVIDENODE_H
#define POSTFIXPARSER_CDIVIDENODE_H


#include "CBinaryNode.h"

class CDivideNode : public CBinaryNode {
public:
    CDivideNode(const std::string& sToken) : CBinaryNode(sToken) {}

    int iEvaluate() const;
    void vPrintInfix(std::ostream& cOstream) const;
};


#endif //POSTFIXPARSER_CDIVIDENODE_H
