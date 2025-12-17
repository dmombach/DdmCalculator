#include "StringUtil.h"
#include <iostream>
#include <cassert>

int main()
{
    // --- toLower tests ---
    assert(StringUtil::toLower("HELLO") == "hello");
    assert(StringUtil::toLower("HeLLo") == "hello");
    assert(StringUtil::toLower("hello") == "hello");

    // --- trim tests ---
    assert(StringUtil::trim("    hello    ") == "hello");
    assert(StringUtil::trim("world") == "world");
    assert(StringUtil::trim("    spaced out") == "spaced out");
    assert(StringUtil::trim("no-space") == "no-space");

    std::cout << "All StringUtil tests passed!" << std::endl;

    return 0;
}