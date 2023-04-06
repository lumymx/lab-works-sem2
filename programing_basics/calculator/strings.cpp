#include "./strings.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

std::string doubleToString(double number, int limit) {
    std::stringstream ss;
    ss.precision(limit);
    ss << std::fixed << number;
    std::string str = ss.str();

    if (number == static_cast<int>(number))
        str.erase(str.find('.'));
    else if (str.length() > limit) {
        std::string::size_type dot_pos = str.find('.');
        if (dot_pos == std::string::npos)
            dot_pos = str.length();
        std::string::size_type e_pos = str.find('e');
        if (e_pos != std::string::npos && e_pos > dot_pos) {
            int exp = std::stoi(str.substr(e_pos+1));
            if (exp >= 0 && exp < 3)
                str.erase(e_pos);
        }
        str.erase(limit);
    }

    return str;
}

std::string labelToFunction(std::string label) {
    std::string function = "";
    if (label == "SIN")
        function = "sin";
    else if (label == "COS")
        function = "cos";
    else if (label == "TAN")
        function = "tan";
    else if (label == "COT")
        function = "cot";
    else if (label == "√")
        function = "sqrt";
    return function;
}
