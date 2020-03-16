template <typename T>
LinkedListIter<T>::LinkedListIter(Node<T> *cur) : cur(cur) {}
template <typename T> Node<T> *LinkedListIter<T>::current() { return cur; }
template <typename T> const Node<T> *LinkedListIter<T>::current() const {
  return cur;
}
template <typename T> void LinkedListIter<T>::advance() { cur = cur->next(); }
template <typename T> void LinkedListIter<T>::advance_many(size_t n) {
  for (size_t i = 0; i < n && is_valid(); i++, advance()) {
  }
}
template <typename T> bool LinkedListIter<T>::is_valid() const {
  return cur != NULL;
}