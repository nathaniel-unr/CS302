template <typename T>
SharedBinaryNode<T> place_node(SharedBinaryNode<T> tree,
                               SharedBinaryNode<T> node) {
  if (tree == nullptr) {
    return node;
  } else if (tree->data() > node->data()) {
    SharedBinaryNode<T> temp = place_node(tree->left(), node);
    tree->set_left(temp);
  } else {
    SharedBinaryNode<T> temp = place_node(tree->right(), node);
    tree->set_right(temp);
  }

  return tree;
}

template <typename T>
void to_vec_preorder_recursive(std::vector<T> &vec, SharedBinaryNode<T> node) {
  if (node == nullptr)
    return;

  vec.push_back(node->data());
  to_vec_preorder_recursive(vec, node->left());
  to_vec_preorder_recursive(vec, node->right());
}

template <typename T>
void to_vec_inorder_recursive(std::vector<T> &vec, SharedBinaryNode<T> node) {
  if (node == nullptr)
    return;
  to_vec_inorder_recursive(vec, node->left());
  vec.push_back(node->data());
  to_vec_inorder_recursive(vec, node->right());
}

template <typename T>
void to_vec_postorder_recursive(std::vector<T> &vec, SharedBinaryNode<T> node) {
  if (node == nullptr)
    return;

  to_vec_postorder_recursive(vec, node->left());
  to_vec_postorder_recursive(vec, node->right());
  vec.push_back(node->data());
}

template <typename T> BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T data) : root(data) {}

template <typename T> bool BinarySearchTree<T>::add(T data) {
  root = place_node(root, std::make_shared<BinaryNode<T>>(data));
  return true;
}

template <typename T> bool BinarySearchTree<T>::is_empty() {
  return root == nullptr;
}

template <typename T> size_t BinarySearchTree<T>::size() {
  return is_empty() ? 0 : root->size();
}

template <typename T> size_t BinarySearchTree<T>::height() {
  return is_empty() ? 0 : root->height();
}

template <typename T> void BinarySearchTree<T>::clear() { root = nullptr; }

template <typename T> std::vector<T> BinarySearchTree<T>::to_vec_preorder() {
  std::vector<T> ret;
  to_vec_preorder_recursive(ret, root);
  return ret;
}

template <typename T> std::vector<T> BinarySearchTree<T>::to_vec_inorder() {
  std::vector<T> ret;
  to_vec_inorder_recursive(ret, root);
  return ret;
}

template <typename T> std::vector<T> BinarySearchTree<T>::to_vec_postorder() {
  std::vector<T> ret;
  to_vec_postorder_recursive(ret, root);
  return ret;
}