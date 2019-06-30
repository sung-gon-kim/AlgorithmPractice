build_test_executable(
  NAME chapter2.bin
  SRCS BinarySearchTest.cpp MergeSortTest.cpp
  PRIVATE_HEADERS "${CMAKE_SOURCE_DIR}/include"
)
