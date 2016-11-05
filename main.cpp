
#include "CParser.h"

int main() {
    CParser c_parser;
    CTree* c_tree = c_parser.vParse("1 2 + *");

    CInfix c_infix = c_tree->cToInfix();
    CInfix::iterator c_beg = c_infix.begin();
    CInfix::iterator c_end = c_infix.end();

    while(c_beg != c_end) {
        std::cout << *c_beg++ << " ";
    }



    CDefinedVariables c_def_vars;
    std::cout << c_tree->iEvaluate(c_def_vars) << std::endl;

    CVariables c_vars = c_tree->sGetVars();
    CVariables::const_iterator c_v_beg = c_vars.begin();
    CVariables::const_iterator c_v_end = c_vars.end();

    //while(c_v_beg != c_v_end)
      //  std::cout << *c_beg++ << std::endl;

    return 0;
}