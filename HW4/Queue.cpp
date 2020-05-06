template <typename T> Queue<T>::Queue() : m_head(NULL) {}
template <typename T> Queue<T>::~Queue() { clear(); }
template <typename T> void Queue<T>::enqueue(T data) {
  if (is_empty()) {
    m_head = new Node<T>(data);
  } else {
    Node<T> *cur = m_head;
    while (cur->next() != NULL)
      cur = cur->next();
    cur->m_next = new Node<T>(data);
  }
}
template <typename T> T Queue<T>::dequeue() {
  assert(!is_empty());
  T ret = m_head->data();
  Node<T> *prev = m_head;
  m_head = m_head->next();
  delete prev;
  return ret;
}
template <typename T> bool Queue<T>::is_empty() { return m_head == NULL; }
template <typename T> bool Queue<T>::is_full() { return false; }
template <typename T> void Queue<T>::clear() {
  while (!is_empty())
    dequeue();
}