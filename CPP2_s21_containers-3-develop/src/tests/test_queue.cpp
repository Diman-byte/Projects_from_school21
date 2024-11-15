#include "tests.h"

TEST(tests_of_queue, copy_cnstr) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> copy(q);

  ASSERT_EQ(q.size(), q.size());

  for (size_t i = 0; i < q.size(); i++) {
    ASSERT_EQ(q.front(), copy.front());
    q.pop();
    copy.pop();
  }
}

TEST(tests_of_queue, move_cnstr) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> copy(std::move(q));
  s21::queue<int> check = {1, 2, 3};

  for (size_t i = 0; i < q.size(); i++) {
    ASSERT_EQ(check.front(), copy.front());
    check.pop();
    copy.pop();
  }
  ASSERT_TRUE(q.empty());
  ASSERT_EQ(q.size(), 0);
}

TEST(tests_of_queue, operator_move) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> copy{9};
  s21::queue<int> check = {1, 2, 3};
  copy = std::move(q);

  for (size_t i = 0; i < q.size(); i++) {
    ASSERT_EQ(check.front(), copy.front());
    check.pop();
    copy.pop();
  }
  ASSERT_TRUE(q.empty());
  ASSERT_EQ(q.front(), 0);
  ASSERT_EQ(q.size(), 0);
}

TEST(tests_of_queue, push_1) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  Myqueue_1.push(2);
  Myqueue_1.push(3);

  int i = 1;
  size_t size = 0;
  while (size < Myqueue_1.size()) {
    ASSERT_EQ(i, Myqueue_1.front());
    i++;
    size++;
    Myqueue_1.pop();
  }
}

TEST(tests_of_queue, pop_1) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  Myqueue_1.push(2);
  Myqueue_1.push(3);

  Myqueue_1.pop();
  Myqueue_1.pop();
  Myqueue_1.pop();
  Myqueue_1.pop();

  bool empty_queue = Myqueue_1.empty();
  ASSERT_TRUE(empty_queue);
}

TEST(tests_of_queue, back) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  Myqueue_1.push(2);
  Myqueue_1.push(3);
  auto it = Myqueue_1.back();
  ASSERT_EQ(3, it);
}
TEST(tests_of_queue, size_1) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  Myqueue_1.push(2);
  Myqueue_1.push(3);
  auto it = Myqueue_1.size();
  ASSERT_EQ((unsigned long)3, it);
}
TEST(tests_of_queue, size_2) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  auto it = Myqueue_1.size();
  ASSERT_EQ((unsigned long)1, it);
}

TEST(tests_of_queue, equal) {
  s21::queue<int> Myqueue_1;
  Myqueue_1.push(1);
  Myqueue_1.push(2);
  Myqueue_1.push(3);
  int i = 1;
  size_t size = 0;
  while (size < Myqueue_1.size()) {
    ASSERT_EQ(i, Myqueue_1.front());
    i++;
    size++;
    Myqueue_1.pop();
  }
}