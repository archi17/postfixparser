//
// Created by artur on 03.11.16.
//

#include "CParser.h"
#include "node/CNumNode.h"

CTree* CParser::vParse(const std::string &sExpression) {
    long i_pos = sExpression.length() - 1;
    return new CTree(pc_parse(sExpression, i_pos));
}

CNode* CParser::pc_parse(const std::string &sExpression, long& iPos) {
    CNode *c_node = 0;

    if(iPos >= 0) {
        // Skip whitespaces
        ESymbol e_symbol;
        while(iPos >= 0 && (e_symbol = eGetSymbol(sExpression[iPos])) == S_WHITESPACE)
            --iPos;

        if(e_symbol == S_PLUS) {
            CPlusNode *c_plus_node = new CPlusNode(sToString(sExpression[iPos]));
            c_plus_node->vSetRightChild(pc_parse(sExpression, --iPos));
            c_plus_node->vSetLeftChild(pc_parse(sExpression, --iPos));
            c_node = c_plus_node;
        } else if (e_symbol == S_MINUS) {
            CMinusNode *c_minus_node = new CMinusNode(sToString(sExpression[iPos]));
            c_minus_node->vSetRightChild(pc_parse(sExpression, --iPos));
            c_minus_node->vSetLeftChild(pc_parse(sExpression, --iPos));
            c_node = c_minus_node;
        } else if (e_symbol == S_TIMES) {
            CTimesNode *c_times_node = new CTimesNode(sToString(sExpression[iPos]));
            c_times_node->vSetRightChild(pc_parse(sExpression, --iPos));
            c_times_node->vSetLeftChild(pc_parse(sExpression, --iPos));
            c_node = c_times_node;
        } else if (e_symbol == S_DIVIDE) {
            CDivideNode *c_divide_node = new CDivideNode(sToString(sExpression[iPos]));
            c_divide_node->vSetRightChild(pc_parse(sExpression, --iPos));
            c_divide_node->vSetLeftChild(pc_parse(sExpression,--iPos));
            c_node = c_divide_node;
        } else if (e_symbol == S_TILDE) {
            CTildeNode *c_tilde_node = new CTildeNode(sToString(sExpression[iPos]));
            c_tilde_node->vSetLeftChild(pc_parse(sExpression, --iPos));
            c_node = c_tilde_node;
        } else if (e_symbol == S_NUM) {
            long i_end = iPos--;
            // Find beginning of number
            while(iPos >= 0 && (e_symbol = eGetSymbol(sExpression[iPos])) == S_NUM)
                --iPos;
            CNumNode *c_num_node = new CNumNode(sToString(sExpression, iPos + 1, i_end + 1));
            c_node = c_num_node;
        } else if (e_symbol == S_VAR) {
            long i_end = iPos--;
            // Find beginning of variable
            while(iPos >= 0 && (e_symbol = eGetSymbol(sExpression[iPos])) == S_VAR)
                --iPos;
            CVarNode *c_var_node = new CVarNode(sToString(sExpression, iPos + 1, i_end + 1));
            c_node = c_var_node;
        }
    }

    return c_node;
}