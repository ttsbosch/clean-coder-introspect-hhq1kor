#pragma once

#include "trade.h"
#include <vector>
#include <string>

class XmlGenerator
{
public:
    static std::string generate(const std::vector<Trade>& trades);
};


