#include "BubbleSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "Sort.h"
#include <cassert>
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <time.h>

const int RAND_VAL_UPPER_LIMIT = 1000000;
const int STAT_TIME = 0;
const int STAT_COMP = 1;
const int STAT_SWAP = 2;

std::vector<int> generate_data(size_t num) {
  std::mt19937 mt(time(0));
  std::uniform_int_distribution<int> distribution(0, RAND_VAL_UPPER_LIMIT);

  std::vector<int> ret(num);
  for (size_t i = 0; i < num; i++) {
    ret.at(i) = distribution(mt);
  }

  return ret;
}

void print_stats(SortStats &stats) {
  std::cout << "Comparisons: " << stats.comparisons << std::endl;
  std::cout << "Swaps: " << stats.swaps << std::endl;
  std::cout << "Cpu Time: " << stats.cpu_time.count() << "ms" << std::endl;
}

bool write_data(const char *path, std::vector<int> &data) {
  std::ofstream file;
  file.open(path);
  if (!file)
    return false;

  for (size_t i = 0; i < data.size(); i++)
    file << data.at(i) << '\n';

  return true;
}

void generate_data_family(size_t size, const char *family_name) {
  QuickSort<int> quicksort;

  std::string unsorted_name("list_");
  unsorted_name += family_name;
  unsorted_name += "_unsorted.txt";

  std::string sorted_name("list_");
  sorted_name += family_name;
  sorted_name += "_sorted.txt";

  std::cout << "Generating " << family_name << " Data..." << std::endl;
  auto list = generate_data(size);

  std::cout << "Writing '" << unsorted_name << "'..." << std::endl;
  if (!write_data(unsorted_name.c_str(), list))
    std::cout << "Failed to write '" << unsorted_name << "'!" << std::endl;

  std::cout << "Sorting " << family_name << " Data..." << std::endl;
  quicksort.sort(list);

  std::cout << "Writing '" << sorted_name << "'..." << std::endl;
  if (!write_data(sorted_name.c_str(), list))
    std::cout << "Failed to write '" << sorted_name << "'!" << std::endl;

  std::cout << std::endl;
}

void generate_files() {
  generate_data_family(1000, "1k");
  generate_data_family(10000, "10k");
  generate_data_family(100000, "100k");
}

template <typename T>
std::vector<SortStats> bench(Sort<T> &algo, const std::vector<T> &data) {
  std::vector<SortStats> stats(10);

  for (size_t i = 0; i < 10; i++) {
    std::vector<T> data_clone(data);
    stats.at(i) = algo.sort(data_clone);
  }

  return stats;
}

std::vector<int> load_file(const char *path) {
  std::ifstream file;
  std::vector<int> ret;
  int val = 0;

  file.open(path);
  if (!file)
    return ret;

  while (file >> val)
    ret.push_back(val);

  return ret;
}

void write_results(const char *name, const char *title, int stat,
                   std::vector<SortStats> &small, std::vector<SortStats> &mid,
                   std::vector<SortStats> &large) {
  std::ofstream file;
  std::string filename(name);
  filename += "_";
  filename += title;
  filename += ".csv";
  file.open(filename);
  if (!file)
    return;

  file << name << ": " << title << std::endl
       << ",1000,10000,100000" << std::endl;
  for (size_t i = 0; i < small.size(); i++) {
    switch (stat) {
    case STAT_TIME:
      file << (i + 1) << "," << small.at(i).cpu_time.count() << ","
           << mid.at(i).cpu_time.count() << "," << large.at(i).cpu_time.count()
           << std::endl;
      break;
    case STAT_SWAP:
      file << (i + 1) << "," << small.at(i).swaps << "," << mid.at(i).swaps
           << "," << large.at(i).swaps << std::endl;
      break;
    case STAT_COMP:
      file << (i + 1) << "," << small.at(i).comparisons << ","
           << mid.at(i).comparisons << "," << large.at(i).comparisons
           << std::endl;
      break;
    }
  }
}

void export_stats(Sort<int> &algo, const char *name) {
  std::vector<int> data_1k_unsorted = load_file("list_1k_unsorted.txt");
  std::vector<int> data_1k_sorted = load_file("list_1k_sorted.txt");

  std::vector<int> data_10k_unsorted = load_file("list_10k_unsorted.txt");
  std::vector<int> data_10k_sorted = load_file("list_10k_sorted.txt");

  std::vector<int> data_100k_unsorted = load_file("list_100k_unsorted.txt");
  std::vector<int> data_100k_sorted = load_file("list_100k_sorted.txt");

  assert(data_1k_sorted.size() != 0);

  auto data_1k_unsorted_results = bench<int>(algo, data_1k_unsorted);
  auto data_1k_sorted_results = bench<int>(algo, data_1k_sorted);

  auto data_10k_unsorted_results = bench<int>(algo, data_10k_unsorted);
  auto data_10k_sorted_results = bench<int>(algo, data_10k_sorted);

  auto data_100k_unsorted_results = bench<int>(algo, data_100k_unsorted);
  auto data_100k_sorted_results = bench<int>(algo, data_100k_sorted);

  write_results(name, "Worst_Cpu_Time", STAT_TIME, data_1k_unsorted_results,
                data_10k_unsorted_results, data_100k_unsorted_results);

  write_results(name, "Best_Cpu_Time", STAT_TIME, data_1k_sorted_results,
                data_10k_sorted_results, data_100k_sorted_results);

  write_results(name, "Worst_Comparisons", STAT_COMP, data_1k_unsorted_results,
                data_10k_unsorted_results, data_100k_unsorted_results);

  write_results(name, "Best_Comparisons", STAT_COMP, data_1k_sorted_results,
                data_10k_sorted_results, data_100k_sorted_results);

  write_results(name, "Worst_Swaps", STAT_SWAP, data_1k_unsorted_results,
                data_10k_unsorted_results, data_100k_unsorted_results);

  write_results(name, "Best_Swaps", STAT_SWAP, data_1k_sorted_results,
                data_10k_sorted_results, data_100k_sorted_results);
}

int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "gen-files") == 0) {
    generate_files();
    return 0;
  }

  QuickSort<int> quicksort;
  SelectionSort<int> selection_sort;
  BubbleSort<int> bubble_sort;

  export_stats(bubble_sort, "Bubblesort");
  export_stats(selection_sort, "Selectionsort");
  export_stats(quicksort, "Quicksort");

  return 0;
}