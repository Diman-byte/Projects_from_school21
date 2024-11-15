#include "tests.h"

TEST(set_constr, constr_test_1) {
  s21::set<int> s;
  ASSERT_NE(&s, nullptr);
  ASSERT_EQ(s.size(), 0);
}

TEST(set_constr_list, set_list_test_1) {
  s21::set<int> a = {1, 2, 4, 10, 12};
  std::set<int> b = {1, 2, 4, 10, 12};

  auto it_a = a.begin();
  auto it_b = b.begin();
  for (; it_a != a.end() && it_b != b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
}

TEST(set_constr_list, set_list_test_2) {
  s21::set<int> a = {1, 1, 1, 1};
  s21::set<int> b = {1};

  auto it_a = a.begin();
  auto it_b = b.begin();
  for (; it_a != a.end() && it_b != b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
  ASSERT_EQ(a.size(), 1);
}

TEST(set_copy, copy_test_1) {
  s21::set<int> s = {8, 3, 10, 1};
  auto iter_s = s.begin();

  s21::set<int> copy_s(s);
  auto iter_copy = copy_s.begin();

  for (; iter_s != s.end() && iter_copy != copy_s.end();
       iter_s++, iter_copy++) {
    ASSERT_EQ(*iter_s, *iter_copy);
  }
}

TEST(set_move, move_test_1) {
  s21::set<int> s = {8, 3, 10, 1};
  s21::set<int> check = {8, 3, 10, 1};

  s21::set<int> move_s = std::move(s);

  auto iter_move = move_s.begin();
  auto ch = check.begin();

  for (; iter_move != move_s.end() && ch != check.end(); iter_move++, ch++) {
    ASSERT_EQ(*iter_move, *ch);
  }

  auto i = s.begin();
  ASSERT_TRUE(i == nullptr);
}

TEST(set_operator_copy, operator_copy_test_1) {
  s21::set<int> s = {1, 2};

  s21::set<int> s2 = {6, 100, 9};
  s = s2;

  auto iter = s.begin();
  auto check = s2.begin();

  for (; iter != s.end(); iter++, check++) {
    ASSERT_EQ(*iter, *check);
  }
  ASSERT_EQ(s.size(), s2.size());
}

TEST(set_operator_copy, operator_copy_test_2) {
  s21::set<int> s;

  s21::set<int> s2 = {6, 100, 9};
  s = s2;

  auto iter = s.begin();
  auto check = s2.begin();

  for (; iter != s.end(); iter++, check++) {
    ASSERT_EQ(*iter, *check);
  }
  ASSERT_EQ(s.size(), s2.size());
}

TEST(set_operator_move, operator_move_test_1) {
  s21::set<int> a = {1, 7, 9, 3};

  s21::set<int> b = {6, 100, 9};
  s21::set<int> check_set = {6, 100, 9};

  a = std::move(b);

  auto iter = a.begin();
  auto check = check_set.begin();

  for (; iter != a.end(); iter++, check++) {
    ASSERT_EQ(*iter, *check);
  }
  auto empty = b.begin();
  ASSERT_TRUE(empty == nullptr);
  ASSERT_EQ(a.size(), 3);
}

TEST(set_iter, iter_test_1) {
  s21::set<int> s = {4, 5, 2, 0, 1};
  std::set<int> check = {4, 5, 2, 0, 1};

  auto it = s.begin();
  auto k = check.begin();

  for (; it != s.end() && k != check.end(); --it, k++) {
    ASSERT_EQ(*it, *k);
  }
}

TEST(set_begin, begin_test_1) {
  s21::set<int> s = {10, 0, 30};
  auto iter = s.begin();
  ASSERT_EQ(*iter, 0);
  iter++;
  ASSERT_EQ(*iter, 10);
  iter++;
  ASSERT_EQ(*iter, 30);
}

TEST(set_empty, empty_test_1) {
  s21::set<int> s;
  ASSERT_EQ(s.empty(), true);
  s.insert(10);
  ASSERT_EQ(s.empty(), false);
}

TEST(set_size, size_test_1) {
  s21::set<int> s = {9, 1, 0, 2, 5, 7};
  s21::set<int> s2;

  ASSERT_EQ(s.size(), 6);
  ASSERT_EQ(s2.size(), 0);
}

TEST(set_max_size, max_size_test_1) {
  std::set<int> s = {};
  s21::set<int> s21 = {};

  //   std::cout << s.max_size() << std::endl;
  //   std::cout << s21.max_size() << std::endl;
  ASSERT_TRUE(s.max_size() < s21.max_size());
}

TEST(set_erase, erase_test_1) {
  // del root
  s21::set<int> s = {8, 3, 1, 6, 7, 4, 10, 14, 13};
  auto it = s.find(8);
  s.erase(it);
  ASSERT_EQ(s.contains(8), 0);
  //   std::cout << s.size() << std::endl;
  ASSERT_EQ(s.size(), 8);
}

TEST(set_erase, erase_test_2) {
  // del 1 child
  s21::set<int> s = {8, 3, 1, 6, 7, 4, 10, 14, 13};
  auto it = s.find(13);
  s.erase(it);
  ASSERT_EQ(s.contains(13), 0);
  ASSERT_EQ(s.size(), 8);
}

TEST(set_erase, erase_test_3) {
  // del 0 child
  s21::set<int> s = {8, 3, 1, 6, 7, 4, 10, 14, 13};
  auto it = s.find(14);
  s.erase(it);
  ASSERT_EQ(s.contains(14), 0);
  ASSERT_EQ(s.size(), 8);
}

TEST(set_erase, erase_test_4) {
  // del 2 child
  s21::set<int> s = {8, 3, 1, 6, 7, 4, 10, 14, 13};
  std::cout << *s.find(3) << std::endl;

  s.erase(s.find(3));
  std::cout << *s.find(3) << std::endl;

  ASSERT_FALSE(s.contains(3));

  ASSERT_EQ(s.size(), 8);
}

TEST(set_erase, erase_test_5) {
  // del nullptr
  s21::set<int> s = {8, 3, 1, 6, 7};
  EXPECT_THROW({ s.erase(s.find(2)); }, std::invalid_argument);
  ASSERT_EQ(s.size(), 5);
}

TEST(set_swap, swap_test_1) {
  s21::set<int> a = {1, 2, 4};
  s21::set<int> temp_a = {1, 2, 4};

  s21::set<int> b = {9, 2, 4, 5};
  s21::set<int> temp_b = {9, 2, 4, 5};

  a.swap(b);
  auto it_a = a.begin();
  auto it_b = temp_b.begin();

  for (; it_a != a.end() && it_b != temp_b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }

  it_a = b.begin();
  it_b = temp_a.begin();
  for (; it_a != b.end() && it_b != temp_a.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
}

TEST(set_swap, swap_test_2) {
  s21::set<int> a = {1, 2, 4};
  s21::set<int> temp_a = {1, 2, 4};

  s21::set<int> b = {9};
  s21::set<int> temp_b = {9};

  a.swap(b);
  auto it_a = a.begin();
  auto it_b = temp_b.begin();

  for (; it_a != a.end() && it_b != temp_b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }

  it_a = b.begin();
  it_b = temp_a.begin();
  for (; it_a != b.end() && it_b != temp_a.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
}

TEST(set_swap, swap_test_3) {
  s21::set<int> a = {1, 2, 4};
  s21::set<int> temp_a = {1, 2, 4};

  s21::set<int> b = {};
  s21::set<int> temp_b = {};

  a.swap(b);
  auto it_a = a.begin();
  auto it_b = temp_b.begin();

  for (; it_a != a.end() && it_b != temp_b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }

  it_a = b.begin();
  it_b = temp_a.begin();
  for (; it_a != b.end() && it_b != temp_a.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
}

TEST(set_swap, swap_test_4) {
  s21::set<int> a = {};
  s21::set<int> temp_a = {};

  s21::set<int> b = {1, 3, 4, 9};
  s21::set<int> temp_b = {1, 3, 4, 9};

  a.swap(b);
  auto it_a = a.begin();
  auto it_b = temp_b.begin();

  for (; it_a != a.end() && it_b != temp_b.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }

  it_a = b.begin();
  it_b = temp_a.begin();
  for (; it_a != b.end() && it_b != temp_a.end(); it_a++, it_b++) {
    ASSERT_EQ(*it_a, *it_b);
  }
  ASSERT_EQ(a.size(), temp_b.size());
  ASSERT_EQ(b.size(), temp_a.size());
}

TEST(set_merge, merge_test_1) {
  s21::set<int> a = {3, 1, 2, 10};
  s21::set<int> b = {3, 4, 5, 8};
  s21::set<int> result = {4, 5, 8, 3, 1, 2, 10};

  a.merge(b);
  auto iter_res = result.begin();
  for (auto it = a.begin(); it != a.end() && iter_res != result.end();
       it++, iter_res++) {
    ASSERT_EQ(*it, *iter_res);
  }

  ASSERT_EQ(a.size(), result.size());
  ASSERT_EQ(b.size(), 1);
}

TEST(set_merge, merge_test_2) {
  s21::set<int> a;
  s21::set<int> b = {4, 5, 8, 3};
  s21::set<int> result = {4, 5, 8, 3};

  a.merge(b);
  auto iter_res = result.begin();
  for (auto it = a.begin(); it != a.end() && iter_res != result.end();
       it++, iter_res++) {
    ASSERT_EQ(*it, *iter_res);
  }

  ASSERT_EQ(a.size(), result.size());
  ASSERT_EQ(b.size(), 0);
}

TEST(set_merge, merge_test_3) {
  s21::set<int> a = {4, 5, 8, 3};

  s21::set<int> b;
  s21::set<int> result = {4, 5, 8, 3};

  a.merge(b);
  auto iter_res = result.begin();
  for (auto it = a.begin(); it != a.end() && iter_res != result.end();
       it++, iter_res++) {
    ASSERT_EQ(*it, *iter_res);
  }
  ASSERT_EQ(a.size(), result.size());
  ASSERT_EQ(b.size(), 0);
}

TEST(set_find, find_test_1) {
  s21::set<int> s = {9, 3, 4, 1, 0};
  auto result = s.find(4);
  ASSERT_EQ(*result, 4);
}

TEST(set_find, find_test_2) {
  s21::set<int> s = {9, 3, 4, 1, 0};
  auto result = s.find(5);
  EXPECT_TRUE(result == nullptr);
}

TEST(set_contains, contains_test_1) {
  s21::set<int> s = {9, 3, 4, 1, 0};
  bool result = s.contains(4);
  ASSERT_TRUE(result);
}

TEST(set_contains, contains_test_2) {
  s21::set<int> s = {9, 3, 4, 1, 0};
  bool result = s.contains(5);
  ASSERT_FALSE(result);
}

TEST(set_insert, insert_test_1) {
  s21::set<int> s;
  auto iter = s.insert(100);

  ASSERT_EQ(*iter.first, 100);
  ASSERT_EQ(iter.second, true);

  auto iter2 = s.insert(100);

  ASSERT_EQ(*iter2.first, 100);
  ASSERT_EQ(iter2.second, false);
}

TEST(set_insert, insert_test_2) {
  s21::set<int> s = {1, 2, 3, 100};
  auto iter = s.insert(100);

  ASSERT_EQ(s.size(), 4);
  ASSERT_EQ(iter.second, false);
}

TEST(set_insert, insert_test_3) {
  s21::set<int> s = {1, 2, 3, 4};
  auto iter1 = s.insert(90);
  auto iter2 = s.insert(0);

  ASSERT_EQ(iter1.second, true);
  ASSERT_EQ(iter2.second, true);
  ASSERT_EQ(s.size(), 6);
}