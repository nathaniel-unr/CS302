#ifndef _LINKED_LIST_ITER_H_
#define _LINKED_LIST_ITER_H_
#include "Node.h"
template <typename T> class LinkedListIter {
public:
  LinkedListIter(Node<T> *cur);
  Node<T> *current();
  const Node<T> *current() const;
  void advance();
  void advance_many(size_t n);
  bool is_valid() const;

private:
  Node<T> *cur;
};
#include "LinkedListIter.cpp"
#endif