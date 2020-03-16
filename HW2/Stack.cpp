template <typename T> Stack<T>::Stack() : ptop(NULL) {}
template <typename T> Stack<T>::Stack(const Stack<T> &other) : ptop(NULL) {
  from_stack(other);
}
template <typename T> Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
  clear();
  from_stack(rhs);
  return *this;
}
template <typename T> Stack<T>::~Stack() { clear(); }

template <typename T> void Stack<T>::push(const T &item) {
  assert(!isFull());
  ptop = new Node<T>(item, ptop);
}
template <typename T> T Stack<T>::peek() {
  assert(!isEmpty());
  return ptop->data();
}
// It is safe to pop an empty stack
template <typename T> void Stack<T>::pop() { ptop = ptop->pnext; }
template <typename T> void Stack<T>::clear() {
  Node<T> *node = ptop;
  while (!isEmpty()) {
    node = ptop;
    ptop = ptop->pnext;
    delete node;
  }
}
template <typename T> bool Stack<T>::isEmpty() { return ptop == NULL; }
template <typename T> bool Stack<T>::isFull() { return false; }

template <typename T> void Stack<T>::from_stack(const Stack<T> &other) {
  if (!other.is_empty()) {
    ptop = new Node<T>(other.ptop->data());
    for (Node<T> *other_cur = other.ptop, *cur = ptop; other_cur != NULL;
         other_cur = other_cur->pnext, cur = cur->pnext) {
      cur->pnext = new Node<T>(other_cur->data());
    }
  }
}
