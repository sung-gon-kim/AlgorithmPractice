#include <array>
#include <gtest/gtest.h>

// Pre-defined numbers
static std::array<int, 10> numbers = {3, 2, 1, 10, 4, 5, 7, 6, 9, 8};

/**
 * @brief Add all the numbers in the array S of N numbers
 */
static int sum(std::array<int, 10> array) {
  int result = 0;
  for (int i = 0; i < array.size(); i++) {
    result += array[i];
  }
  return result;
}

TEST(AddArrayMembersTest, testShouldReturnSumOfNumbers) {
  ASSERT_EQ(55, sum(numbers));
}
