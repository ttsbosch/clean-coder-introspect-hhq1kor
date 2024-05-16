#include "processor.h"
#include "trade_processor.h"
#include "xml_generator.h"
#include <iostream>
#include <fstream>

void Processor::process(std::istream& stream)
{
    TradeProcessor tradeProcessor;
    std::vector<Trade> trades = tradeProcessor.processTrades(stream);

    std::string xmlData = XmlGenerator::generate(trades);
    std::ofstream outFile("output.xml");
    outFile << xmlData;

    std::cout << "INFO: " << trades.size() << " trades processed" << std::endl;
}
