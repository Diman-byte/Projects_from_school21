#include <iostream>

#include "s21_list.h"

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using list_type = s21::list<value_type>;

 private:
  list_type container;
  size_type size_;

 public:
  stack() : container(), size_(0) {}

  stack(std::initializer_list<value_type> const &items) {
    for (auto item = items.begin(); item != items.end(); item++) {
      container.push_back(*item);
    }
    size_ = container.size();
  }

  stack(const stack &s) {
    for (auto item : s.container) {
      container.push_back(item);
    }
  }

  stack(stack &&s) noexcept : container(std::move(s.container)) {
    s.container.clear();
  }

  ~stack() = default;

  stack &operator=(stack &&s) {
    container.clear();
    this->swap(s);
    return *this;
  }

  const_reference top() { return container.back(); }
  void push(const_reference value) { container.push_back(value); }
  void pop() { container.pop_back(); }
  void swap(stack &other) { container.swap(other.container); }
  bool empty() { return size_ == 0; }
  size_type size() { return container.size(); }
};

}  // namespace s21
