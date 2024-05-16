#include "trade_processor.h"
#include "string_utils.h"
#include <iostream>
#include <stdexcept>
#include <vector>

const float LotSize = 100000;

std::vector<Trade> TradeProcessor::processTrades(std::istream& stream)
{
    std::vector<Trade> trades;
    std::string line;
    int lineCount = 1;

    while (std::getline(stream, line))
    {
        std::vector<std::string> fields = StringUtils::split(line, ',');
        if (fields.size() != 3)
        {
            std::cout << "WARN: Line " << lineCount << " malformed. Only " << fields.size() << " field(s) found." << std::endl;
            continue;
        }
        if (fields[0].length() != 6)
        {
            std::cout << "WARN: Trade currencies on line " << lineCount << " malformed: '" << fields[0] << "'" << std::endl;
            continue;
        }
        int tam;
        if (!StringUtils::tryParseInt(fields[1], tam))
        {
            std::cout << "WARN: Trade amount on line " << lineCount << " not a valid integer: '" << fields[1] << "'" << std::endl;
            continue;
        }
        double tp;
        if (!StringUtils::tryParseDouble(fields[2], tp))
        {
            std::cout << "WARN: Trade price on line " << lineCount << " not a valid decimal: '" << fields[2] << "'" << std::endl;
            continue;
        }

        Trade trade;
        trade.sourceCurrency = fields[0].substr(0, 3);
        trade.destinationCurrency = fields[0].substr(3, 3);
        trade.lots = tam / LotSize;
        trade.price = tp;
        trades.push_back(trade);
        lineCount++;
    }
    return trades;
}
