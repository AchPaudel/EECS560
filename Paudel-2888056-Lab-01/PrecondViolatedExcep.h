
#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public std::runtime_error
{
public:
   PrecondViolatedExcep(const string& message = ""): std::runtime_error(message.c_str()){}
}; // end PrecondViolatedExcep
#endif
