#include "new"

void*
operator new[](size_t size) throw (std::bad_alloc)
{
    return ::operator new(size);
}
