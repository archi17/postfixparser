//
// Created by artur on 03.11.16.
//

#include "CParser.h"

CTree* CParser::pcParse(const std::string &sExpression) {
    c_errors.clear();
    i_pos = sExpression.length() - 1;
    s_expression = sExpression;
    CTree *c_tree = new CTree(pc_parse_expression());

    if(e_symbol == S_ERROR || i_pos >= 0) {
        EErrorType e_error_type = e_symbol == S_ERROR ? ERR_ILLEGAL_SYMBOL : ERR_UNEXPECTED_SYMBOL;
        v_skip(S_WHITESPACE);
        v_error(e_error_type, i_pos);
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
            c_tilde_node->vSetLeftChild(pc_parse_or_default());
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

CNode* CParser::pc_parse_or_default() {
    CNode *pc_child = pc_parse_expression();
    if(pc_child == 0) {
        pc_child = new CNumNode("1");
        v_error(ERR_MISSING_OPERAND, i_pos + 1);
    }
    return pc_child;
}

CBinaryNode* CParser::pc_parse_children(CBinaryNode* cBinaryNode) {
    cBinaryNode->vSetRightChild(pc_parse_or_default());
    cBinaryNode->vSetLeftChild(pc_parse_or_default());

    return cBinaryNode;
}

void CParser::v_error(EErrorType eErrorType, long iPos) {
    c_errors.push_back(CError(eErrorType, iPos));
}
