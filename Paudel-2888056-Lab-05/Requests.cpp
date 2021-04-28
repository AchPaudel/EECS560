#include "Requests.h"
#include <iostream>

Requests::Requests(){

}

Requests::Requests(std::string first, std::string last, int priorityNum)
{
    firstName = first;
    lastName = last;
    priority = priorityNum;
}


bool Requests::operator<(const Requests& r) const
{
    return(this->priority < r.priority);
}

bool Requests::operator>(const Requests& r) const
{
    return(this->priority > r.priority);
}

Requests Requests::operator=(const Requests& r)
{
    this->firstName = r.firstName;
    this->lastName = r.lastName;
    this->priority = r.priority;
    return *this;
}


void Requests::printRequest()
{
    std::cout<<firstName<<" "<<lastName<<" with priority "<<priority<<std::endl;
}
