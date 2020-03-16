template <typename T>
ConstLinkedListIter<T>::ConstLinkedListIter(const Node<T> *cur) : cur(cur) {}
template <typename T> const Node<T> *ConstLinkedListIter<T>::current() const {
  return cur;
}
template <typename T> void ConstLinkedListIter<T>::advance() {
  cur = cur->next();
}
template <typename T> void ConstLinkedListIter<T>::advance_many(size_t n) {
  for (size_t i = 0; i < n && is_valid(); i++, advance()) {
  }
}
template <typename T> bool ConstLinkedListIter<T>::is_valid() const {
  return cur != NULL;
}