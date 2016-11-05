//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CNODE_H
#define POSTFIXPARSER_CNODE_H

#include "../utils.h"

#include <string>
#include <set>
#include <map>
#include <vector>

typedef std::set<std::string> CVariables;
typedef std::map<std::string, int> CDefinedVariables;
typedef std::vector<std::string> CLevel;
typedef std::vector<std::string> CInfix;
typedef std::vector<CLevel> CLevels;

class CNode
{
public:
    CNode(const std::string& sToken) : s_token(sToken) {}
    virtual ~CNode() { /* Doesn't have any children, nothing to do */ };

    const std::string& sGetToken() const { return s_token; }

    virtual int iEvaluate(CDefinedVariables &cVars) const = 0;

    virtual void vInsertInfix(CInfix& cInfix) const;
    virtual void vRegisterVar(CVariables &cVars) const;
    virtual void vLevelInOrder(CLevels &cLevels, int iLevel) const;

private:
    const std::string s_token;
};

class CNumNode : public CNode
{
public:
    CNumNode(const std::string& sToken) : CNode(sToken) {};
    int iEvaluate(CDefinedVariables &cVars) const;
};

class CVarNode : public CNode
{
public:
    CVarNode(const std::string& sToken) : CNode(sToken) {}
    int iEvaluate(CDefinedVariables &cVars) const;
    void vRegisterVar(CVariables &cVars) const;
};

#endif //POSTFIXPARSER_CNODE_H
