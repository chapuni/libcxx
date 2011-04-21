#include "new"

void
operator delete(void* ptr, const std::nothrow_t&) throw ()
{
    ::operator delete(ptr);
}
