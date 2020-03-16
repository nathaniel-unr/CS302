#ifndef _CONST_LINKED_LIST_ITER_H_
#define _CONST_LINKED_LIST_ITER_H_
#include "Node.h"

template <typename T> class ConstLinkedListIter {
public:
  ConstLinkedListIter(const Node<T> *cur);
  const Node<T> *current() const;
  void advance();
  void advance_many(size_t n);
  bool is_valid() const;

private:
  const Node<T> *cur;
};
#include "ConstLinkedListIter.cpp"
#endif