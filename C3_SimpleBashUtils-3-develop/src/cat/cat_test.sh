#!/bin/bash

FOLDER_T="../test_samples" 

succes=0
fail=0

for file in $FOLDER_T/*.txt; do
	for flag in -b -e -n -s -t; do
		echo "Test with flag $flag on file $file"

		# cat эталонный
		cat $flag "$file" > expected_output.txt
		echo "Ожидаемый вывод:"
		cat expected_output.txt
		echo " "

		# s21_cat
		./s21_cat $flag "$file" > my_output.txt
		echo "Вывод s21_cat:"
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

rm my_output.txt expected_output.txt

# вывод результатов
echo ""
echo "---Итог теста---"
echo "Успешно: $succes"
echo "Не успешно: $fail"