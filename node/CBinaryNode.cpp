//
// Created by artur on 05.11.16.
//

#include <iostream>
#include "CBinaryNode.h"

void CBinaryNode::vPrintInfix(std::ostream &cOstream) const {
    cOstream << "(";
    pcGetLeftChild()->vPrintInfix(cOstream);
    cOstream << sGetToken();
    pcGetRightChild()->vPrintInfix(cOstream);
    cOstream << ")";
}
