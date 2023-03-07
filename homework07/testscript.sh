#!/bin/bash

echo "STARTING TEST UNITTEST_T100"

rm myoutst100.txt

./bst -t 100 -s 100 >> myoutst100.txt

diff myoutst100.txt unittest_ans_t100_s100.txt

echo "STARTING TEST STUDENTS_1"

./bst -i students_1.txt -o myoutsstudents1.txt

diff myoutsstudents1.txt students_1_ans.txt