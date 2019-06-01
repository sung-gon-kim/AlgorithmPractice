#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "TestUtils.hpp"

/**
 * @brief Find the largest number in a list
 */
inline int findMax(const std::vector<int>& numbers) {
  int max = numbers[0];
  for (const auto& number : numbers) {
    if (max < number) {
      max = number;
    }
  }
  return max;
}

TEST(FindLargestNumberTest, returnLargestNumber) {
  auto numbers = RandomNumbers(10, 0, 100);
  int expected = *std::max_element(numbers.begin(), numbers.end());
  ASSERT_EQ(expected, findMax(numbers));
}
