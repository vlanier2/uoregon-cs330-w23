#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"

using namespace std;

// We need a second smile to keep track of the 
// key pages and the current page selected
struct KCipher::CipherCheshire {
    vector<string> cipher_book;
    unsigned int page_id;
};

struct Cipher::CipherCheshire {
    string cipher_alpha;
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

bool is_alpha_char(char c)
{
    return (c >= 'a') && (c <= 'z');
}

bool is_key_valid(string key) {
    for (char c: key) {
        if (!is_alpha_char(c)) return false;
    }
    return true;
}

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

void KCipher::add_key(string page) {

    string temp = remove_spaces(page);

    // if the key is empty or contains invalid chars exit
    if (temp == "" || !is_key_valid(temp)) {
        cerr << "Invalid Running key: " << page << endl;
        exit(EXIT_FAILURE);
    }

    ksmile->cipher_book.push_back(page);
}

void KCipher::set_id(unsigned int page_number) {
    ksmile->page_id = page_number;
}

KCipher::KCipher() : Cipher() {
    ksmile = new KCipher::CipherCheshire; // create second smile

    // a key of all 'A' will map to the unshifted alphabet in the tabula recta
    this->add_key(string(MAX_LENGTH, 'a')); 
    this->set_id(0);
}

KCipher::KCipher(string page) {

    ksmile = new KCipher::CipherCheshire; // create second smile
    this->add_key(page);
    this->set_id(0);
}

// new destructor is needed. as discussed in class no need to deal with the
// first smile as the destructor for the base class will be called prior to the
// destructor of the derived class
KCipher::~KCipher() {
    delete ksmile;
}

string KCipher::encrypt(string raw) {

    if (ksmile->page_id > ksmile->cipher_book.size() - 1) { // page id does not exist
        cerr << "Warning: invalid id: " << ksmile->page_id << endl;
        exit(EXIT_FAILURE);
    }

    // Technically I dont need to remove all the spaces from the raw and key.
    // I would just need to count the number of spaces and make a bit more 
    // complicated iteration later on. I am leaving this for the sake of time
    // constraints, but it could be optimized later.
    string raw_no_spaces = remove_spaces(raw);
    string key_page = remove_spaces(ksmile->cipher_book[ksmile->page_id]);

    if (raw_no_spaces.length() > key_page.length()) { // key is too short
        cerr << "Invalid Running key: " << ksmile->cipher_book[ksmile->page_id] << endl;
    }

    cout << "Encrypting...";

    string retStr;
    string tableau;
    char enc_char;

    // using some iterators for convienence. This is compiling with the makefile, so
    // hopefully it is ok.
    string::iterator raw_iter, page_iter;
    raw_iter = raw.begin();
    page_iter = key_page.begin();
    
    while (*raw_iter) {
        if (*raw_iter == ' ') { // insert space if needed
            retStr += ' ';
            raw_iter++;
        } else { // encrypt with 'on the fly' tableau discussed in class
            tableau = smile->cipher_alpha;
            rotate_string(tableau, (toupper(*page_iter) - 'A')); // rotate by page char

            enc_char = tableau[toupper(*raw_iter) - 'A']; // index by raw char
            retStr += isupper(*raw_iter) ? toupper(enc_char) : enc_char; // handle case

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
    
    string key_page = remove_spaces(ksmile->cipher_book[ksmile->page_id]);
    enc_iter = enc.begin();
    page_iter = key_page.begin();

    while(*enc_iter) {  // decrypted using 'math' method. Hopefully this is ok. 
                        // I thought it was interesting to work out.
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

    return retStr;
}