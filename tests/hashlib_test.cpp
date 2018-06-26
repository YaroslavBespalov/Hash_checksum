#include "gtest/gtest.h"
#include "hash.h"

TEST(calcutale_sum32, generic)
{
    std::stringstream stream(std::string{1, 0, 0, 127, 0, 2});
    uint32_t res = calcutale_sum32(stream);
    EXPECT_EQ(static_cast<uint32_t>(16777343+131072), res);
}

TEST(calcutale_sum32, zero)
{
    std::stringstream stream(std::string{});
    uint32_t res = calcutale_sum32(stream);
    EXPECT_EQ(static_cast<uint32_t>(0), res);
}

TEST(calculate_crc32, generic)
{
    std::stringstream stream(std::string{8, 4, 7, 1, 2, 6, 123, 5}); //08 04 07 01 02 06 7B 05
    uint32_t res = calculate_crc32(stream);
    // crc32 calculated here: https://www.lammertbies.nl/comm/info/crc-calculation.html
    EXPECT_EQ(static_cast<uint32_t>(0x70C8194C), res);
}

TEST(calculate_crc32, zero)
{
    std::stringstream stream(std::string{});
    uint32_t res = calculate_crc32(stream);
    EXPECT_EQ(static_cast<uint32_t>(0), res);
}

