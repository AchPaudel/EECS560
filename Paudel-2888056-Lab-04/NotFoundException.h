#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include<stdexcept>
#include<string>

class NotFoundException: public std::runtime_error
{
public:
    NotFoundException(const std::string& message): runtime_error("ERROR: " + message) {}
};
#endif
