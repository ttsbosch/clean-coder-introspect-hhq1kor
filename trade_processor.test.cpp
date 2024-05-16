#include <gtest/gtest.h>
#include "trade_processor.h"

TEST(ProcessTradesTest, ValidInput) {
    TradeProcessor processor;
    std::istringstream input("EURUSD,100000,1.23456\nUSDJPY,50000,109.123\n");
    std::vector<Trade> trades = processor.processTrades(input);
    ASSERT_EQ(trades.size(), 2);
    EXPECT_EQ(trades[0].sourceCurrency, "EUR");
    EXPECT_EQ(trades[0].destinationCurrency, "USD");
    EXPECT_FLOAT_EQ(trades[0].lots, 1.0f);
    EXPECT_DOUBLE_EQ(trades[0].price, 1.23456);
    
}