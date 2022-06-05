build_test_program(
  NAME chapter2.bin
  SRCS BinarySearchTest.cpp MergeSortTest.cpp
  PRIVATE_HEADERS "${CMAKE_SOURCE_DIR}/include"
)
