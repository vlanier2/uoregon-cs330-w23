#! /bin/bash

echo "TO FEW ARGS"
./a.out file_1.txt file_2.txt

#echo "TO MANY ARGS (CASE NOT HANDLED?)"
#./a.out nothing1.txt nothing2.txt nothing3.txt nothing4.txt

echo "FILES DONT EXIST"
./a.out nothing1.txt nothing2.txt

echo "FILE ONE DOESNT EXIST"
./a.out nothing1.txt file_1.txt out_no_file_1.txt

echo "FILE TWO DOESNT EXIST"
./a.out file_1.txt nothing2.txt out_no_file_2.txt

echo "FILE 1 IS SHORTER"
./a.out file_short.txt file_2.txt out_file_1_short.txt

echo "FILE 2 IS SHORTER" 
./a.out file_1.txt file_short.txt out_file_2_short.txt

echo "BOTH FILES EXIST AND SAME LENGTH"
./a.out file_1.txt file_2.txt out_file_3.txt

diff out_file_3.txt file_3.txt