#include "new"

void
operator delete[] (void* ptr) throw ()
{
    ::operator delete (ptr);
}
