#ifndef _STACK_H_
#define _STACK_H_
#include "Node.h"
#include <assert.h>
#include <iostream>
template <typename T> class Stack {
public:
  Stack();
  Stack(const Stack<T> &other);
  Stack<T> &operator=(const Stack<T> &rhs);
  ~Stack();

  void push(const T &item);
  T peek();
  void pop();
  void clear();
  bool isEmpty();
  bool isFull();

private:
  Node<T> *ptop;

  void from_stack(const Stack<T> &other);
};

#include "Stack.cpp"
#endif
//