#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Node.h"
#include <cassert>
#include <cstddef>

template <typename T> class Queue {
public:
  Queue();
  ~Queue();

  void enqueue(T data);
  T dequeue();
  bool is_empty();
  bool is_full();
  void clear();

private:
  Node<T> *m_head;
};

#include "Queue.cpp"
#endif