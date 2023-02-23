/*
  Implementation of methods for classes Response, AngryResponse, HappyResponse
*/
#include <iostream>
#include <string>
#include <algorithm>

#include "response.h"

using namespace std;

/*
  Implementation of Word class
  Don't worry too hard about these implementations.
  If you'd like to learn more about STL see: 
    https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
*/
string Word::upper()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

string Word::lower()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

/*
  Implementation of Response methods
*/
bool Response::checkAndRespond(const string& inWord, ostream& toWhere)
{
    size_t pos = inWord.find(this->keyword.upper());

    if (pos != std::string::npos) {
      this->respond(toWhere);
      return true;
    }

  return false;
}

void Response::respond(ostream& toWhere)
{
  toWhere << "I am neither angry nor happy: " << this->response << std::endl;
}


void AngryResponse::respond(ostream& toWhere)
{
  toWhere << "I am angry: " << this->response << std::endl;
}


void HappyResponse::respond(ostream& toWhere) 
{
  toWhere << "I am happy: " << this->response << std::endl;
}

