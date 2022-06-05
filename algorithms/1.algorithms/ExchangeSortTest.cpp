#include <array>
#include <utility>
#include <gtest/gtest.h>

// Pre-defined numbers
static std::array<int, 10> numbers = {3, 2, 1, 10, 4, 5, 7, 6, 9, 8};

/**
 * @brief Sort N keys in nondecreasing order
 */
static void exchangeSort(std::array<int, 10>& array) {
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = i + 1; j < array.size(); j++) {
      if (array[i] > array[j]) {
	std::swap(array[i], array[j]);
      }
    }
  }
}

TEST(ExchangeSortTest, testShouldBeSortedInAscendingOrder) {
  std::array<int, 10> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  exchangeSort(numbers);
  ASSERT_EQ(expected, numbers);
}
