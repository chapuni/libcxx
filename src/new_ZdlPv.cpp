#include <stdlib.h>

#include "new"

void
operator delete(void* ptr) throw ()
{
    if (ptr)
        ::free(ptr);
}
