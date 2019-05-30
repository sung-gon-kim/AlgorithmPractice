build_test_executable(
  NAME chapter1.bin
  SRCS SequentialSearchTest.cpp AddArrayMembersTest.cpp ExchangeSortTest.cpp
  MatrixMultiplicationTest.cpp BinarySearchTest.cpp FibonacciSequenceTest.cpp
  PRIVATE_HEADERS "${CMAKE_SOURCEE_DIR}/1.algorithms"
)
