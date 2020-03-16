#ifndef _SORT_H_
#define _SORT_H_
#include "SortStats.h"
#include <vector>
template <typename T> class Sort {
public:
  virtual SortStats sort(std::vector<T> &data) = 0;
};
#endif