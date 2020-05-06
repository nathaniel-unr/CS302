#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> generate_data(size_t num) {
  std::mt19937 mt(time(0));
  std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

  std::vector<int> ret(num);
  for (size_t i = 0; i < num; i++) {
    ret.at(i) = distribution(mt);
  }

  return ret;
}

int get_avg(std::vector<int> &data) {
  float acc = 0;
  for (size_t i = 0; i < data.size(); i++)
    acc += data[i];
  return acc / data.size();
}

int main() {
  std::vector<int> data = generate_data(100);
  make_heap(data.begin(), data.end());

  std::cout << "Heap initalized with values: " << std::endl;
  for (size_t i = 0; i < data.size(); i++)
    std::cout << data[i] << std::endl;
  std::cout << std::endl;

  int avg = get_avg(data);

  std::cout << "Calculated Average: " << avg << std::endl;

  data.push_back(avg);
  push_heap(data.begin(), data.end());

  pop_heap(data.begin(), data.end());
  int removed = data.back();
  data.pop_back();

  std::cout << "Largest entry in heap (removed): " << removed << std::endl << std::endl;

  sort_heap(data.begin(), data.end());
  
  std::cout << "Heap Sorted: " << std::endl;
  for (size_t i = 0; i < data.size(); i++)
    std::cout << data[i] << std::endl;
  std::cout << std::endl;
  
  return 0;
}