#include "exception.h"
#include <string>
using std::string;

string DoneException::getErrorMessage(){
  return s;
}

DoneException::DoneException(std::string s) : s{s} {}
