#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static bool is_valid_input(const std::string& s1, const std::string& s2)
{
    if (s1.empty() || s2.empty())
    {
        std::cerr << "Error: s1 and s2 must not be empty." << std::endl;
        return false;
    }
    return true;
}

static std::string replace_all(const std::string& content, const std::string& s1, const std::string& s2)
{
    std::string result;
    std::size_t pos = 0;
    bool found = true;

    while (found)
    {
        std::size_t match = content.find(s1, pos);

        if (match > content.length())
        {
            found = false;
        }
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

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <file> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = av[1];
    const std::string s1 = av[2];
    const std::string s2 = av[3];

    if (!is_valid_input(s1, s2))
        return 1;

    std::ifstream in(filename.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    if (in.fail() && !in.eof())
    {
        std::cerr << "Error: Failed while reading file '" << filename << "'." << std::endl;
        return 1;
    }
    const std::string content = buffer.str();
    in.close();

    const std::string replaced = replace_all(content, s1, s2);
    std::ofstream out((filename + ".replace").c_str());
    if (!out.is_open())
    {
        std::cerr << "Error: Could not open output file '" << filename << ".replace' for writing." << std::endl;
        return 1;
    }
    out << replaced;
    if (out.fail())
    {
        std::cerr << "Error: Failed while writing to file '" << filename << ".replace'." << std::endl;
        return 1;
    }

    return 0;
}