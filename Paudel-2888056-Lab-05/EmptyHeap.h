#ifndef EMPTYHEAP_H
#define EMPTYHEAP_H
#include <stdexcept>
#include <string>

class EmptyHeap: public std::runtime_error
{
public:
    EmptyHeap(const std::string& message): runtime_error("Empty Heap Error: " + message) {}
};
#endif
