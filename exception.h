#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class DoneException {
  std::string s;
public:
  DoneException(std::string);
  std::string getErrorMessage();
};

#endif
