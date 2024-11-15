CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TST_LIBS = -lcheck -lsubunit -lm

BACK=$(wildcard brick_game/tetris/backend/*.c)
FRONT=$(wildcard gui/cli/*.c)
TEST=$(wildcard brick_game/tetris/tests/check.c)

all: install

mkbuild:
	@rm -rf build/
	@mkdir build

uninstall :
	@rm -rf build/
	@echo "┏=========================================┓"
	@echo "┃             Game uninstall              ┃"
	@echo "┗=========================================┛"

install : mkbuild main
	@echo "┏=========================================┓"
	@echo "┃              Game install               ┃"
	@echo "┗=========================================┛"

back_lib : 
	@$(CC) -c $(FLAGS) $(BACK) -lncurses
	@ar -rcs build/back.a *.o
	@rm *.o

front_lib:
	@$(CC) -c $(FLAGS) -D_POSIX_C_SOURCE=199309L $(FRONT) -o gui/cli/frontend.o -lncurses
	@ar -rcs build/front.a gui/cli/frontend.o
	@rm gui/cli/*.o

main: back_lib front_lib
	@$(CC) -c $(FLAGS) tetris.c -o tetris.o
	@$(CC) $(FLAGS) tetris.o -L. build/front.a build/back.a -o build/Tetris -lncurses
	@rm tetris.o

dvi:
	@doxygen .Doxyfile
	@open doxygen/html/index.html

dist: install
	@rm -rf dist.tar.gz
	@tar -cvzf dist.tar.gz build/Tetris	

style_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@find ./ -name "*.c" -o -name "*.h" | xargs clang-format -n
	@rm ./.clang-format

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@find ./ -name "*.c" -o -name "*.h" | xargs clang-format -i
	@rm ./.clang-format

clean :
	@echo "Deleting unnecessary files..."
	@rm -rf brick_game/tetris/backend/*.o gui/cli/*.o build/ *.dSYM doxygen/ brick_game/tetris/backend/*.gcda brick_game/tetris/backend/*.gcno *.gcda *gcno *.info .saveScore.txt report/ TEST dist.tar.gz

add_coverage_flag:
	$(eval FLAGS += --coverage)

test : clean mkbuild back_lib
	@$(CC) -c $(FLAGS) $(TST_LIBS) $(TEST) -o test.o
	@$(CC) $(FLAGS) test.o -L. build/back.a $(TST_LIBS) -o TEST -lncurses
	@rm test.o
	@./TEST

# смотрим покрытие только back части
#Вместо того чтобы использовать --no-external, можно точнее указать, какие файлы включать в отчет, с помощью флага --extract.
gcov_report: add_coverage_flag clean
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@$(CC) $(FLAGS) -D_POSIX_C_SOURCE=199309L $(TEST) $(TST_LIBS) $(BACK) -o TEST -lncurses
	@./TEST
	@lcov --capture --directory . --output-file test_coverage.info
	@lcov --extract test_coverage.info "*/brick_game/tetris/backend/*" -o test_coverage.info
	@genhtml -o report test_coverage.info
	@open report/index.html


# проверка всего 
# gcov_report: clean mkbuild back_lib
# 	@$(CC) --coverage $(FLAGS) -D_POSIX_C_SOURCE=199309L $(TEST) $(TST_LIBS) $(FRONT) $(BACK) -o TEST -lncurses
# 	@./TEST
# 	@lcov -t "test_coverage" -o test_coverage.info -c -d .
# 	@genhtml -o report test_coverage.info
# 	@open report/index.html

leaks:
	leaks -atExit -- ./TEST

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./TEST

.PHONY: all mkbuild install ininstall clean dvi dist test gcov_report style_check valgrind