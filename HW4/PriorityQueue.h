#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
#include "Node.h"
#include <cassert>
#include <iostream>

template <typename T> class PriorityQueue {
public:
  PriorityQueue();
  ~PriorityQueue();

  void enqueue(T data);
  T dequeue();
  bool is_empty();
  bool is_full();
  void clear();

private:
  Node<T> *m_head;
};

#include "PriorityQueue.cpp"
#endif