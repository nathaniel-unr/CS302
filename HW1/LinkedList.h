#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "ConstLinkedListIter.h"
#include "LinkedListIter.h"
#include "Node.h"

template <typename T> class LinkedList {
  friend class Node<T>;

public:
  LinkedList();
  LinkedList(const LinkedList &other);
  ~LinkedList();

  LinkedList<T> &operator=(const LinkedList<T> &rhs);

  size_t size() const;

  void push_front(T data);
  void push_front(Node<T> *data);

  void push_end(T data);
  void push_end(Node<T> *data);

  Node<T> *pop_front();
  Node<T> *pop_end();

  Node<T> *get(size_t target);
  const Node<T> *get(size_t target) const;

  bool insert(size_t target_index, T data);

  Node<T> *find(const Node<T> *start, T target);
  const Node<T> *find(const Node<T> *start, T target) const;

  Node<T> *remove(size_t target_index);

  void clear();
  bool is_empty() const;

  LinkedListIter<T> iter();
  ConstLinkedListIter<T> iter() const;

  Node<T> *operator[](size_t pos);
  const Node<T> *operator[](size_t pos) const;

  Node<T> *first();
  const Node<T> *first() const;

  Node<T> *last();
  const Node<T> *last() const;

private:
  Node<T> *pfirst;
  Node<T> *plast;

  void copy_from(const LinkedList<T> &other);
};

#include "LinkedList.cpp"
#endif