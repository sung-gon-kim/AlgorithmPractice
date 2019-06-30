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
  
inline std::vector<int> join(std::vector<int> first, std::vector<int> second) {
  auto joined = first;
  joined.insert(joined.end(), second.begin(), second.end());
  return joined;
}

  
#endif  // TESTUTILS_HPP_
