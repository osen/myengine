#ifndef MYENGINE_EXCEPTION_H
#define MYENGINE_EXCEPTION_H

#include <exception>
#include <string>

namespace myengine
{

struct Exception : public std::exception
{
  Exception(const std::string& message);
  virtual ~Exception() throw();
  virtual const char* what() const throw();

private:
  std::string message;

};

}

#endif
