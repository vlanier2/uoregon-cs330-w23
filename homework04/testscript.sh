#!/bin/bash

echo "TEST ONE"

echo "START AT ONE"
./bfs test1/test1.txt 1

diff distance_1_LL.txt test1/ans_1.txt

echo "START AT SIX"
./bfs test1/test1.txt 6

diff distance_6_LL.txt test1/ans_6.txt


echo "TEST TWO"

echo "START AT NINE"
./bfs test2/test2.txt 9

diff distance_9_LL.txt test1/ans_9.txt


echo "START AT SEVENTY FIVE"
./bfs test2/test2.txt 75

diff distance_75_LL.txt test1/ans_75.txt
