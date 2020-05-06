#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_
#include "BinaryNode.h"
#include <memory>
#include <vector>

template <typename T> class BinarySearchTree {
public:
  BinarySearchTree();
  BinarySearchTree(T data);

  bool add(T data);
  bool is_empty();
  size_t size();
  size_t height();
  void clear();

  std::vector<T> to_vec_preorder();
  std::vector<T> to_vec_inorder();
  std::vector<T> to_vec_postorder();

private:
  SharedBinaryNode<T> root;
};

#include "BinarySearchTree.cpp"
#endif