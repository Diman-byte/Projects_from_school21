CC = gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address

all : door_struct list_test

door_struct : dmanager_module.o
	$(CC) dmanager_module.c -o Quest_1
	@mv Quest_1 ../build/

list_test : list.o
	$(CC) -D LIST_TEST list.c list_test.c -o Quest_2
	@mv Quest_2 ../build/

rebuild_door_struct : clean_1 door_struct
	
rebuild_list_test : clean_2 list_test

clean : clean_1 clean_2

clean_1 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_1

clean_2 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_2

