#pragma once
#include "s21_tree.h"

namespace s21 {
template <typename Key, typename T>
class map : public Tree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using iterator = typename Tree<key_type, mapped_type>::iterator;
  using const_iterator = typename Tree<key_type, mapped_type>::const_iterator;

  map() : Tree<key_type, mapped_type>(){};

  map(std::initializer_list<value_type> const& items)
      : Tree<key_type, mapped_type>() {
    for (auto item : items) {
      Tree<key_type, mapped_type>::insert(item);
    }
  };

  map(const map& m) : Tree<key_type, mapped_type>(m){};
  map(map&& m) noexcept : Tree<key_type, mapped_type>(std::move(m)){};
  ~map() = default;

  map& operator=(map&& m) {
    this->clear();
    this->swap(m);
    return *this;
  }

  std::pair<iterator, bool> insert(const value_type& value) {
    bool is_insert = true;
    if (this->contains(value.first)) {
      is_insert = false;
    } else {
      Tree<key_type, mapped_type>::insert(value);
    }
    return std::make_pair(this->find(value.first), is_insert);
  }

  std::pair<iterator, bool> insert(const Key& key, const T& obj) {
    value_type value_(key, obj);
    bool is_insert = true;

    if (this->contains(key)) {
      is_insert = false;
    } else {
      Tree<key_type, mapped_type>::insert(value_);
    }
    return std::make_pair(this->find(key), is_insert);
  }

  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj) {
    value_type value_(key, obj);
    bool is_insert = true;

    if (this->contains(key)) {
      iterator element = this->find(key);
      element->second = obj;
      is_insert = false;
    } else {
      Tree<key_type, mapped_type>::insert(value_);
    }
    return std::make_pair(this->find(key), is_insert);
  }

  T& at(const Key& key) {
    iterator element = this->find(key);
    if (element == this->end()) {
      throw std::out_of_range("map::at key doesn't exist");
    }
    return element->second;
  }

  void erase(iterator pos) {
    Tree<Key, Key>::erase(pos);
    Tree<Key, Key>::setSize(this->size() - 1);
  }

  T& operator[](const Key& key) {
    iterator it = this->find(key);

    if (it == this->end()) {
      this->insert(key, T());
      it = this->find(key);
    }
    return it->second;
  }

  void swap(map& other) { Tree<key_type, mapped_type>::swap(other); }
  void merge(map& other) { Tree<key_type, mapped_type>::merge(other); }

  bool contains(const Key& key) {
    return Tree<key_type, mapped_type>::contains(key);
  }

  // begin, end, empty, size, max_size, clear in class Tree
};
}  // namespace s21
