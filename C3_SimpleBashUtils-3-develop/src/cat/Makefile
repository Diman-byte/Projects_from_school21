CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

all : s21_cat

rebuild : clean all

s21_cat : cat.c
	@ $(CC) $(CFLAGS) cat.c -o s21_cat

clean : 
	@ rm -rf s21_cat



