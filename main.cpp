
#include "CParser.h"

class PrintVisitor : public INodeVisitor {
public:
    void vVisit(const CNode* pcNode) {
        std::cout << *(pcNode->pcGetToken());
    }
};

int main() {
    CParser c_parser;
    CNode* c_node = c_parser.vParse("x f ab+*");
    c_node->vVisitInOrder(new PrintVisitor);

    return 0;
}