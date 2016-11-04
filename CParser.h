//
// Created by artur on 03.11.16.
//

#ifndef POSTFIXPARSER_CPARSER_H
#define POSTFIXPARSER_CPARSER_H

#include "CNode.h"
#include "CLogEntry.h"

#include <string>
#include <vector>
#include <cstring>

class CParser {
public:
    CNode* vParse(const std::string& sExpression);

private:
    char *pc_expression;
    std::vector<CToken*> c_tokens;
    std::vector<CLogEntry*> c_log;

    std::vector<CToken *>::reverse_iterator c_iter_beg;
    std::vector<CToken *>::reverse_iterator c_iter_end;

    CNode* pc_parse();
    void v_tokenize();
    CSymbol c_get_symbol(const char *pcChar) const;

    void v_warning(int iPos);
    void v_error(int iPos);
};


#endif //POSTFIXPARSER_CPARSER_H
