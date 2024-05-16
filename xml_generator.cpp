#include "xml_generator.h"
#include <sstream>

std::string XmlGenerator::generate(const std::vector<Trade>& trades)
{
    std::ostringstream xStream;
    xStream << "<TradeRecords>" << std::endl;
    for (const auto& trade : trades) 
    {
        xStream << "\t<TradeRecord>" << std::endl;
        xStream << "\t\t<SourceCurrency>" << trade.sourceCurrency << "</SourceCurrency>" << std::endl;
        xStream << "\t\t<DestinationCurrency>" << trade.destinationCurrency << "</DestinationCurrency>" << std::endl;
        xStream << "\t\t<Lots>" << trade.lots << "</Lots>" << std::endl;
        xStream << "\t\t<Price>" << trade.price << "</Price>" << std::endl;
        xStream << "\t</TradeRecord>" << std::endl;
    }
    xStream << "</TradeRecords>";
    return xStream.str();
}
