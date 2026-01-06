#include "Utils.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./replace <file> <s1> <s2>" << std::endl;
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
        std::cout << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    if (in.fail() && !in.eof())
    {
        std::cout << "Error: Failed while reading file '" << filename << "'." << std::endl;
        return 1;
    }

    const std::string content = buffer.str();

    const std::string replaced = replace_all(content, s1, s2);
    std::ofstream out((filename + ".replace").c_str());
    if (!out.is_open())
    {
        std::cout << "Error: Could not open output file '" << filename << ".replace' for writing." << std::endl;
        return 1;
    }
    out << replaced;
    if (out.fail())
    {
        std::cout << "Error: Failed while writing to file '" << filename << ".replace'." << std::endl;
        return 1;
    }
    
    return 0;
}