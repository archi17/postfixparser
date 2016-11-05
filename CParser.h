//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H


#include "CLogEntry.h"
#include "CTree.h"
#include "ESymbol.h"
#include "utils.h"

#include "node/CNode.h"
#include "node/CPlusNode.h"
#include "node/CMinusNode.h"
#include "node/CTimesNode.h"
#include "node/CDivideNode.h"
#include "node/CTildeNode.h"
#include "node/CVarNode.h"



class CParser {
public:
    CTree* vParse(const std::string& sExpression);

private:
    CNode* pc_parse(const std::string& sExpression, long& iPos);
};


#endif //POSTFIXPARSER_CPARSER_H
