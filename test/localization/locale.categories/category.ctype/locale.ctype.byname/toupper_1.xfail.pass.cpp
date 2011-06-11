//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <locale>

// template <class charT> class ctype_byname;

// charT toupper(charT) const;

#include <locale>
#include <cassert>

int main()
{
    {
        std::locale l("en_US");
        {
            typedef std::ctype<char> F;
            const F& f = std::use_facet<F>(l);

            assert(f.toupper(' ') == ' ');
            assert(f.toupper('A') == 'A');
            assert(f.toupper('\x07') == '\x07');
            assert(f.toupper('.') == '.');
            assert(f.toupper('a') == 'A');
            assert(f.toupper('1') == '1');
            assert(f.toupper('\xDA') == '\xDA');
            assert(f.toupper('\xFA') == '\xFA');
        }
    }
    {
        std::locale l("C");
        {
            typedef std::ctype<char> F;
            const F& f = std::use_facet<F>(l);

            assert(f.toupper(' ') == ' ');
            assert(f.toupper('A') == 'A');
            assert(f.toupper('\x07') == '\x07');
            assert(f.toupper('.') == '.');
            assert(f.toupper('a') == 'A');
            assert(f.toupper('1') == '1');
            assert(f.toupper('\xDA') == '\xDA');
            assert(f.toupper('\xFA') == '\xFA');
        }
    }
    {
        std::locale l("en_US");
        {
            typedef std::ctype<wchar_t> F;
            const F& f = std::use_facet<F>(l);

            assert(f.toupper(L' ') == L' ');
            assert(f.toupper(L'A') == L'A');
            assert(f.toupper(L'\x07') == L'\x07');
            assert(f.toupper(L'.') == L'.');
            assert(f.toupper(L'a') == L'A');
            assert(f.toupper(L'1') == L'1');
            assert(f.toupper(L'\xDA') == L'\xDA');
            assert(f.toupper(L'\xFA') == L'\xDA');
        }
    }
    {
        std::locale l("C");
        {
            typedef std::ctype<wchar_t> F;
            const F& f = std::use_facet<F>(l);

            assert(f.toupper(L' ') == L' ');
            assert(f.toupper(L'A') == L'A');
            assert(f.toupper(L'\x07') == L'\x07');
            assert(f.toupper(L'.') == L'.');
            assert(f.toupper(L'a') == L'A');
            assert(f.toupper(L'1') == L'1');
            assert(f.toupper(L'\xDA') == L'\xDA');
            assert(f.toupper(L'\xFA') == L'\xFA');
        }
    }
}
