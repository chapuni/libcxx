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

// iter_type
// get_date(iter_type s, iter_type end, ios_base& str,
//          ios_base::iostate& err, tm* t) const;

#include <locale>
#include <cassert>
#include "iterators.h"

typedef input_iterator<const char*> I;

typedef std::time_get_byname<char, I> F;

class my_facet
    : public F
{
public:
    explicit my_facet(const std::string& nm, std::size_t refs = 0)
        : F(nm, refs) {}
};

int main()
{
    std::ios ios(0);
    std::ios_base::iostate err;
    std::tm t;
    {
        const my_facet f("en_US", 1);
        const char in[] = "06/10/2009";
        err = std::ios_base::goodbit;
        t = std::tm();
        I i = f.get_date(I(in), I(in+sizeof(in)/sizeof(in[0])-1), ios, err, &t);
        assert(i.base() == in+sizeof(in)/sizeof(in[0])-1);
        assert(t.tm_mon == 5);
        assert(t.tm_mday == 10);
        assert(t.tm_year == 109);
        assert(err == std::ios_base::eofbit);
    }
    {
        const my_facet f("fr_FR", 1);
        const char in[] = "10.06.2009";
        err = std::ios_base::goodbit;
        t = std::tm();
        I i = f.get_date(I(in), I(in+sizeof(in)/sizeof(in[0])-1), ios, err, &t);
        assert(i.base() == in+sizeof(in)/sizeof(in[0])-1);
        assert(t.tm_mon == 5);
        assert(t.tm_mday == 10);
        assert(t.tm_year == 109);
        assert(err == std::ios_base::eofbit);
    }
    {
        const my_facet f("ru_RU", 1);
        const char in[] = "10.06.2009";
        err = std::ios_base::goodbit;
        t = std::tm();
        I i = f.get_date(I(in), I(in+sizeof(in)/sizeof(in[0])-1), ios, err, &t);
        assert(i.base() == in+sizeof(in)/sizeof(in[0])-1);
        assert(t.tm_mon == 5);
        assert(t.tm_mday == 10);
        assert(t.tm_year == 109);
        assert(err == std::ios_base::eofbit);
    }
    {
        const my_facet f("zh_CN", 1);
        const char in[] = "2009/06/10";
        err = std::ios_base::goodbit;
        t = std::tm();
        I i = f.get_date(I(in), I(in+sizeof(in)/sizeof(in[0])-1), ios, err, &t);
        assert(i.base() == in+sizeof(in)/sizeof(in[0])-1);
        assert(t.tm_mon == 5);
        assert(t.tm_mday == 10);
        assert(t.tm_year == 109);
        assert(err == std::ios_base::eofbit);
    }
}
