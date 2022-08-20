#include "gtest/gtest.h"
#include "../include/fs_exception.h"
#include "../include/ConverterJSON.h"

TEST(AbsoluteDateTestSuite, test1){ // 12/2/2020 -> 737761
    EXPECT_EQ(2, 2);
}

TEST(AbsoluteDateTestSuite, test2) {
    auto dummy = new ConverterJSON();
    EXPECT_EQ(5, dummy->GetResponsesLimit());
}