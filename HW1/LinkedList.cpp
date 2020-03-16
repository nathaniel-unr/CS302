template <typename T> LinkedList<T>::LinkedList() : pfirst(NULL), plast(NULL) {}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) : pfirst(NULL), plast(NULL) {
  copy_from(other);
}
template <typename T> LinkedList<T>::~LinkedList() { clear(); }

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
  clear();
  copy_from(rhs);
  return *this;
}

template <typename T> size_t LinkedList<T>::size() const {
  size_t size = 0;
  for (ConstLinkedListIter<T> iter = this->iter(); iter.is_valid();
       size++, iter.advance()) {
  }

  return size;
}

template <typename T> void LinkedList<T>::push_front(T data) {
  push_front(new Node<T>(data));
}

template <typename T> void LinkedList<T>::push_front(Node<T> *data) {
  if (is_empty()) {
    data->pnext = NULL;
    plast = data;
  } else {
    data->pnext = pfirst;
  }
  pfirst = data;
}

template <typename T> void LinkedList<T>::push_end(T data) {
  push_end(new Node<T>(data));
}

template <typename T> void LinkedList<T>::push_end(Node<T> *data) {
  if (is_empty()) {
    pfirst = data;
    plast->pnext = NULL;
  } else {
    plast->pnext = data;
  }
  plast = data;
}

template <typename T> Node<T> *LinkedList<T>::pop_front() {
  if (is_empty())
    return NULL;

  Node<T> *temp = pfirst;
  if (pfirst == plast) {
    pfirst = NULL;
    plast = NULL;
  } else {
    pfirst = pfirst->pnext;
  }

  return temp;
}

template <typename T> Node<T> *LinkedList<T>::pop_end() {
  if (is_empty())
    return NULL;

  if (pfirst == plast) {
    pfirst = NULL;
    plast = NULL;
  } else {
    LinkedListIter<T> iter = this->iter();
    while (iter.current()->pnext != plast) {
      iter.advance();
    }
    plast = iter.current();
  }

  return iter->pnext;
}

template <typename T> Node<T> *LinkedList<T>::get(size_t target) {
  LinkedListIter<T> iter = this->iter();
  iter.advance_many(target);
  return iter.current();
}

template <typename T> const Node<T> *LinkedList<T>::get(size_t target) const {
  ConstLinkedListIter<T> iter = this->iter();
  iter.advance_many(target);
  return iter.current();
}

template <typename T> bool LinkedList<T>::insert(size_t target_index, T data) {
  if (target_index == 0) {
    push_front(data);
    return true;
  }

  Node<T> *cur = get(target_index - 1);
  if (cur == NULL)
    return false;

  if (cur->next() == NULL) {
    Node<T> *node_data = new Node<T>(data);
    plast->pnext = node_data;
    plast = node_data;
  } else {
    Node<T> *node_data = new Node<T>(data, cur->pnext);
    cur->pnext = node_data;
  }

  return true;
}

template <typename T>
Node<T> *LinkedList<T>::find(const Node<T> *start, T target) {
  if (start == NULL)
    start = pfirst;
  LinkedListIter<T> iter = LinkedListIter<T>(start);
  while (iter.is_valid() && iter.current()->data() == target) {
    iter.advance();
  }
  return iter->current();
}

template <typename T>
const Node<T> *LinkedList<T>::find(const Node<T> *start, T target) const {
  if (start == NULL)
    start = pfirst;
  ConstLinkedListIter<T> iter = LinkedListIter<T>(start);
  while (iter.is_valid() && iter.current()->data() == target) {
    iter.advance();
  }
  return iter->current();
}

template <typename T> Node<T> *LinkedList<T>::remove(size_t target_index) {
  if (is_empty())
    return NULL;

  if (target_index == 0)
    return pop_front();

  if (pfirst == plast)
    return NULL;

  Node<T> *cur = get(target_index - 1);
  Node<T> *temp = cur->pnext;
  if (temp == NULL)
    return NULL;
  cur->pnext = temp->pnext;
  return temp;
}

template <typename T> void LinkedList<T>::clear() {
  if (is_empty())
    return;

  LinkedListIter<T> iter = this->iter();
  while (iter.is_valid()) {
    Node<T> *temp = iter.current();
    iter.advance();
    delete temp;
  }

  pfirst = NULL;
  plast = NULL;
}

template <typename T> bool LinkedList<T>::is_empty() const {
  return pfirst == NULL;
}

template <typename T> LinkedListIter<T> LinkedList<T>::iter() {
  return LinkedListIter<T>(pfirst);
}

template <typename T> ConstLinkedListIter<T> LinkedList<T>::iter() const {
  return ConstLinkedListIter<T>(pfirst);
}

template <typename T> Node<T> *LinkedList<T>::operator[](size_t pos) {
  return get(pos);
}

template <typename T>
const Node<T> *LinkedList<T>::operator[](size_t pos) const {
  return get(pos);
}

template <typename T> Node<T> *LinkedList<T>::first() { return pfirst; }

template <typename T> const Node<T> *LinkedList<T>::first() const {
  return pfirst;
}

template <typename T> Node<T> *LinkedList<T>::last() { return plast; }

template <typename T> const Node<T> *LinkedList<T>::last() const {
  return plast;
}

template <typename T>
void LinkedList<T>::copy_from(const LinkedList<T> &other) {
  ConstLinkedListIter<T> iter = other.iter();
  if (!iter.is_valid())
    return;

  pfirst = new Node<T>(iter.current()->data());
  LinkedListIter<T> new_iter = LinkedListIter<T>(pfirst);

  iter.advance();

  while (iter.is_valid()) {
    new_iter.current()->pnext = new Node<T>(iter.current()->data());
    new_iter.advance();
    iter.advance();
  }

  plast = new_iter.current();
}