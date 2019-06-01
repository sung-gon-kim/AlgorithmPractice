#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "TestUtils.hpp"

/**
 * @brief Find the smallest number in a list
 */
inline int findMin(const std::vector<int>& numbers) {
  int min = numbers[0];
  for (const auto& number : numbers) {
    if (number < min) {
      min = number;
    }
  }
  return min;
}

TEST(FindSmallestNumberTest, returnSmallestNumber) {
  auto numbers = RandomNumbers(10, 0, 100);
  int expected = *std::min_element(numbers.begin(), numbers.end());
  ASSERT_EQ(expected, findMin(numbers));
}
