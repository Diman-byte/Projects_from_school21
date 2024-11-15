#ifndef S21_LIST_H_
#define S21_LIST_H_
#include <limits>

namespace s21 {
template <typename T>
class list {
  struct Node;

 public:
  class iterator;
  using value_type = T;
  using const_value = const T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Contr and Destr

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const
           &items);             // list<int> myList = {1, 2, 3, 4, 5};
  list(const list &other);      // const copy
  list(list &&other) noexcept;  // const move
  ~list();

  // Operators

  list &operator=(list &other);
  list &operator=(list &&other) noexcept;

  // Func

  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void swap(list &other);
  void merge(list &other);
  void splice(const iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // Doub Func

  void print() const;
  void init_fake();
  void init_field();
  void delete_fake();

  // Cap

  size_type size() const { return size_; }
  bool empty() const { return head_ == fake_; }
  size_type max_size();

  // Access

  const_reference front();
  const_reference back();

 private:
  struct Node {
    value_type data_;
    Node *prev_, *next_;
    explicit Node(value_type data = value_type(), Node *prev = nullptr,
                  Node *next = nullptr)
        : data_(data), prev_(prev), next_(next) {}
  };
  Node *head_, *tail_, *fake_;
  size_type size_;

 public:
  class iterator {
    Node *node_;

   public:
    iterator();
    explicit iterator(Node *node);
    reference operator*() const;
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    iterator operator+(int shift);
    iterator operator-(int shift);
    iterator &operator+=(int shift);
    iterator &operator-=(int shift);
    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;
    Node *get_node() { return node_; }
    friend class list;
  };
  iterator begin() const;
  iterator end() const;
  Node *get_node(iterator it) { return it.node_; }

  template <typename... Args>
  iterator insert_many(const iterator pos, Args &&...args) {
    for (auto elem : {std::forward<Args>(args)...}) {
      insert(pos, elem);
    }
    return pos;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    (push_front(std::forward<Args>(args)), ...);
  }
};
// Constr and destr
template <typename value_type>
list<value_type>::list() {
  init_fake();
  init_field();
}

template <typename value_type>
list<value_type>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <typename value_type>
list<value_type>::list(const list &other) : list() {
  Node *tmp = other.head_;
  while (tmp != other.fake_) {
    push_back(tmp->data_);
    tmp = tmp->next_;
  }
}

template <typename value_type>
list<value_type> &list<value_type>::operator=(list &other) {
  if (this == &other) return *this;
  clear();
  Node *tmp = other.head_;
  while (tmp != other.fake_) {
    push_back(tmp->data_);
    tmp = tmp->next_;
  }
  return *this;
}

template <typename value_type>
list<value_type>::list(list &&other) noexcept
    : head_(other.head_),
      tail_(other.tail_),
      fake_(other.fake_),
      size_(other.size_) {
  other.init_fake();
  other.init_field();
}

template <typename value_type>
list<value_type> &list<value_type>::operator=(list &&other) noexcept {
  if (this == &other) return *this;
  clear();
  delete_fake();

  head_ = other.head_;
  tail_ = other.tail_;
  fake_ = other.fake_;
  size_ = other.size_;

  other.init_fake();
  other.init_field();
  return *this;
}

template <typename value_type>
list<value_type>::~list() {
  clear();
  delete_fake();
}

// Main Func

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  insert(iterator(fake_), value);
}

template <typename value_type>
void list<value_type>::pop_front() {
  /*
  if (empty()) {
    throw std::out_of_range("Cannot pop from an empty list");
  }
  */
  erase(iterator(head_));
}

template <typename value_type>
void list<value_type>::clear() {
  while (size_ != 0) {
    pop_front();
  }
}

template <typename value_type>
void list<value_type>::pop_back() {
  /*
  if (empty()) {
    throw std::out_of_range("Cannot pop from an empty list");
  }
  */
  erase(iterator(tail_));
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  insert(iterator(head_), value);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  Node *node = new Node(value);
  node->next_ = pos.node_;
  node->prev_ = pos.node_->prev_;
  pos.node_->prev_->next_ = node;
  pos.node_->prev_ = node;

  if (node->prev_ == fake_) {
    head_ = node;
  }
  if (node->next_ == fake_) {
    tail_ = node;
  }

  ++size_;
  fake_->data_ = size_;
  return iterator(node);
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos.node_ == fake_) return;

  pos.node_->prev_->next_ = pos.node_->next_;
  pos.node_->next_->prev_ = pos.node_->prev_;

  if (pos.node_ == head_) {
    head_ = pos.node_->next_;
  }
  if (pos.node_ == tail_) {
    tail_ = pos.node_->prev_;
  }
  size_--;
  fake_->data_ = size_;
  delete pos.node_;
}

template <typename value_type>
void list<value_type>::swap(list &other) {
  if (this == &other) return;

  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(fake_, other.fake_);
}

template <typename value_type>
void list<value_type>::merge(list &other) {
  if (this == &other || other.head_ == fake_) return;
  list<value_type> tmp(size_ + other.size_);

  iterator it_this = begin();
  iterator it_other = other.begin();
  iterator it_tmp = tmp.begin();

  while (it_this != end() || it_other != other.end()) {
    if (it_other != other.end() && (*it_this > *it_other || it_this == end())) {
      *it_tmp++ = *it_other++;
    } else {
      *it_tmp++ = *it_this++;
    }
  }
  *this = tmp;
  other.clear();
}

template <typename value_type>
void list<value_type>::splice(const iterator pos, list &other) {
  if (this != &other) {
    for (auto itr = other.begin(); itr != other.end(); ++itr) {
      insert(pos, *itr);
    }
    other.clear();
  }
}

template <typename value_type>
void list<value_type>::unique() {
  if (begin() == end()) return;

  for (iterator it1 = begin(); it1 != end(); it1++) {
    bool loop = true;
    for (iterator it2 = iterator(it1.node_->next_); it2 != end() && loop;) {
      if (*it1 == *it2) {
        iterator tmp = iterator(it2.node_->next_);
        erase(it2);
        it2 = tmp;
      } else {
        loop = false;
      }
    }
  }
}

template <typename value_type>
void list<value_type>::reverse() {
  iterator it1(head_);
  iterator it2(tail_);
  for (; it1 != it2 && it1.node_->next_ != it2.node_; ++it1, --it2) {
    value_type tmp = it1.node_->data_;
    it1.node_->data_ = it2.node_->data_;
    it2.node_->data_ = tmp;
  }
}

template <typename value_type>
void list<value_type>::sort() {
  if (head_ == tail_) {
    return;
  }
  for (iterator i = begin(); i != end(); i++) {
    iterator i_next = iterator(i.node_->next_);
    for (; i_next != end() && i_next != i; i_next++) {
      if (*i > *i_next) {
        value_type data = *i_next;
        *i_next = *i;
        *i = data;
      }
    }
  }
}

// Sub Func

template <typename value_type>
void list<value_type>::print() const {
  for (Node *tmp = head_; tmp != fake_; tmp = tmp->next_) {
    std::cout << tmp->data_ << " ";
  }
  std::cout << "\n";
}

template <typename value_type>
void list<value_type>::init_fake() {
  fake_ = new Node;
}

template <typename value_type>
void list<value_type>::init_field() {
  fake_->data_ = value_type();
  fake_->next_ = fake_;
  fake_->prev_ = fake_;
  head_ = fake_;
  tail_ = fake_;
  size_ = 0;
}

template <typename value_type>
void list<value_type>::delete_fake() {
  delete fake_;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(Node);
}

// Access el list

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  /*
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  */
  return head_ ? head_->data_ : fake_->data_;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  /*
    if (empty()) {
      throw std::out_of_range("List is empty");
    }
    */
  return tail_ ? tail_->data_ : fake_->data_;
}

// List it-or

template <typename value_type>
list<value_type>::iterator::iterator() : node_(nullptr) {}

template <typename value_type>
list<value_type>::iterator::iterator(Node *node) : node_(node) {}

template <typename value_type>
typename list<value_type>::iterator &list<value_type>::iterator::operator++() {
  node_ = node_->next_;
  return *this;
}

template <typename value_type>
typename list<value_type>::reference list<value_type>::iterator::operator*()
    const {
  return node_->data_;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator++(
    int) {
  iterator tmp = *this;
  node_ = node_->next_;
  return tmp;
}

template <typename value_type>
typename list<value_type>::iterator &list<value_type>::iterator::operator--() {
  node_ = node_->prev_;
  return *this;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator--(
    int) {
  iterator tmp = *this;
  node_ = node_->prev_;
  return tmp;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator+(
    int shift) {
  auto tmp = *this;
  while (shift-- > 0) ++tmp;
  return tmp;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::iterator::operator-(
    int shift) {
  auto tmp = *this;
  while (shift-- > 0) tmp--;
  return tmp;
}

template <typename value_type>
typename list<value_type>::iterator &list<value_type>::iterator::operator+=(
    int shift) {
  while (shift-- > 0) ++(*this);
  return *this;
}

template <typename value_type>
typename list<value_type>::iterator &list<value_type>::iterator::operator-=(
    int shift) {
  while (shift-- > 0) (*this)--;
  return *this;
}

template <typename value_type>
bool list<value_type>::iterator::operator==(const iterator &other) const {
  return node_ == other.node_;
}

template <typename value_type>
bool list<value_type>::iterator::operator!=(const iterator &other) const {
  return node_ != other.node_;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() const {
  return iterator(fake_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() const {
  return iterator(!head_ ? fake_ : head_);
}

}  // namespace s21

#endif