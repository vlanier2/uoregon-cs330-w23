#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"

using namespace std;

struct KCipher::CipherCheshire {
    string cipher_alpha;
    vector<string> cipher_book;
    unsigned int page_id;
};

/* Helper function definitions
 */
string remove_spaces(string in_str) {
    string temp = "";
    
    for (char c : in_str) {
        if (c != ' ')
            temp += c; 
    }

    return temp;
} 

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

void KCipher::add_key(string page) {
    string temp = remove_spaces(page);
    if (temp == "") {
        cerr << "Invalid Running key: " << temp << endl; 
        exit(EXIT_FAILURE);
    }

    smile->cipher_book.push_back(page);
}

void KCipher::set_id(unsigned int page_number) {
    smile->page_id = page_number;
}

KCipher::KCipher() {
    smile = new KCipher::CipherCheshire;
    smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
    this->add_key(string(MAX_LENGTH, 'A'));
    this->set_id(0);
}

KCipher::KCipher(string page) {

    smile = new KCipher::CipherCheshire;
    smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";    
    smile->cipher_book = vector<string>();

    this->add_key(page);
    this->set_id(0);
}

string KCipher::encrypt(string raw) {

    if (smile->page_id > smile->cipher_book.size()) {
        cerr << "Warning: invalid id: " << smile->page_id << endl;
        exit(EXIT_FAILURE);
    }

    string raw_no_spaces = remove_spaces(raw);
    string key_page = remove_spaces(smile->cipher_book[smile->page_id]);

    if (raw_no_spaces.length() > key_page.length()) {
        cerr << "Invalid Running key: " << smile->cipher_book[smile->page_id] << endl;
    }

    cout << "Encrypting...";

    string retStr;
    string tableau;
    char enc_char;

    string::iterator raw_iter, page_iter;
    raw_iter = raw.begin();
    page_iter = key_page.begin();
    
    while (*raw_iter) {
        if (*raw_iter == ' ') {
            retStr += ' ';
            raw_iter++;
        } else {
            tableau = smile->cipher_alpha;
            rotate_string(tableau, (toupper(*page_iter) - 'A'));

            enc_char = tableau[toupper(*raw_iter) - 'A'];
            retStr += isupper(*raw_iter) ? toupper(enc_char) : enc_char;

            raw_iter++;
            page_iter++;
        }
    }
    cout << "Done" << endl;

    return retStr;
}

string KCipher::decrypt(string enc) {

    cout << "Decrypting...";

    char dec_char;
    string retStr;
    string::iterator enc_iter, page_iter;
    
    string key_page = remove_spaces(smile->cipher_book[smile->page_id]);
    enc_iter = enc.begin();
    page_iter = key_page.begin();

    while(*enc_iter) {
        if (*enc_iter == ' ') {
            retStr += ' ';
            enc_iter++;
        } else {
            dec_char = 'A' + (toupper(*enc_iter) - toupper(*page_iter) + 26) % 26;
            retStr += isupper(*enc_iter) ? dec_char : tolower(dec_char);
            enc_iter++;
            page_iter++;
        }
    }
    
    cout << "Done" << endl;

    //cout << retStr << endl;

    return retStr;
}