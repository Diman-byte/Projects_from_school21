CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

all : s21_grep

rebuild : clean all

s21_grep : grep.c
	@ $(CC) $(CFLAGS) grep.c -o s21_grep

clean : 
	@ rm -rf s21_grep


