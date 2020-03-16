#ifndef _NODE_H_
#define _NODE_H_
#include <cstddef>

template <typename T> class Stack;

template <typename T> class Node {
  friend class Stack<T>;

public:
  Node(const T &item);
  Node(const T &item, Node<T> *pnext);

  T &data();
  Node<T> *next();

private:
  Node<T> *pnext;
  T m_data;
};
#include "Node.cpp"
#endif