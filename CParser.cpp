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
        // Skip whitespaces
        ESymbol e_symbol;
        while(i_pos >= 0 && (e_symbol = eGetSymbol(s_expression[i_pos])) == S_WHITESPACE)
            --i_pos;

        if(e_symbol == S_PLUS) {
            CPlusNode *c_plus_node = new CPlusNode(sToString(s_expression[i_pos--]));
            c_plus_node->vSetRightChild(pc_parse());
            c_plus_node->vSetLeftChild(pc_parse());
            c_node = c_plus_node;
        } else if (e_symbol == S_MINUS) {
            CMinusNode *c_minus_node = new CMinusNode(sToString(s_expression[i_pos--]));
            c_minus_node->vSetRightChild(pc_parse());
            c_minus_node->vSetLeftChild(pc_parse());
            c_node = c_minus_node;
        } else if (e_symbol == S_TIMES) {
            CTimesNode *c_times_node = new CTimesNode(sToString(s_expression[i_pos--]));
            c_times_node->vSetRightChild(pc_parse());
            c_times_node->vSetLeftChild(pc_parse());
            c_node = c_times_node;
        } else if (e_symbol == S_DIVIDE) {
            CDivideNode *c_divide_node = new CDivideNode(sToString(s_expression[i_pos--]));
            c_divide_node->vSetRightChild(pc_parse());
            c_divide_node->vSetLeftChild(pc_parse());
            c_node = c_divide_node;
        } else if (e_symbol == S_TILDE) {
            CTildeNode *c_tilde_node = new CTildeNode(sToString(s_expression[i_pos--]));
            c_tilde_node->vSetLeftChild(pc_parse());
            c_node = c_tilde_node;
        } else if (e_symbol == S_NUM) {
            long i_end = i_pos--;
            // Find beginning of a number
            while(i_pos >= 0 && (e_symbol = eGetSymbol(s_expression[i_pos])) == S_NUM)
                --i_pos;
            CNumNode *c_num_node = new CNumNode(sToString(s_expression, i_pos + 1, i_end + 1));
            c_node = c_num_node;
        } else if (e_symbol == S_VAR) {
            long i_end = i_pos--;
            // Find beginning of a variable
            while(i_pos >= 0 && (e_symbol = eGetSymbol(s_expression[i_pos])) == S_VAR)
                --i_pos;
            CVarNode *c_var_node = new CVarNode(sToString(s_expression, i_pos + 1, i_end + 1));
            c_node = c_var_node;
        }
    }

    return c_node;
}