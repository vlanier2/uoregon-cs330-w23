#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"

using namespace std;

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

string validate_and_convert_key(string in_str, unsigned int max_length);

VCipher::VCipher() : KCipher() {}

// Using this helper function to validate and convert the keyword to a 'key_page'
// allows me to avoid redefining the cheshire here. I think it looks pretty clean, 
// but im not sure if its good practice. Let me know if you are reading this and
// have some time.
VCipher::VCipher(string keyword) : KCipher(validate_and_convert_key(keyword, MAX_LENGTH)) {}

string validate_and_convert_key(string in_str, unsigned int max_length) {
    
    if (!is_key_valid(in_str)) {
        cerr << "Error: not a valid Vigenere key word" << endl;
        exit(EXIT_FAILURE);
    }
    
    string ret_str;
    while(ret_str.length() < max_length) {
        ret_str.append(in_str);
    }
    return ret_str;
}