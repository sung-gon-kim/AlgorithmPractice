#include <array>
#include <gtest/gtest.h>

// Pre-defined numbers
static std::array<int, 10> numbers = {3, 2, 1, 10, 4, 5, 7, 6, 9, 8};

/**
 * @brief Is the key X in the array S of N keys?
 */
static int seqsearch(std::array<int, 10> array, int needle) {
  int location = 0;
  while (location < array.size() && array[location] != needle) {
    ++location;
  }
  return (location >= array.size()) ? -1 : location;
}

TEST(SequentialSearchTest, testShouldReturnNegativeIfNumberNotExistsInArray) {
  ASSERT_EQ(-1, seqsearch(numbers, 100));
}

TEST(SequentialSearchTest, testShouldReturnLocationOfXIfExistsInArray) {
  ASSERT_EQ(6, seqsearch(numbers, 7));
}
