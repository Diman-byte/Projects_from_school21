#include <iostream>
#include <list>

#include "s21_list.h"

namespace s21 {
template <typename T>
class queue {
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
  queue() : container() {}
  queue(std::initializer_list<value_type> const &items) {
    for (auto item : items) {
      container.push_back(item);
    }
  }

  queue(const queue &q) {
    for (auto item : q.container) {
      container.push_back(item);
    }
  }

  queue(queue &&q) noexcept : container(std::move(q.container)) {
    q.container.clear();
  }

  ~queue() = default;

  queue &operator=(queue &&q) {
    container.clear();
    this->swap(q);
    return *this;
  }

  const_reference front() { return container.front(); }
  const_reference back() { return container.back(); }

  void push(const_reference value) { container.push_back(value); }
  void pop() {
    if (!empty()) {
      container.pop_front();
    }
  }
  void swap(queue &other) { container.swap(other.container); }

  bool empty() { return container.empty(); }
  size_type size() { return container.size(); }
};

}  // namespace s21