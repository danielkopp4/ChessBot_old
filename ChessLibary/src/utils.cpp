#include "utils.hpp"

char tolower(char c) {
    if (std::isupper(c)) {
        return char(c + 32);
    }
                
    return c;
}

std::string tolower(std::string& string) {
    std::stringstream ss;
    for (unsigned int i = 0; i < string.length(); i++) {
        ss << tolower(string[i]);
    }

    return ss.str();
}