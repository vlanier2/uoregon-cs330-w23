#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"

// -------------------------------------------------------
// Caesar Cipher implementation

struct CCipher::CipherCheshire {
    string cipher_alpha;
};

CCipher::CCipher() : Cipher() {}

CCipher::CCipher(int offset) : Cipher() {

    if (offset < 0) {
        cerr << "Error: Caesar cipher is less than 0" << endl;
        exit(EXIT_FAILURE);
    }

    rotate_string(smile->cipher_alpha, offset);
}

// -------------------------------------------------------

// Reverses a string segment given by left : right
void reverse_str_segment(string& in_str, unsigned int left, unsigned int right) {
    unsigned int mid = ((right - left) / 2) + left;
    char temp;
    for (unsigned int i = left; i <= mid; ++i) {
        temp = in_str[i];
        in_str[i] = in_str[right];
        in_str[right] = temp;
        right--;
    }
}

// Rotates the input string in_str by rot positions
// uses fast rotation algorithm discussed in class
void rotate_string(string& in_str, int rot)
{
    unsigned int alpha_len = in_str.length();
    unsigned int split_index = rot % alpha_len;

    if (split_index == 0)
        return;   

    reverse_str_segment(in_str, 0, split_index - 1);
    reverse_str_segment(in_str, split_index, alpha_len - 1);
    reverse_str_segment(in_str, 0, alpha_len - 1);
}
