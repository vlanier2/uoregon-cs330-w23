#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"

using namespace std;

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------
// struct VCipher::CipherCheshire {
//     string cipher_alpha;
//     vector<string> cipher_book;
//     unsigned int page_id;
// };

string validate_and_convert_key(string in_str, unsigned int max_length);

VCipher::VCipher() : KCipher() {}

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