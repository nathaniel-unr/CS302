template <typename T> PriorityQueue<T>::PriorityQueue() : m_head(NULL) {}
template <typename T> PriorityQueue<T>::~PriorityQueue() { clear(); }

template <typename T> bool PriorityQueue<T>::is_empty() {
  return m_head == NULL;
}

template <typename T> bool PriorityQueue<T>::is_full() { return false; }

template <typename T> void PriorityQueue<T>::enqueue(T data) {
  if (is_empty() || data < m_head->data()) {
    m_head = new Node<T>(data, m_head);
    return;
  }

  Node<T> *cur = m_head;
  while (cur->next() != NULL && cur->next()->data() < data)
    cur = cur->next();

  cur->m_next = new Node<T>(data, cur->m_next);
}

template <typename T> T PriorityQueue<T>::dequeue() {
  assert(!is_empty());
  T ret = m_head->data();
  Node<T> *prev = m_head;
  m_head = m_head->next();
  delete prev;
  return ret;
}

template <typename T> void PriorityQueue<T>::clear() {
  while (!is_empty())
    dequeue();
}