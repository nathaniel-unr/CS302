#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_
#include <memory>

template <typename T> class BinaryNode {
public:
  BinaryNode(T data);

  T &data();

  std::shared_ptr<BinaryNode<T>> left();
  std::shared_ptr<BinaryNode<T>> right();

  void set_left(std::shared_ptr<BinaryNode<T>> node);
  void set_right(std::shared_ptr<BinaryNode<T>> node);

  bool has_left();
  bool has_right();

  size_t size();
  size_t height();

private:
  std::shared_ptr<BinaryNode<T>> m_left;
  std::shared_ptr<BinaryNode<T>> m_right;
  T m_data;

  size_t size_left();
  size_t size_right();
};

template <typename T> using SharedBinaryNode = std::shared_ptr<BinaryNode<T>>;

#include "BinaryNode.cpp"
#endif