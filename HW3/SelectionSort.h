#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_
#include "Sort.h"
template <typename T> class SelectionSort : public Sort<T> {
public:
  virtual SortStats sort(std::vector<T> &data) {
    SortStats stats;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < data.size() - 1; i++) {
      size_t smallest_index = i;

      for (size_t j = i + 1; j < data.size(); j++) {
        stats.comparisons += 1;
        if (data.at(j) < data.at(smallest_index))
          smallest_index = j;
      }

      if (i != smallest_index) {
        stats.swaps += 1;
        std::swap(data.at(i), data.at(smallest_index));
      }
    }
    auto end = std::chrono::high_resolution_clock::now();

    stats.cpu_time = end - start;
    return stats;
  }
};
#endif