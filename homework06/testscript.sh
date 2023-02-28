#!/bin/bash


echo "TEST 1 subs"
./cipher -ms -i test1/subs/substitution.txt -o testfile
diff test1/subs/substitution_out.txt testfile
rm testfile

echo "TEST 2 subs"
./cipher -ms -i test2/subs/substitution.txt -o testfile
diff test2/subs/substitution_out.txt testfile
rm testfile

echo "TEST 3 subs ERROR"
./cipher -ms -i test3_error/subs/substitution.txt -o testfile 2> errfile
diff test3_error/subs/cout_error errfile

echo "REALITY CHECK"
diff test1/subs/substitution_out.txt test1/subs/substitution.txt
