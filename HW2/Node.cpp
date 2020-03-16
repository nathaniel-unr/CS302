template <typename T>
Node<T>::Node(const T &item) : pnext(NULL), m_data(item) {}
template <typename T>
Node<T>::Node(const T &item, Node<T> *pnext) : pnext(pnext), m_data(item) {}

template <typename T> T &Node<T>::data() { return m_data; }
template <typename T> Node<T> *Node<T>::next() { return pnext; }