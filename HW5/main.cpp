#include "BinarySearchTree.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> generate_data(size_t num) {
  std::mt19937 mt(time(0));
  std::uniform_int_distribution<int> distribution(1, 200);

  std::vector<int> ret(num, 0);
  for (size_t i = 0; i < num; i++) {
    int data = 0;
    do {
      data = distribution(mt);
    } while (std::find(ret.begin(), ret.end(), data) != ret.end());
    ret.at(i) = data;
  }

  return ret;
}

template <typename T> void print_list(const std::vector<T> &v) {
  for (size_t i = 0; i < v.size(); i++)
    std::cout << (i + 1) << ") " << v[i] << std::endl;
}

int main() {
  auto data = generate_data(100);
  BinarySearchTree<int> tree;

  std::cout << "Original Data: " << std::endl;
  for (size_t i = 0; i < data.size(); i++) {
    std::cout << data[i] << std::endl;
    tree.add(data[i]);
  }
  std::cout << std::endl;

  std::cout << "Size: " << tree.size() << std::endl;
  std::cout << "Height: " << tree.height() << std::endl;
  std::cout << std::endl;

  auto preorder = tree.to_vec_preorder();

  std::cout << "Preorder: " << std::endl;
  print_list(preorder);
  std::cout << std::endl;

  auto inorder = tree.to_vec_inorder();

  std::cout << "Inorder: " << std::endl;
  print_list(inorder);
  std::cout << std::endl;

  auto postorder = tree.to_vec_postorder();

  std::cout << "Postorder: " << std::endl;
  print_list(postorder);
  std::cout << std::endl;

  return 0;
}