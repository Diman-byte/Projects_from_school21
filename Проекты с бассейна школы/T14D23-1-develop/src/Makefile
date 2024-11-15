CC = gcc -Wall -Wextra -Werror -std=c11 -fsanitize=address

all : state_sort state_search clear_state

state_sort : state_sort.o
	$(CC) state_sort.c -o Quest_1
	@ mv Quest_1 ../build/

state_search : state_search.o
	$(CC) state_search.c -o Quest_2
	@ mv Quest_2 ../build/

clear_state : clear_state.o
	$(CC) clear_state.c -o Quest_3
	@ mv Quest_3 ../build/

rebuild_state_sort : clean state_sort

rebuild_state_search : clean state_search

rebuild_clear_state : clean clear_state

clean : clean_1 clean_2 clean_3

clean_1 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_1

clean_2 : 
	@ rm -rf *.o
	@ rm -rf ../build/Quest_2

clean_3 :
	@ rm -rf *.o
	@ rm -rf ../build/Quest_3
