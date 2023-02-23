#!/bin/bash

echo "TEST ONE"

./ai test1/input.txt test1/message.txt test1_out.txt

diff test1_out.txt test1/result.txt


echo "TEST TWO"

./ai test2/input.txt test2/message.txt test2_out.txt

diff test2_out.txt test2/result.txt


echo "REALITY CHECK"

diff test2_out.txt test1/result.txt
