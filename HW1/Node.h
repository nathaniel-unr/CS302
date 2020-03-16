#ifndef _NODE_H_
#define _NODE_H_
#include <cstddef>
template <typename T> class LinkedList;

template <typename T> class Node {
  friend class LinkedList<T>;

public:
  Node(T data);
  Node(T data, Node<T> *pnext);
  T &data();
  const T &data() const;
  Node<T> *next() const;

private:
  T m_data;
  Node<T> *pnext;
};
#include "Node.cpp"
#endif