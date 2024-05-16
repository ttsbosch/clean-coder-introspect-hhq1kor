#pragma once

#include <string>
#include <vector>

class StringUtils
{
public:
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static bool tryParseInt(const std::string& str, int& value);
    static bool tryParseDouble(const std::string& str, double& value);
};


