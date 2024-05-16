#pragma once

#include <string>

struct Trade
{
    std::string sourceCurrency;
    std::string destinationCurrency;
    float lots;
    double price;
};
