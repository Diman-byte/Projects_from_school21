#include "tests.h"

TEST(map_constructor, case1) {
  s21::map<int, int> s21_map_int;
  s21::map<double, double> s21_map_double;
  s21::map<std::string, std::string> s21_map_string;

  EXPECT_EQ(s21_map_int.size(), 0U);
  EXPECT_EQ(s21_map_double.size(), 0U);
  EXPECT_EQ(s21_map_string.size(), 0U);
}

TEST(map_constructor, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_constructor, case3) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_constructor, case4) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_constructor, case5) {
  s21::map<std::string, int> s21_map = {{"hello", 1}, {"hi", 2}, {"hola", 3}};

  EXPECT_EQ(s21_map.size(), 3U);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

TEST(map_copy_cnstr, case6) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res(s21_map_ref);
  auto iter1 = s21_map_ref.begin();
  auto iter2 = s21_map_res.begin();
  for (; iter1 != s21_map_ref.end(); iter1++, iter2++) {
    EXPECT_EQ((*iter1).first, (*iter2).first);
    EXPECT_EQ((*iter1).second, (*iter2).second);
  }

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(map_copy_cnstr, case7) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  s21::map<double, std::string> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

TEST(map_copy_cnstr, case8) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  s21::map<std::string, int> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.size(), s21_map_ref.size());
}

// move
TEST(map_move_cnstr, case9) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  s21::map<int, double> s21_map_ref = {pair1, pair2, pair3};
  s21::map<int, double> s21_map_res = std::move(s21_map_ref);
  EXPECT_TRUE(s21_map_ref.begin() == nullptr);
  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

TEST(map_move_cnstr, case10) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  s21::map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  s21::map<double, std::string> s21_map_res = std::move(s21_map_ref);

  EXPECT_TRUE(s21_map_ref.begin() == nullptr);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

TEST(map_move_cnstr, case11) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  s21::map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  s21::map<std::string, int> s21_map_res = std::move(s21_map_ref);

  EXPECT_TRUE(s21_map_ref.begin() == nullptr);

  EXPECT_EQ(s21_map_ref.size(), 0U);
  EXPECT_EQ(s21_map_res.size(), 3U);
}

// Insert

TEST(map_insert, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};

  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case2) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};
  std::pair<double, std::string> pair4{2.77, "hi"};
  std::pair<double, std::string> pair5{3.9, "hola"};

  s21::map<double, std::string> s21_map;

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hi", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello", 1};

  s21::map<std::string, int> s21_map;

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert(pair3);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert(pair4);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert(pair5);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case4) {
  std::pair<int, double> pair1{9, 1.4};

  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(pair1);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  s21::map<double, std::string> s21_map = {pair1};

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(pair1);
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};

  s21::map<std::string, int> s21_map = {pair1};

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert(pair2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.size(), 2U);
}

TEST(map_insert, case7) {
  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<int, double>::iterator, bool> insert4 =
      s21_map.insert(23, 2.77);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert5 =
      s21_map.insert(98, 3.9);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case8) {
  s21::map<double, std::string> s21_map;

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(1.4, "hello");
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert2 =
      s21_map.insert(2.77, "hi");
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert3 =
      s21_map.insert(3.9, "hola");
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<s21::map<double, std::string>::iterator, bool> insert4 =
      s21_map.insert(2.77, "hi");
  std::pair<s21::map<double, std::string>::iterator, bool> insert5 =
      s21_map.insert(3.9, "hola");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case9) {
  s21::map<std::string, int> s21_map;

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert("hello", 1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert2 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert3 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert3.second, 0);

  std::pair<s21::map<std::string, int>::iterator, bool> insert4 =
      s21_map.insert("hola", 3);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<s21::map<std::string, int>::iterator, bool> insert5 =
      s21_map.insert("hello", 1);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.size(), 3U);
}

TEST(map_insert, case10) {
  s21::map<int, double> s21_map;

  std::pair<s21::map<int, double>::iterator, bool> insert1 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<s21::map<int, double>::iterator, bool> insert2 =
      s21_map.insert(9, 1.4);
  std::pair<s21::map<int, double>::iterator, bool> insert3 =
      s21_map.insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case11) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  s21::map<double, std::string> s21_map = {pair1};

  std::pair<s21::map<double, std::string>::iterator, bool> insert1 =
      s21_map.insert(1.4, "hello");
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.size(), 1U);
}

TEST(map_insert, case12) {
  std::pair<std::string, int> pair1{"hello", 1};

  s21::map<std::string, int> s21_map = {pair1};

  std::pair<s21::map<std::string, int>::iterator, bool> insert1 =
      s21_map.insert("hi", 2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.size(), 2U);
}

TEST(map_insert_assign, case12) {
  s21::map<int, int> m{{0, 10}, {1, 20}, {2, 30}};

  std::pair<s21::map<int, int>::iterator, bool> ins =
      m.insert_or_assign(0, 100);

  ASSERT_EQ(ins.first->first, 0);
  ASSERT_EQ(ins.first->second, 100);
  ASSERT_FALSE(ins.first->first);
  ASSERT_EQ(m[0], 100);

  ASSERT_EQ(m.size(), 3U);
}

TEST(map_insert_assign, case13) {
  s21::map<int, int> m{{0, 10}, {1, 20}, {2, 30}};

  std::pair<s21::map<int, int>::iterator, bool> ins =
      m.insert_or_assign(3, 100);

  ASSERT_EQ(ins.first->first, 3);
  ASSERT_EQ(ins.first->second, 100);
  ASSERT_TRUE(ins.first->first);
  ASSERT_EQ(m[3], 100);

  ASSERT_EQ(m.size(), 4U);
}

TEST(map_erase, case13) {
  s21::map<int, int> m{{0, 10}, {1, 20}, {2, 30}};

  auto iter = m.begin();
  m.erase(iter);

  ASSERT_FALSE(m.contains(0));

  ASSERT_EQ(m.size(), 2U);
}

TEST(map_erase, case14) {
  s21::map<int, int> m{{0, 10}, {1, 20}, {2, 30}};

  auto iter = m.begin();
  iter++;
  m.erase(iter);

  ASSERT_FALSE(m.contains(1));

  ASSERT_EQ(m.size(), 2U);
}

TEST(map_erase, case15) {
  s21::map<int, int> m{{0, 10}, {1, 20}, {2, 30}};
  auto iter = m.begin();
  iter++;
  iter++;
  m.erase(iter);

  ASSERT_FALSE(m.contains(2));

  ASSERT_EQ(m.size(), 2U);
}

TEST(map_swap, case17) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};
  s21::map<int, int> map1 = {{1, 4}, {2, 5}, {3, 6}, {4, 7}};

  map.swap(map1);
  ASSERT_EQ(map.size(), (unsigned long)4);
  ASSERT_EQ(map1.size(), (unsigned long)3);
  ASSERT_EQ(map[4], 7);
  ASSERT_EQ(map1[3], 7);
}

TEST(map_merge, case18) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};
  s21::map<int, int> map1 = {{10, 4}, {11, 5}, {12, 6}, {13, 7}};

  map.merge(map1);
  ASSERT_EQ(map.size(), (unsigned long)7);
  ASSERT_EQ(map1.size(), (unsigned long)0);
  ASSERT_EQ(map[10], 4);
  ASSERT_EQ(map[11], 5);
  ASSERT_EQ(map[12], 6);
  ASSERT_EQ(map[13], 7);
  ASSERT_TRUE(map1.empty());

  //   for (auto& iter : map) {
  //     std::cout << iter.first << "\t" << iter.second << std::endl;
  //   }
}

TEST(map_merge, case19) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};
  s21::map<int, int> map1 = {{10, 4}, {2, 5}, {3, 6}, {13, 7}};

  map.merge(map1);

  ASSERT_EQ(map.size(), (unsigned long)5);
  ASSERT_EQ(map1.size(), (unsigned long)2);
  ASSERT_EQ(map[13], 7);
  ASSERT_EQ(map[3], 7);

  ASSERT_EQ(map1[2], 5);
  ASSERT_EQ(map1[3], 6);
}

TEST(map_at, case19) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};

  ASSERT_EQ(map.at(1), 4);
  ASSERT_EQ(map.at(2), 5);
  ASSERT_EQ(map.at(3), 7);
  EXPECT_THROW({ map.at(100); }, std::out_of_range);
}

TEST(map_move_operator, case20) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};
  s21::map<int, int> map1 = {{10, 4}, {2, 5}, {3, 6}, {13, 7}};
  s21::map<int, int> check = {{10, 4}, {2, 5}, {3, 6}, {13, 7}};

  map = std::move(map1);
  auto iter1 = map.begin();
  auto iter2 = check.begin();
  for (; iter1 != check.end(); iter1++, iter2++) {
    ASSERT_EQ(iter1->first, iter2->first);
    ASSERT_EQ(iter1->second, iter2->second);
  }

  auto emp = map1.begin();
  ASSERT_TRUE(map1.empty());
  ASSERT_TRUE(emp == nullptr);
}

TEST(map_index_operator, case21) {
  s21::map<int, int> map = {{1, 4}, {2, 5}, {3, 7}};

  ASSERT_EQ(map[1], 4);
  ASSERT_EQ(map[2], 5);
  ASSERT_EQ(map[3], 7);

  map[4] = 10;
  ASSERT_EQ(map.at(4), 10);
}