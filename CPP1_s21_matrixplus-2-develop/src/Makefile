
CC = g++ 
SRC = s21_matrix_oop.cpp
OBJ = s21_matrix_oop.o
OBJ_TEST = s21_matrix_test.o
TARGET = s21_matrix_oop.a
FLAGS= -Wall -Werror -Wextra -std=c++17
TESTFLAGS= -pthread -lgtest -lgmock
CHECK_FLAG = -lstdc++
LCOVFLAGS = --no-external 
OPEN= open 
TEST_TARGET = testing_exe

OS := $(shell uname -s) 
ifeq ($(OS), Linux)
	OPEN = xdg-open
	TESTFLAGS= -pthread -lgtest -lgmock -lpthread
	FLAGS= -Wall -Werror -Wextra -std=c++17 -fPIC -fprofile-arcs -ftest-coverage -lstdc++fs
endif

all: clean gcov_report 

build: $(TARGET)

rebuild: clean $(TARGET)

$(TARGET):
	@$(CC) -c $(FLAGS) $(SRC) -o $(OBJ)
	@ar -rcs $(TARGET) $(OBJ)
	@ranlib $(TARGET)
	@rm -rf *.o
test: clean $(TARGET)
	@$(CC) $(FLAGS) -c test.cpp -o test.o
	@$(CC) $(FLAGS) $(CHECK_FLAG) test.o $(TARGET) $(TESTFLAGS) -o $(TEST_TARGET)
	@rm -rf *.o
	@./$(TEST_TARGET)

gcov_report: $(TARGET)
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@$(CC) --coverage $(FLAGS) test.cpp $(TESTFLAGS) s21_matrix_oop.cpp -o $(TEST_TARGET)
	@./$(TEST_TARGET)
	@lcov -t "test_coverage" -o test_coverage.info -c -d .
	@genhtml -o report test_coverage.info
	@open report/index.html
	@rm -rf *.gcda *.gcno test report/test_coverage.info


add_coverage_flag:
	$(eval FLAGS += --coverage)
clean: 
	@rm -rf *.out *.o *.gcno *.info s21_matrix_oop.a *.gcda *.a *.o *.txt
	@rm -rf report 
	@rm -rf $(TEST_TARGET)
leaks: 
	leaks -atExit --  ./$(TEST_TARGET)
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TEST_TARGET)

style_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -n *.cpp *.h
	@rm ./.clang-format

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.cpp *.h
	@rm ./.clang-format


.PHONY: all build rebuild clean test gcov_report style_check format_style valgrind leaks