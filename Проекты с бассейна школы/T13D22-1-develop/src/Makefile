CC = gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address

all : cipher

cipher : cipher.o
	$(CC) cipher.c -o cipher
	@mv cipher ../build/

rebuild: clean cipher

clean : 
	@ rm -rf *.o
	@ rm -rf ../build/cipher