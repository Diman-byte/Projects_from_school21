FLAGS=-Wall -Werror -Wextra -std=c11
FLAGS_GCOV=-Wall -Werror -Wextra -std=c11 --coverage
GCOV_FILTER=--filter functions/ --filter sscanf/ --filter sprintf/ --filter C_sharp/

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	FLAGS +=  -lsubunit
	FLAGS_GCOV += -lsubunit
endif

all: clean s21_string.a
deafult: all

s21_string.o: functions/*.c sprintf/*.c sscanf/*.c C_sharp/*.c
	gcc $(FLAGS) -c $^ -I functions -I sprintf

s21_string.a: s21_string.o
	ar cr s21_string.a *.o

clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda s21_test report

format:
	clang-format -i *.c *.h 

test: clean
	gcc $(FLAGS) -o s21_test  s21_test.c tests/*.c functions/*.c sprintf/*.c sscanf/*.c C_sharp/*.c -I functions -I sprintf -I sscanf -I C_sharp -lcheck -lm -lsubunit
	./s21_test 

test_gcov: clean
	gcc $(FLAGS_GCOV) -o s21_test  s21_test.c tests/*.c functions/*.c sprintf/*.c sscanf/*.c C_sharp/*.c -I functions -I sprintf -I sscanf -I C_sharp -lcheck -lm -lsubunit
	./s21_test 

gcov_report: test_gcov
	mkdir -p report
	gcov s21_*.gcda
	gcovr --html --html-details $(GCOV_FILTER) -o report/gcov_report.html
	open report/gcov_report.html || true
