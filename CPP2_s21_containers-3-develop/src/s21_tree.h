#ifndef S21_TREE_H
#define S21_TREE_H
#include <limits>

namespace s21 {
template <typename Key, typename T>

class Tree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 protected:
  typedef struct Node {
    value_type value;
    Node *left;
    Node *right;
    Node *parent;
    Node(const_reference val)
        : value(val), left(nullptr), right(nullptr), parent(nullptr){};
  } Node;

  Node *root;
  size_type size_;

 public:
  Tree() : root(nullptr), size_(0){};
  ~Tree() { clear(); }

  Tree(const Tree &s) {
    root = copyTree(s.root, nullptr);
    size_ = s.size_;
  }

  Tree(Tree &&other) noexcept {
    size_ = other.size_;
    root = other.root;
    other.root = nullptr;
    other.size_ = 0;
  }

  class iterator {
   protected:
    Node *current;

   public:
    iterator() : current(nullptr){};
    iterator(Node *node) : current(node){};
    iterator(const iterator &other) : current(other.current) {}

    value_type *operator->() { return &(current->value); }

    Node *getNode() { return this->current; }

    reference operator*() {
      if (!current) {
        throw std::invalid_argument("Set is empty");
      }
      return current->value;
    }

    iterator &operator=(const iterator &other) {
      if (this != &other) {
        this->current = other.current;
      }
      return *this;
    }

    iterator &operator++() {
      if (current != nullptr) {
        if (current->right != nullptr) {
          current = current->right;
          while (current->left != nullptr) {
            current = current->left;
          }
        } else {
          Node *parent = current->parent;
          while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent;
          }
          current = parent;
        }
      }
      return *this;
    }

    iterator operator++(int) {
      iterator temp = *this;
      ++(*this);
      return temp;
    }

    iterator operator--() {
      iterator old = *this;
      if (current != nullptr) {
        if (current->left != nullptr) {
          current = current->left;
          while (current->right != nullptr) {
            current = current->right;
          }
        } else {
          Node *parent = current->parent;
          while (parent != nullptr && current == parent->left) {
            current = parent;
            parent = parent->parent;
          }
          current = parent;
        }
      }
      return old;
    }

    iterator operator--(int) {
      iterator tmp = *this;
      --*this;
      return tmp;
    }

    bool operator!=(const iterator &other) { return current != other.current; }
    bool operator==(const iterator &other) { return current == other.current; }
  };

  class const_iterator {
   protected:
    Node *current;

   public:
    const_iterator() : current(nullptr){};
    const_iterator(Node *node) : current(node){};
    const_iterator(const const_iterator &other) : current(other.current) {}

    value_type *operator->() { return &(current->value); }

    Node *getNode() { return this->current; }

    const_reference operator*() {
      if (!current) {
        throw std::invalid_argument("Set is empty");
      }
      return current->value;
    }

    const_iterator &operator=(const const_iterator &other) {
      if (this != &other) {
        this->current = other.current;
      }
      return *this;
    }

    const_iterator &operator++() {
      if (current != nullptr) {
        if (current->right != nullptr) {
          current = current->right;
          while (current->left != nullptr) {
            current = current->left;
          }
        } else {
          Node *parent = current->parent;
          while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent;
          }
          current = parent;
        }
      }
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator temp = *this;
      ++(*this);
      return temp;
    }

    const_iterator operator--() {
      const_iterator old = *this;
      if (current != nullptr) {
        if (current->left != nullptr) {
          current = current->left;
          while (current->right != nullptr) {
            current = current->right;
          }
        } else {
          Node *parent = current->parent;
          while (parent != nullptr && current == parent->left) {
            current = parent;
            parent = parent->parent;
          }
          current = parent;
        }
      }
      return old;
    }

    bool operator!=(const const_iterator &other) {
      return current != other.current;
    }
    bool operator==(const const_iterator &other) {
      return current == other.current;
    }
  };

  Node *copyTree(Node *node, Node *parent) {
    if (node == nullptr) {
      return nullptr;
    }
    Node *new_node = new Node(node->value);
    new_node->parent = parent;
    new_node->left = copyTree(node->left, new_node);
    new_node->right = copyTree(node->right, new_node);
    return new_node;
  }

  void clear() {
    iterator it = begin();
    while (it != end()) {
      iterator temp = it;
      ++it;
      erase(temp);
    }
    root = nullptr;
    size_ = 0;
  }

  void insert(const value_type value_) {
    root = insert_node(root, value_);
    size_++;
  }

  Node *insert_node(Node *node, const value_type value_) {
    if (node == nullptr) {
      return new Node(value_);
    }

    const key_type &key = value_.first;
    const key_type &node_key = node->value.first;

    if (key > node_key) {
      node->right = insert_node(node->right, value_);

      if (node->right->parent == nullptr) {
        node->right->parent = node;
      }
    } else if (key < node_key) {
      node->left = insert_node(node->left, value_);

      if (node->left->parent == nullptr) {
        node->left->parent = node;
      }
    } else {
      node->value.second = value_.second;
    }
    return node;
  }

  Node *find_node(Node *node, const Key key) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->value.first == key) {
      return node;
    }
    if (key > node->value.first) {
      return find_node(node->right, key);
    } else {
      return find_node(node->left, key);
    }
  }

  Node *getSmallestNode(Node *node) {
    if (node->left != nullptr) {
      return getSmallestNode(node->left);
    }
    return node;
  }

  Node *getBiggestNode(Node *node) {
    if (node->right != nullptr) {
      return getBiggestNode(node->right);
    }
    return node;
  }

  Node *getSmallestNode(Node *node) const {
    if (node->left != nullptr) {
      return getSmallestNode(node->left);
    }
    return node;
  }

  void merge(Tree &other) {
    size_t new_size = other.size();
    for (auto iter = other.begin(); iter != other.end();) {
      auto temp = iter;
      temp++;

      if (temp == iterator(other.getBiggestNode(other.root))) {
        temp--;
        iter++;
      }

      if (!contains(iter->first)) {
        insert(*iter);
        other.erase(iter);
        new_size--;
      }

      iter = temp;
    }
    other.setSize(new_size);
  }

  void erase(iterator pos) {
    if (pos == nullptr) {
      throw std::invalid_argument("Invalid poiner");
    }
    erase_node(find_node(root, pos->first));
  }

  void erase_node(Node *node) {
    if (node == nullptr) return;
    Node *parent = node->parent;

    if (node->left == nullptr && node->right == nullptr) {
      if (parent != nullptr) {
        if (parent->left == node) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
      } else {
        root = nullptr;
      }
      delete node;
    } else if (node->right == nullptr || node->left == nullptr) {
      Node *child = node->left ? node->left : node->right;
      if (parent != nullptr) {
        if (parent->left == node) {
          parent->left = child;
        } else {
          parent->right = child;
        }
      } else {
        root = child;
      }
      if (child != nullptr) {
        child->parent = parent;
      }
      delete node;

    } else {
      Node *new_node = getSmallestNode(node->right);
      node->value.second = new_node->value.second;
      erase_node(new_node);
    }
  }

  void swap(Tree &other) {
    std::swap(root, other.root);
    std::swap(size_, other.size_);
  }

  void setSize(size_type new_size) { size_ = new_size; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(Node *);
  }

  bool empty() { return root == nullptr ? true : false; }
  size_type size() { return size_; }
  bool contains(const Key &key) { return find(key) != end(); }

  iterator begin() { return !root ? end() : iterator(getSmallestNode(root)); }
  const_iterator cbegin() const {
    return !root ? cend() : const_iterator(getSmallestNode(root));
  }

  iterator end() { return iterator(nullptr); }
  const_iterator cend() const { return const_iterator(nullptr); }

  iterator find(const Key &key) { return iterator(find_node(root, key)); }
};
}  // namespace s21

#endif