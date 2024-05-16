#include <gtest/gtest.h>
#include "string_utils.h"

TEST(SplitStringTest, SimpleString) {
    std::vector<std::string> tokens = StringUtils::split("EURUSD,100000,1.23456", ',');
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], "EURUSD");
    EXPECT_EQ(tokens[1], "100000");
    EXPECT_EQ(tokens[2], "1.23456");
}


TEST(IntGetFromStringTest, ValidInteger) {
    int value;
    ASSERT_TRUE(StringUtils::tryParseInt("123", value));
    EXPECT_EQ(value, 123);
}

TEST(IntGetFromStringTest, InvalidInteger) {
    int value;
    ASSERT_FALSE(StringUtils::tryParseInt("abc", value));
}


TEST(ToDoubleTest, ValidDouble) {
    double value;
    ASSERT_TRUE(StringUtils::tryParseDouble("3.14159", value));
    EXPECT_DOUBLE_EQ(value, 3.14159);
}

TEST(ToDoubleTest, InvalidDouble) {
    double value;
    ASSERT_FALSE(StringUtils::tryParseDouble("abc", value));
}