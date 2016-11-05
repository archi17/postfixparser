//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CMINUSNODE_H
#define POSTFIXPARSER_CMINUSNODE_H


#include "CBinaryNode.h"

class CMinusNode : public CBinaryNode {
public:
    CMinusNode(const std::string& sToken) : CBinaryNode(sToken) {};

    int iEvaluate() const;
    void vPrintInfix(std::ostream& cOstream) const;
};


#endif //POSTFIXPARSER_CMINUSNODE_H
