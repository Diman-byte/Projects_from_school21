CC = gcc
COMMON_FLAGS = -Wall -Werror -Wextra -lm -lpthread -fprofile-arcs -ftest-coverage -lcheck
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: clean s21_math.a test gcov_report

MATH_FLAGS = -Wall -Werror -Wextra -lm

s21_math.a: s21_math.o
	ar rcs $@ $^

test: s21_math.c test_math.c
	$(CC) $(COMMON_FLAGS) -o $@ $^
	./test
	mv test-s21_math.gcno test_math.gcno
	mv test-s21_math.gcda test_math.gcda


s21_math.o: s21_math.c
	$(CC) $(MATH_FLAGS) -c -o $@ $<

gcov_report: test
	gcov -r test_math.c
	mkdir -p gcov-report
	gcovr -r . --html --html-details -o gcov-report/index.html

clean:
	rm -f s21_math.a *.o *.gcno *.gcda *.gcov ./test
	rm -rf gcov-report/

rebuild: clean all

.PHONY: all clean test s21_math.a gcov_report
