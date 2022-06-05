#include <gtest/gtest.h>

#define SIZE 2

static int first[SIZE][SIZE] = {{2, 3}, {4, 1}};
static int second[SIZE][SIZE] = {{5, 7}, {6, 8}};

/**
 * @brief Determine the product of two N * N matrices
 */
static void matrixmult(int size, const int A[SIZE][SIZE], const int B[SIZE][SIZE], int C[SIZE][SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[i][j] = 0;
      for (int k = 0; k < size; k++) {
	C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
    }
  }
}

TEST(MatrixMultiplicationTest, testShouldReturnProductOfTwoMatrices) {
  int expected[SIZE][SIZE] = {{28, 38}, {26, 36}};
  int actual[SIZE][SIZE];
  matrixmult(SIZE, first, second, actual);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      ASSERT_EQ(expected[i][j], actual[i][j]);
    }
  }
}
