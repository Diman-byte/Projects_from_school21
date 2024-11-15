CC = gcc -Wall -Wextra -Werror -std=c11

all : main_executable_module.o data_io.o data_stat.o data_process.o decision.o sort.o

build : main_executable_module.o data_io.o data_stat.o data_process.o decision.o sort.o
	$(CC) main_executable_module.o data_io.o data_process.o data_stat.o decision.o sort.o -o Quest_3
	@mv Quest_3 ../../build/

build_with_static : data_stat.a main_executable_module.o data_io.o data_process.o decision.o sort.o
	$(CC) data_stat.a main_executable_module.o data_io.o data_process.o decision.o sort.o -o Quest_5
	@mv Quest_5 ../../build/

build_with_dynamic : data_process.so main_executable_module.o data_io.o decision.o sort.o
	$(CC) -DDYNYMIC_LIBRARY data_process.so main_executable_module.o data_io.o decision.o sort.o -o Quest_6
	@mv Quest_6 ../../build/
	@mv data_process.so ../../build/

rebuild : 	clean_quest_3 build

rebuild_with_static : 	clean_quest_5 build_with_static

rebuild_with_dynamic : 	clean_quest_6 build_with_dynamic

main_executable_module.o : main_executable_module.c
	$(CC) -c main_executable_module.c -o main_executable_module.o

data_io.o : ../data_libs/data_io.c	
	$(CC) -c ../data_libs/data_io.c -o data_io.o

data_stat.o : ../data_libs/data_stat.c
	$(CC) -c ../data_libs/data_stat.c -o data_stat.o

data_process.o : ../data_module/data_process.c
	$(CC) -c ../data_module/data_process.c -o data_process.o

decision.o : ../yet_another_decision_module/decision.c
	$(CC) -c ../yet_another_decision_module/decision.c -o decision.o

sort.o : sort.c
	$(CC) -c sort.c -o sort.o

data_stat.a : data_stat.o
	@ ar r data_stat.a data_stat.o

data_process.so : 
	@ $(CC) -c ../data_libs/data_stat.c ../data_module/data_process.c
	@ $(CC) -shared -o data_process.so data_process.o data_stat.o
	@ $(CC) -shared -o ../../build/data_process.so data_process.o data_stat.o

clean : clean_quest_3 clean_quest_5 clean_quest_6

clean_quest_3 : 
	@ rm -rf *.o
	@ rm -rf ../../build/Quest_3

clean_quest_5 :
	@ rm -rf *.o
	@ rm -rf *.a
	@ rm -rf ../../build/Quest_5

clean_quest_6 :
	@ rm -rf *.o
	@ rm -rf *.so
	@ rm -rf ../../build/*.so
	@ rm -rf ../../build/Quest_6

run :
	../../build/Quest_6








