#include "Utils.hpp"

bool is_valid_input(const std::string& s1, const std::string& s2)
{
    if (s1.empty() || s2.empty())
    {
        std::cerr << "Error: s1 and s2 must not be empty." << std::endl;
        return false;
    }
    return true;
}

std::string replace_all(const std::string& content, const std::string& s1, const std::string& s2)
{
    std::string result;
    std::size_t pos = 0;
    bool found = true;

    while (found)
    {
        std::size_t match = content.find(s1, pos);

        if (match > content.length())
            found = false;
        else 
        {
            result.append(content, pos, match - pos);
            result.append(s2);
            pos = match + s1.length();
        }
    }
    result.append(content, pos, content.length() - pos);
    return result;
}