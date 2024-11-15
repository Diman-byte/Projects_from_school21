#include "tests.h"

TEST(tests_of_stack, copy_constr) {
  s21::stack<int> s = {1, 2, 3};
  s21::stack<int> copy(s);

  for (size_t i = 0; i < s.size(); i++) {
    ASSERT_EQ(s.top(), copy.top());
    s.pop();
    copy.pop();
  }
}

TEST(tests_of_stack, move_constr) {
  s21::stack<int> s = {1, 2, 3};
  s21::stack<int> copy(std::move(s));
  s21::stack<int> check = {1, 2, 3};

  for (size_t i = 0; i < s.size(); i++) {
    ASSERT_EQ(check.top(), copy.top());
    check.pop();
    copy.pop();
  }
  ASSERT_EQ(s.size(), 0);
}

TEST(tests_of_stack, operator_move) {
  s21::stack<int> s = {1, 2, 3};
  s21::stack<int> copy;
  s21::stack<int> check = {1, 2, 3};
  copy = std::move(s);
  for (size_t i = 0; i < s.size(); i++) {
    ASSERT_EQ(check.top(), copy.top());
    check.pop();
    copy.pop();
  }
  ASSERT_EQ(s.size(), 0);
}

TEST(tests_of_stack, push_1) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  Mystack_1.push(2);
  Mystack_1.push(3);

  int i = 3;
  size_t size = 0;
  while (size < Mystack_1.size()) {
    ASSERT_EQ(i, Mystack_1.top());
    i--;
    size++;
    Mystack_1.pop();
  }
}

TEST(tests_of_stack, pop_1) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  Mystack_1.push(2);
  Mystack_1.push(3);

  Mystack_1.pop();
  Mystack_1.pop();
  Mystack_1.pop();

  bool empty_stack = Mystack_1.empty();
  ASSERT_EQ(1, empty_stack);
}

TEST(tests_of_stack, top) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  Mystack_1.push(2);
  Mystack_1.push(3);
  auto it = Mystack_1.top();
  ASSERT_EQ(3, it);
}

TEST(tests_of_stack, size_1) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  Mystack_1.push(2);
  Mystack_1.push(3);
  auto it = Mystack_1.size();
  ASSERT_EQ((unsigned long)3, it);
}

TEST(tests_of_stack, size_2) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  auto it = Mystack_1.size();
  ASSERT_EQ((unsigned long)1, it);
}

TEST(tests_of_stack, equal) {
  s21::stack<int> Mystack_1;
  Mystack_1.push(1);
  Mystack_1.push(2);
  Mystack_1.push(3);
  int i = 3;
  size_t size = 0;
  while (size < Mystack_1.size()) {
    ASSERT_EQ(i, Mystack_1.top());
    i--;
    size++;
    Mystack_1.pop();
  }
}
