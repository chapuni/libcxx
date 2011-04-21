//===--------------------------- new.cpp ----------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <stdlib.h>

#include "new"

#if __APPLE__
    #include <cxxabi.h>
    // On Darwin, there are two STL shared libraries and a lower level ABI
    // shared libray.  The global holding the current new handler is
    // in the ABI library and named __cxa_new_handler.
    #define __new_handler __cxxabiapple::__cxa_new_handler
#else  // __APPLE__
    _LIBCPP_BEGIN_NAMESPACE_STD
        ::std::new_handler __new_handler;
    _LIBCPP_END_NAMESPACE_STD
#endif

#if 0
// Implement all new and delete operators as weak definitions
// in this shared library, so that they can be overriden by programs
// that define non-weak copies of the functions.
#endif

namespace std
{

const nothrow_t nothrow = {};

new_handler
set_new_handler(new_handler handler) throw()
{
    return __sync_lock_test_and_set(&__new_handler, handler);
}

new_handler
get_new_handler() throw()
{
    return __sync_fetch_and_add(&__new_handler, (new_handler)0);
}

bad_alloc::bad_alloc() throw()
{
}

bad_alloc::~bad_alloc() throw()
{
}

const char*
bad_alloc::what() const throw()
{
    return "std::bad_alloc";
}

bad_array_new_length::bad_array_new_length() throw()
{
}

bad_array_new_length::~bad_array_new_length() throw()
{
}

const char*
bad_array_new_length::what() const throw()
{
    return "bad_array_new_length";
}

void
__throw_bad_alloc()
{
#ifndef _LIBCPP_NO_EXCEPTIONS
    throw bad_alloc();
#endif
}

}  // std
