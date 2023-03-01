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
rm errfile

echo "TEST 1 caesar"
./cipher -mc -i test1/caesar/caesar.txt -o testfile
diff test1/caesar/caesar_out.txt testfile
rm testfile

echo "TEST 2 caesar"
./cipher -mc -i test2/caesar/caesar.txt -o testfile
diff test2/caesar/caesar_out.txt testfile
rm testfile

echo "TEST 3 caesar ERROR"
./cipher -mc -i test3_error/caesar/caesar.txt -o testfile 2> errfile
diff test3_error/caesar/cout_error errfile
rm errfile

echo "TEST 1 ROT13"
./cipher -mr -i test1/rot13/rot13.txt -o testfile
diff test1/rot13/rot13_out.txt testfile
rm testfile

echo "TEST 2 ROT13"
./cipher -mr -i test2/rot13/rot13.txt -o testfile
diff test2/rot13/rot13_out.txt testfile
rm testfile

# _______________________________________

echo "TEST 1 Running Key"
./cipher -mk -i test1/running_key/running_key.txt -o testfile
diff test1/running_key/running_key_out.txt testfile
rm testfile

echo "TEST 2 Running Key"
./cipher -mk -i test2/running_key/running_key.txt -o testfile
diff test2/running_key/running_key_out.txt testfile
rm testfile

echo "TEST 3 Running Key ERROR"
./cipher -mk -i test3_error/running_key/running_key_1.txt -o testfile 2> errfile
diff test3_error/running_key/cout_error_1 errfile
rm errfile

./cipher -mk -i test3_error/running_key/running_key_2.txt -o testfile 2> errfile
diff test3_error/running_key/cout_error_2 errfile
rm errfile

./cipher -mk -i test3_error/running_key/running_key_3.txt -o testfile 2> errfile
diff test3_error/running_key/cout_error_3 errfile
rm errfile

# _______________________________________


echo "TEST 1 Vigenere"
./cipher -mv -i test1/vigenere/vigenere.txt -o testfile
diff test1/vigenere/vigenere_out.txt testfile
rm testfile

echo "TEST 2 Vigenere"
./cipher -mv -i test2/vigenere/vigenere.txt -o testfile
diff test2/vigenere/vigenere_out.txt testfile
rm testfile

echo "TEST 3 Vigenere ERROR"
./cipher -mv -i test3_error/vigenere/vigenere.txt -o testfile 2> errfile
diff test3_error/vigenere/cout_error errfile
rm errfile

# _______________________________________


echo "REALITY CHECK"
diff test1/subs/substitution_out.txt test1/subs/substitution.txt
