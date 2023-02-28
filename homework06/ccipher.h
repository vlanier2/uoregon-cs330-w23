#ifndef CCIPHER_H_
#define CCIPHER_H_
#include "cipher.h"

using namespace std;

/* A class that implements a
   Caesar cipher class. It 
   inherits the Cipher class */
// TODO: Implement this class

//struct CipherCheshire;

class CCipher : public Cipher {
public:
   CCipher();
   CCipher(int offset);
};

/* Helper function headers 
 */
void rotate_string(string& in_str, int rot);
void reverse_str_segment(string& in_str, unsigned int left, unsigned int right);
#endif

