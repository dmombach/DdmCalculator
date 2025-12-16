#include "StringUtil.h"
#include <algorithm>
#include <cctype>

namespace StringUtil
{
    std::string trim(const std::string& s)
    {
        auto start = s.begin();
        while (start != s.end() && std::isspace(*start)) ++start;

        auto end = s.end();
        while (end != start && std::isspace(*(end - 1))) --end;

        return std::string(start, end);
    }

    std::string toLower(const std::string& input)
    {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });

        return result;
    }
}