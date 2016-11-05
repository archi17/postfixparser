//
// Created by artur on 03.11.16.
//

#include "CParser.h"

CTree* CParser::vParse(const std::string &sExpression) {
    i_pos = sExpression.length() - 1;
    s_expression = sExpression;
    CTree *c_tree = new CTree(pc_parse_expression());
    if(e_symbol == S_ERROR || i_pos >= 0) {
        // error or warning;
    }
    return c_tree;
}

CNode* CParser::pc_parse_expression() {
    CNode *c_node = 0;

    if(i_pos >= 0) {
        v_skip(S_WHITESPACE);
        std::string s_token = sToString(s_expression[i_pos--]);

        if(e_symbol == S_PLUS) {
            c_node = pc_parse_children(new CPlusNode(s_token));
        } else if (e_symbol == S_MINUS) {
            c_node = pc_parse_children(new CMinusNode(s_token));
        } else if (e_symbol == S_TIMES) {
            c_node = pc_parse_children(new CTimesNode(s_token));
        } else if (e_symbol == S_DIVIDE) {
            c_node = pc_parse_children(new CDivideNode(s_token));
        } else if (e_symbol == S_TILDE) {
            CTildeNode *c_tilde_node = new CTildeNode(s_token);
            c_tilde_node->vSetLeftChild(pc_parse_expression());
            c_node = c_tilde_node;
        } else if (e_symbol == S_NUM || e_symbol == S_VAR) {
            c_node = pc_parse_terminal(e_symbol);
        }
    }

    return c_node;
}

void CParser::v_skip(ESymbol eSymbol) {
    while(i_pos >= 0 && (e_symbol = eGetSymbol(s_expression[i_pos])) == eSymbol)
        --i_pos;
}

CNode* CParser::pc_parse_terminal(ESymbol eSymbol) {
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

CBinaryNode* CParser::pc_parse_children(CBinaryNode* cBinaryNode) {
    CNode *pc_left_child = pc_parse_expression();
    CNode *pc_right_child = pc_parse_expression();

    CNode *pc_default_node = new CNumNode("1");

    if(pc_right_child != 0) {
        cBinaryNode->vSetRightChild(pc_right_child);
    } else {
        cBinaryNode->vSetRightChild(pc_default_node);
        // warning();
    }

    if(pc_left_child != 0) {
        cBinaryNode->vSetLeftChild(pc_left_child);
    } else {
        cBinaryNode->vSetLeftChild(pc_default_node);
        // warning();
    }

    return cBinaryNode;
}