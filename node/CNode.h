//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CNODE_H
#define POSTFIXPARSER_CNODE_H

#include "../utils.h"

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

class CNode
{
public:
    CNode(const std::string& sToken) : s_token(sToken) {}
    const std::string& sGetToken() const { return s_token; }
    virtual int iEvaluate(std::map<std::string, int> &cVars) const = 0;
    virtual void vPrintInfix(std::ostream& cOstream) const;
    virtual void vRegisterVar(std::set<std::string> &cVars) const;
    virtual void vLevelInOrder(std::vector<std::vector<std::string> > &cLevels, int iLevel) const;

private:
    const std::string s_token;
};

class CNumNode : public CNode
{
public:
    CNumNode(const std::string& sToken) : CNode(sToken) {};
    int iEvaluate(std::map<std::string, int> &cVars) const;
};

class CVarNode : public CNode
{
public:
    CVarNode(const std::string& sToken) : CNode(sToken) {}
    int iEvaluate(std::map<std::string, int> &cVars) const;
    void vRegisterVar(std::set<std::string> &cVars) const;
};

#endif //POSTFIXPARSER_CNODE_H
