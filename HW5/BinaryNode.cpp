template <typename T> BinaryNode<T>::BinaryNode(T data) : m_data(data) {}

template <typename T> T &BinaryNode<T>::data() { return m_data; }

template <typename T> std::shared_ptr<BinaryNode<T>> BinaryNode<T>::left() {
  return m_left;
}

template <typename T> std::shared_ptr<BinaryNode<T>> BinaryNode<T>::right() {
  return m_right;
}

template <typename T>
void BinaryNode<T>::set_left(std::shared_ptr<BinaryNode<T>> node) {
  m_left = node;
}

template <typename T>
void BinaryNode<T>::set_right(std::shared_ptr<BinaryNode<T>> node) {
  m_right = node;
}

template <typename T> bool BinaryNode<T>::has_left() {
  return m_left != nullptr;
}
template <typename T> bool BinaryNode<T>::has_right() {
  return m_right != nullptr;
}

template <typename T> size_t BinaryNode<T>::size() {
  return 1 + size_left() + size_right();
}

template <typename T> size_t BinaryNode<T>::height() {
  return 1 + std::max(size_left(), size_right());
}

template <typename T> size_t BinaryNode<T>::size_left() {
  return has_left() ? m_left->size() : 0;
}

template <typename T> size_t BinaryNode<T>::size_right() {
  return has_right() ? m_right->size() : 0;
}