cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)

project(
  Algorithms
  VERSION 0.0.1
  LANGUAGES CXX
  DESCRIPTION "Algorithm Practices"
)

# Output the compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable C++11 standard options
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Load CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
include(BuildModules)

enable_testing()

# Read sub-directories
add_subdirectory(1.algorithms)
