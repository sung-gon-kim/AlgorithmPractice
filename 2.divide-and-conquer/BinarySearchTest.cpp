#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "TestUtils.hpp"

/**
 * @brief Determine whether X is in the sorted array S of N keys
 */
inline int binsearch(std::vector<int> list, int value) {
  std::sort(list.begin(), list.end());
  
  int low = 0;
  int mid = 0;
  int high = list.size() - 1;
  int location = -1;
  
  while (low <= high && location == -1) {
    mid = (low + high) / 2;
    if (value == list[mid]) {
      location = mid;
    } else if (value < list[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return location;
}

TEST(BinarySearchTest, shouldReturnNegativeWhenNumberNotFound) {
  auto numbers = RandomNumbers(10, 1, 100);
  ASSERT_EQ(-1, binsearch(numbers, 0));
  ASSERT_EQ(-1, binsearch(numbers, 101));
}

TEST(BinarySearchTest, shouldReturnLocationWhennumberFound) {
  auto numbers = RandomNumbers(10, 1, 100);
  int min = *std::min_element(numbers.begin(), numbers.end());
  int max = *std::max_element(numbers.begin(), numbers.end());
  ASSERT_NE(-1, binsearch(numbers, min));
  ASSERT_NE(-1, binsearch(numbers, max));
}
