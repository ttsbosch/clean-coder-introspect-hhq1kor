#include "string_utils.h"
#include <sstream>
#include <stdexcept>
#include <vector>

std::vector<std::string> StringUtils::split(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool StringUtils::tryParseInt(const std::string& str, int& value)
{
    try
    {
        value = std::stoi(str);
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}

bool StringUtils::tryParseDouble(const std::string& str, double& value)
{
    try
    {
        value = std::stod(str);
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}
