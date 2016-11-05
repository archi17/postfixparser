//
// Created by artur on 04.11.16.
//

#ifndef POSTFIXPARSER_UTILS_H
#define POSTFIXPARSER_UTILS_H

#include <string>
#include <sstream>

inline std::string sToString(char chChar) {
    return std::string(1, chChar);
}

inline std::string sToString(const std::string& sString, int iBeg, int iEnd) {
    return sString.substr(iBeg, iEnd - iBeg);
}

inline int iToInt(const std::string& sString) {
    std::istringstream c_isstream(sString);
    int i_n;
    c_isstream >> i_n;
    return i_n;
}

#endif //POSTFIXPARSER_UTILS_H
