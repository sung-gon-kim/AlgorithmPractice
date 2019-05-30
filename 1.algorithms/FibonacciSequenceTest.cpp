#include <gtest/gtest.h>

/**
 * @brief Determine the Nth term in the Fibonacci Sequence (Recursive)
 */
static int fibonacci1(int n) {
  return (n <= 1) ? n : fibonacci1(n - 1) + fibonacci1(n - 2);
}

static int fibonacci2(int n) {
  std::vector<int> values(n + 1, 0);
  values[0] = 0;
  if (n > 0) {
    values[1] = 1;
    for (int i = 2; i <= n; i++) {
      values[i] = values[i - 1] + values[i - 2];
    }
  }
  return values[n];
}

TEST(FibonacciSequenceTest, recursiveFibonacciSequence) {
  std::vector<int> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  for (int i = 0; i < expected.size(); i++) {
    ASSERT_EQ(expected[i], fibonacci1(i));
  }
}

TEST(FibonacciSequenceTest, iterativeFibonacciSequence) {
  std::vector<int> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  for (int i = 0; i < expected.size(); i++) {
    ASSERT_EQ(expected[i], fibonacci2(i));
  }
}
