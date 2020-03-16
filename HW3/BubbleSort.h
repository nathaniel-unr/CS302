#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_
#include "Sort.h"
template <typename T> class BubbleSort : public Sort<T> {
public:
  virtual SortStats sort(std::vector<int> &data) {
    SortStats stats;
    auto start = std::chrono::high_resolution_clock::now();
    bool has_swapped = true;
    while (has_swapped) {
      has_swapped = false;
      for (size_t i = 0; i < data.size() - 1; i++) {
        stats.comparisons += 1;
        if (data.at(i) > data.at(i + 1)) {
          stats.swaps += 1;
          std::swap(data.at(i), data.at(i + 1));
          has_swapped = true;
        }
      }
    }
    auto end = std::chrono::high_resolution_clock::now();
    stats.cpu_time = end - start;
    return stats;
  }
};
#endif