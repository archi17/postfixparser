//
// Created by artur on 03.11.16.
//

#include "CParser.h"

CTree* CParser::vParse(const std::string &sExpression) {
    strcpy(pc_expression, sExpression.c_str());
    v_tokenize();
    CNode* pc_root = 0;
    if(c_log.empty()) {
        c_iter_beg = c_tokens.rbegin();
        c_iter_end = c_tokens.rend();
        pc_root = pc_parse();
    }

    return new CTree(pc_root);
}

CNode* CParser::pc_parse() {
    CNode *pc_node = 0;

    if(c_iter_beg != c_iter_end) {
        CToken *pc_token = (*c_iter_beg++);
        pc_node = new CNode(pc_token);

        CSymbol c_symbol = pc_token->cGetSymbol();

        if (c_symbol == S_TILDE) {
            pc_node->vSetLeftChild(pc_parse());
        } else if (c_symbol == S_PLUS || c_symbol == S_MINUS || c_symbol == S_TIMES || c_symbol == S_DIVIDE) {
            pc_node->vSetRightChild(pc_parse());
            pc_node->vSetLeftChild(pc_parse());
        }
    }

    return pc_node;
}

void CParser::v_tokenize() {
    const char *pc_curr = pc_expression;
    while(*pc_curr != '\0') {
        const char *pc_beg = pc_curr;
        CSymbol c_symbol = c_get_symbol(pc_curr++);

        // Move pc_curr one past end of literal or variable
        while(*pc_curr != '\0' && c_get_symbol(pc_curr) == c_symbol && (c_symbol == S_VAR || c_symbol == S_NUM))
            pc_curr++;

        if(c_symbol == S_ERROR)
            v_error(pc_curr - pc_expression);
        else if(c_symbol != S_WHITESPACE)
            c_tokens.push_back(new CToken(c_symbol, pc_beg, pc_curr));
    }
}

CSymbol CParser::c_get_symbol(const char *pcChar) const {
    CSymbol c_symbol = S_ERROR;

    if(isalpha(*pcChar))
        c_symbol = S_VAR;
    else if(isdigit(*pcChar))
        c_symbol = S_NUM;
    else if(isspace(*pcChar))
        c_symbol = S_WHITESPACE;
    else if(*pcChar == '+')
        c_symbol = S_PLUS;
    else if(*pcChar == '-')
        c_symbol = S_MINUS;
    else if(*pcChar == '*')
        c_symbol = S_TIMES;
    else if(*pcChar == '/')
        c_symbol = S_DIVIDE;
    else if(*pcChar == '~')
        c_symbol = S_TILDE;

    return c_symbol;
}

void CParser::v_error(int iPos) {
    c_log.push_back(new CLogEntry(LEVEL_ERROR, iPos));
}

void CParser::v_warning(int iPos) {
    c_log.push_back(new CLogEntry(LEVEL_WARNING, iPos));
}
