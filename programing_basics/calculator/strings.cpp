#include "./strings.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <unordered_map>

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

double stringToDouble(std::string str) {
    double num;
    std::istringstream iss(str);
    iss >> num;
    return num;
}

std::string labelToFunction(std::string label) {
    std::unordered_map<std::string, std::string> function_map {
        {"SIN", "sin"},
        {"COS", "cos"},
        {"TAN", "tan"},
        {"COT", "cot"},
        {"√", "sqrt"}
    };

    auto iter = function_map.find(label);
    if (iter == function_map.end())
        return "unknown_function";

    return iter->second;
}
