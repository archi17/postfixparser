//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_CLOGENTRY_H
#define POSTFIXPARSER_CLOGENTRY_H

#include <string>

enum CLevel { LEVEL_WARNING, LEVEL_ERROR };

class CLogEntry {
public:
    CLogEntry(CLevel cLevel, int iPos);

private:
    const CLevel c_level;
    const int i_pos;
};


#endif //POSTFIXPARSER_CLOGENTRY_H
