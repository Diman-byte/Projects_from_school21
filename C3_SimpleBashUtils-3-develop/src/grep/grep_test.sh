#!/bin/bash

FOLDER_T="../test_samples" 

succes=0
fail=0

for file in $FOLDER_T/*.txt; do
	for flag in -e -i -v -c -l -n; do
		for pat in a L "[0-2]"; do
			echo "Test with flag $flag pattern $pat on file $file"

			# grep эталонный
			grep $flag $pat "$file" > expected_output.txt
			echo "Ожидаемый вывод:"
			cat expected_output.txt
			echo " "

			# s21_grep
			./s21_grep $flag $pat "$file" > my_output.txt
			echo "Вывод s21_grep:"
			cat my_output.txt
			echo " "


			# сравнение результатов
			if diff -q my_output.txt expected_output.txt; then 
				succes=$((succes + 1))
				echo "Тест пройден"; 
			else 
				fail=$((fail + 1))
				echo "Тест не пройден"; 
			fi 


			echo "_____________________________________________"
		done
	done
done

# тест с несколькими шаблонами
echo "Test with flag -e pattern a, L, 1 on file test_1.txt"
# grep эталонный
grep -e a -e L -e 1  ../test_samples/test_1.txt > expected_output.txt
echo "Ожидаемый вывод:"
cat expected_output.txt
echo " "
# s21_grep
./s21_grep -e a -e L -e 1 ../test_samples/test_1.txt > my_output.txt
echo "Вывод s21_grep:"
cat my_output.txt
echo " "
# сравнение результатов
if diff -q my_output.txt expected_output.txt; then 
	succes=$((succes + 1))
	echo "Тест пройден"; 
else 
	fail=$((fail + 1))
	echo "Тест не пройден"; 
fi 



rm my_output.txt expected_output.txt

# вывод результатов
echo ""
echo "---Итог теста---"
echo "Успешно: $succes"
echo "Не успешно: $fail"