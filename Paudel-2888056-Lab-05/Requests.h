#ifndef REQUESTS_H
#define REQUESTS_H
#include <string>

class Requests
{
public:
    Requests();
    Requests(std::string firstName, std::string lastName, int priority);
    //Requests(const Requests& copy):firstName(copy.firstName), lastName(copy.lastName), priority(copy.priority){}
    bool operator< (const Requests& r) const;
    bool operator> (const Requests& r) const;
    Requests operator= (const Requests& r);
    void printRequest();
private:
    std::string firstName;
    std::string lastName;
    int priority;
};
#endif
