template <typename T>
#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
class QuickSort : public Sort<T> {
public:
  virtual SortStats sort(std::vector<T> &data) {
    SortStats stats;
    auto start = std::chrono::high_resolution_clock::now();

    sort_inner(data, 0, data.size() - 1, stats);
    auto end = std::chrono::high_resolution_clock::now();
    stats.cpu_time = end - start;
    return stats;
  }

private:
  void sort_inner(std::vector<T> &data, size_t low, size_t high,
                  SortStats &stats) {
    if (low < high) {
      size_t part = partition(data, low, high, stats);
      if (part != 0) // Prevent Overflow
        sort_inner(data, low, part - 1, stats);
      sort_inner(data, part + 1, high, stats);
    }
  }

  size_t partition(std::vector<T> &data, size_t low, size_t high,
                   SortStats &stats) {

    T pivot = data.at(high);
    size_t i = low - 1;
    for (size_t j = low; j < high; j++) {
      stats.comparisons += 1;
      if (data.at(j) < pivot) {
        stats.swaps += 1;
        i++;
        std::swap(data.at(i), data.at(j));
      }
    }
    stats.swaps += 1;
    std::swap(data.at(i + 1), data.at(high));
    return i + 1;
  }
};
#endif