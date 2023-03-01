#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;


/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */

class KCipher : public Cipher {
protected:
   struct CipherCheshire;
   CipherCheshire *smile;

public:
   KCipher();
   KCipher(string page);
   void add_key(string page);
   void set_id(unsigned int page_number);
   string encrypt(string raw);
   string decrypt(string enc);
};

#endif