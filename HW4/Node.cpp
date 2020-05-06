template <typename T> Node<T>::Node(T data) : m_data(data), m_next(NULL) {}
template <typename T>
Node<T>::Node(T data, Node<T> *m_next) : m_data(data), m_next(m_next) {}
template <typename T> T &Node<T>::data() { return m_data; }
template <typename T> const T &Node<T>::data() const { return m_data; }
template <typename T> Node<T> *Node<T>::next() const { return m_next; }