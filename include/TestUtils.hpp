#ifndef TESTUTILS_HPP_
#define TESTUTILS_HPP_

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

inline std::vector<int> RandomNumbers(std::size_t size, int lowerBound, int upperBound) {
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine dre(seed);
  std::uniform_int_distribution<int> di(lowerBound, upperBound);
  
  std::vector<int> vec(size);
  std::generate(vec.begin(), vec.end(), [&]{ return di(dre); });
  return vec;
}

#endif  // TESTUTILS_HPP_
