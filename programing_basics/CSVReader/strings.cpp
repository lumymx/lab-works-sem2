#include "strings.h"
#include <cstring>

char* charPtrToLower(char* str) {
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
    return str;
}

std::string stringToLower(std::string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    return str;
}
