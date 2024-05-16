#pragma once

#include "trade.h"
#include <istream>
#include <vector>

class TradeProcessor
{
public:
    std::vector<Trade> processTrades(std::istream& stream);
};