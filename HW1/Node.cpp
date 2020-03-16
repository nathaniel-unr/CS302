template <typename T> Node<T>::Node(T data) : m_data(data), pnext(NULL) {}
template <typename T>
Node<T>::Node(T data, Node<T> *pnext) : m_data(data), pnext(pnext) {}
template <typename T> T &Node<T>::data() { return m_data; }
template <typename T> const T &Node<T>::data() const { return m_data; }
template <typename T> Node<T> *Node<T>::next() const { return pnext; }