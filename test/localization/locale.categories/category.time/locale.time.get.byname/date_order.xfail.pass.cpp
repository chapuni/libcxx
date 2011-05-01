//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// class time_get_byname<charT, InputIterator>

// dateorder date_order() const;

#include <locale>
#include <cassert>
#include "iterators.h"

typedef std::time_get_byname<char, input_iterator<const char*> > F;

class my_facet
    : public F
{
public:
    explicit my_facet(const std::string& nm, std::size_t refs = 0)
        : F(nm, refs) {}
};

int main()
{
    {
        const my_facet f("en_US", 1);
        assert(f.date_order() == std::time_base::mdy);
    }
    {
        const my_facet f("fr_FR", 1);
        assert(f.date_order() == std::time_base::dmy);
    }
    {
        const my_facet f("ru_RU", 1);
        assert(f.date_order() == std::time_base::dmy);
    }
    {
        const my_facet f("zh_CN", 1);
        assert(f.date_order() == std::time_base::ymd);
    }
}
