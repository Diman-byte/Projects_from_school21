G++ = g++ -Wall -Werror -Wextra -std=c++17
GCOV_FLAGS= --coverage
GTEST = -lgtest -lpthread

all: test

test: clean
	$(G++) tests/test_*.cpp -o test $(GTEST)
	./test

gcov_report: clean 
	$(G++) tests/test_*.cpp -o test $(GTEST) $(GCOV_FLAGS)
	./test
	rm -rf tests.gcda
	lcov -t "report" -o report.info --no-external -c -d .
	genhtml  -o ./report report.info
	rm -rf *.gcda *.gcno *.info

clean:
	rm -rf ./test ./a.out *.gcda *.gcno coverage.info report

clang:
	clang-format -n -style=Google *.h *.tpp tests/*.cpp tests/*.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test 
