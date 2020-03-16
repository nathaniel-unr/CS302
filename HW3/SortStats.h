#ifndef _SORT_STATS_H_
#define _SORT_STATS_H_
#include <chrono>
#include <cstddef>
struct SortStats {
  size_t comparisons = 0;
  size_t swaps = 0;
  std::chrono::duration<double, std::milli> cpu_time =
      std::chrono::duration<double, std::milli>::zero();
};
#endif