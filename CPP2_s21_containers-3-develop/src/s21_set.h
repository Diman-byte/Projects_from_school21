#ifndef S21_SET_H
#define S21_SET_H

#include "s21_tree.h"

namespace s21 {
template <typename Key>

class set : public Tree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  set() : Tree<Key, Key>() {}
  set(const set &s) : Tree<Key, Key>(s) {}
  set(set &&s) : Tree<Key, Key>(std::move(s)){};
  set(std::initializer_list<value_type> const &items) : Tree<Key, Key>() {
    for (auto item : items) {
      insert(item);
    }
  }
  ~set() = default;

  class iterator : public Tree<Key, Key>::iterator {
   public:
    using Tree<Key, Key>::iterator::iterator;  // Наследование

   public:
    reference operator*() {
      if (!this->current) {
        throw std::invalid_argument("Set is empty");
      }
      return this->current->value.second;
    }
  };

  class const_iterator : public Tree<Key, Key>::const_iterator {
   public:
    using Tree<Key, Key>::const_iterator::const_iterator;

   public:
    const_reference operator*() {
      if (!this->current) {
        throw std::invalid_argument("Set is empty");
      }
      return this->current->value.second;
    }
  };

  set &operator=(set &&s) {
    this->clear();
    this->swap(s);
    return *this;
  }

  set &operator=(const set &s) {
    if (this != &s) {
      this->clear();

      for (auto it = s.cbegin(); it != s.cend(); it++) {
        insert(*it);
      }
    }
    return *this;
  }

  bool empty() { return Tree<Key, Key>::empty(); }
  size_type size() { return Tree<Key, Key>::size(); }
  size_type max_size() { return Tree<Key, Key>::max_size(); }
  void clear() { Tree<Key, Key>::clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    bool is_insert = true;
    if (contains(value)) {
      is_insert = false;
    } else {
      Tree<Key, Key>::insert(std::make_pair(value, value));
    }
    return std::make_pair(find(value), is_insert);
  }

  void erase(iterator pos) {
    Tree<Key, Key>::erase(pos);
    Tree<Key, Key>::setSize(size() - 1);
  }

  bool contains(const Key &key) {
    iterator it = find(key);
    return it != end() ? *it == key : false;
  }

  void swap(set &other) { Tree<Key, Key>::swap(other); }
  void merge(set &other) { Tree<Key, Key>::merge(other); }

  iterator find(const Key &key) {
    return iterator(this->find_node(this->root, key));
  }

  iterator begin() { return iterator(Tree<Key, Key>::begin().getNode()); }
  iterator end() { return iterator(Tree<Key, Key>::end().getNode()); }

  const_iterator cbegin() const {
    return const_iterator(Tree<Key, Key>::cbegin().getNode());
  }
  const_iterator cend() const {
    return const_iterator(Tree<Key, Key>::cend().getNode());
  }
};
}  // namespace s21

#endif