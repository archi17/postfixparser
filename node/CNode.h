//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CNODE_H
#define POSTFIXPARSER_CNODE_H

#include <string>
#include <iostream>

class CNode {
public:
    CNode(const std::string& sToken) : s_token(sToken) {}

    const std::string& sGetToken() const { return s_token; }

    virtual int iEvaluate() const = 0;
    virtual void vPrintInfix(std::ostream& cOstream) const;

private:
    const std::string s_token;
};


#endif //POSTFIXPARSER_CNODE_H
