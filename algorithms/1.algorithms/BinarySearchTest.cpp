#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "TestUtils.hpp"

/**
 * @brief Determine whether X is in the sorted array S of N keys
 *
 * @return location of the number if exists, or -1 otherwise.
 */
static int binsearch(std::vector<int> list, int value)  {
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

TEST(BinarySearchTest, testShouldReturnNegativeWhenNumberNotExist) {
  ASSERT_EQ(-1, binsearch(RandomNumbers(1, 0, 1), 2));
  ASSERT_EQ(-1, binsearch(RandomNumbers(9, 0, 100), 101));
  ASSERT_EQ(-1, binsearch(RandomNumbers(10, 0, 100), 101));
}

TEST(BinarySearchTest, testShouldReturnLocationWhenNumberExist) {
  auto numbers = RandomNumbers(10, 0, 100);

  // Find the low and high numbers and reshuffle the numbers
  std::sort(numbers.begin(), numbers.end());
  int min = numbers.front();
  int max = numbers.back();
  std::random_shuffle(numbers.begin(), numbers.end());
  
  ASSERT_EQ(0, binsearch(numbers, min));
  ASSERT_EQ(9, binsearch(numbers, max));
}
