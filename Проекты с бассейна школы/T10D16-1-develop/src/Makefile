CC = gcc -Wall -Wextra -Werror -std=c11

all : strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

strlen_tests : s21_string.o
	$(CC) -D STRLEN_TEST s21_string.c s21_string_test.c -o Quest_1
	@ mv Quest_1 ../build/

strcmp_tests : s21_string.o
	$(CC) -D STRCMP_TEST s21_string.c s21_string_test.c -o Quest_2
	@ mv Quest_2 ../build/

strcpy_tests : s21_string.o
	$(CC) -D STRCPY_TEST s21_string.c s21_string_test.c -o Quest_3
	@ mv Quest_3 ../build/

strcat_tests : s21_string.o
	$(CC) -D STRCAT_TEST s21_string.c s21_string_test.c -o Quest_4
	@ mv Quest_4 ../build/

strchr_tests : s21_string.o
	$(CC) -D STRCHR_TEST s21_string.c s21_string_test.c -o Quest_5
	@ mv Quest_5 ../build/


clean : clean_1 clean_2 clean_3 clean_4 clean_5

clean_1 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_1

clean_2 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_2

clean_3 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_3

clean_4 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_4

clean_5 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_5


