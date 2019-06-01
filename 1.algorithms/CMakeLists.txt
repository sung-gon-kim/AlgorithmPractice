build_test_executable(
  NAME chapter1.bin
  SRCS SequentialSearchTest.cpp AddArrayMembersTest.cpp ExchangeSortTest.cpp
  MatrixMultiplicationTest.cpp BinarySearchTest.cpp FibonacciSequenceTest.cpp
  FindLargestNumberTest.cpp FindSmallestNumberTest.cpp
  PRIVATE_HEADERS "${CMAKE_SOURCE_DIR}/include"
)
