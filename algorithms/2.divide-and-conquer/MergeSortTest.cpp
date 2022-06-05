#include <iostream>
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "TestUtils.hpp"

/**
 * @brief Merge two sorted arrays into one sorted array.
 */
std::vector<int> merge(const std::vector<int> &first, const std::vector<int> &second) {
  auto result = std::vector<int>();
  std::size_t i = 0;
  std::size_t j = 0;
  
  while (i < first.size() && j < second.size()) {
    if (first[i] < second[j]) {
      result.push_back(first[i]);
      i++;
    } else {
      result.push_back(second[j]);
      j++;
    }
  }
  while (i < first.size()) {
    result.push_back(first[i]);
    i++;
  }
  while (j < second.size()) {
    result.push_back(second[j]);
    j++;
  }
  return result;
}

TEST(MergeSortTest, testShouldReturnSortedList) {
  auto first = RandomNumbers(5, 1, 100);
  std::sort(first.begin(), first.end());
  auto second = RandomNumbers(5, 1, 100);
  std::sort(second.begin(), second.end());

  auto expected = join(first, second);
  std::sort(expected.begin(), expected.end());

  auto result = merge(first, second);
  ASSERT_EQ(expected, result);
}

/**
 * @brief Sort n keys in nondecreasing sequence.
 */
void mergesort(std::vector<int> &numbers) {
  std::size_t middle = numbers.size() / 2;
  if (numbers.size() > 1) {
    std::vector<int> left(numbers.begin(), numbers.begin() + middle);
    std::vector<int> right(numbers.begin() + middle, numbers.end());
    mergesort(left);
    mergesort(right);
    numbers = merge(left, right);
  }
}

TEST(MergeSortTest, testShouldReturnMergeSortedList) {
  auto numbers = RandomNumbers(10, 1, 100);

  auto expected = numbers;
  std::sort(expected.begin(), expected.end());

  mergesort(numbers);

  ASSERT_EQ(expected, numbers);
}
