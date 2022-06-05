#include <utility>
#include <gtest/gtest.h>

long calculate(long lbound, long ubound) {
  long i, j, length, maxLength;
  
  if (lbound > ubound) {
    std::swap(lbound, ubound);
  }
  maxLength = 0;
  for (long i = lbound; i <= ubound; i++) {
    j = i;
    length = 1;
    while (j != 1) {
      if (j & 1) {
	j = j * 3 + 1;
	length++;
      }
      while (!(j & 1)) {
	j >>= 1;
	length++;
      }
    }
    if (length > maxLength) {
      maxLength = length;
    }
  }
  return maxLength;
}

TEST(The3n1problem, testCalculate) {
  EXPECT_EQ(20, calculate(1, 10));
  EXPECT_EQ(125, calculate(100, 200));
  EXPECT_EQ(89, calculate(201, 210));
  EXPECT_EQ(174, calculate(900, 1000));
}
