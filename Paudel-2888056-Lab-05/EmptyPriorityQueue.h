#ifndef EMPTYPRIORITYQUEUE_H
#define EMPTYPRIORITYQUEUE_H
#include <stdexcept>
#include <string>

class EmptyPriorityQueue: public std::runtime_error
{
public:
    EmptyPriorityQueue(const std::string& message): runtime_error("Empty Priority Queue Error: " + message) {}
};
#endif
