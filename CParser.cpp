//
// Created by artur on 03.11.16.
//

#include "CParser.h"
#include "node/CNumNode.h"

CTree* CParser::vParse(const std::string &sExpression) {
    i_pos = sExpression.length() - 1;
    s_expression = sExpression;
    return new CTree(pc_parse());
}

CNode* CParser::pc_parse() {
    CNode *c_node = 0;

    if(i_pos >= 0) {
        v_skip(S_WHITESPACE);
        std::string s_token = sToString(s_expression[i_pos--]);
        if(e_symbol == S_PLUS) {
            CPlusNode *c_plus_node = new CPlusNode(s_token);
            c_plus_node->vSetRightChild(pc_parse());
            c_plus_node->vSetLeftChild(pc_parse());
            c_node = c_plus_node;
        } else if (e_symbol == S_MINUS) {
            CMinusNode *c_minus_node = new CMinusNode(s_token);
            c_minus_node->vSetRightChild(pc_parse());
            c_minus_node->vSetLeftChild(pc_parse());
            c_node = c_minus_node;
        } else if (e_symbol == S_TIMES) {
            CTimesNode *c_times_node = new CTimesNode(s_token);
            c_times_node->vSetRightChild(pc_parse());
            c_times_node->vSetLeftChild(pc_parse());
            c_node = c_times_node;
        } else if (e_symbol == S_DIVIDE) {
            CDivideNode *c_divide_node = new CDivideNode(s_token);
            c_divide_node->vSetRightChild(pc_parse());
            c_divide_node->vSetLeftChild(pc_parse());
            c_node = c_divide_node;
        } else if (e_symbol == S_TILDE) {
            CTildeNode *c_tilde_node = new CTildeNode(s_token);
            c_tilde_node->vSetLeftChild(pc_parse());
            c_node = c_tilde_node;
        } else if (e_symbol == S_NUM || e_symbol == S_VAR) {
            c_node = v_parse_terminal(e_symbol);
        }
    }

    return c_node;
}

void CParser::v_skip(ESymbol eSymbol) {
    while(i_pos >= 0 && (e_symbol = eGetSymbol(s_expression[i_pos])) == eSymbol)
        --i_pos;
}

CNode* CParser::v_parse_terminal(ESymbol eSymbol) {
    long i_end = i_pos + 1;
    v_skip(eSymbol);
    std::string s_token = sToString(s_expression, i_pos + 1, i_end + 1);
    CNode *c_node;
    if(eSymbol == S_VAR)
        c_node = new CVarNode(s_token);
    else
        c_node = new CNumNode(s_token);

    return c_node;
}