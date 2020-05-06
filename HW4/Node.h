#ifndef _NODE_H_
#define _NODE_H_
#include <cstddef>

template <typename T> class Queue;
template <typename T> class PriorityQueue;

template <typename T> class Node {
  friend class Queue<T>;
  friend class PriorityQueue<T>;

public:
  Node(T data);
  Node(T data, Node<T> *pnext);
  T &data();
  const T &data() const;
  Node<T> *next() const;

private:
  T m_data;
  Node<T> *m_next;
};
#include "Node.cpp"
#endif