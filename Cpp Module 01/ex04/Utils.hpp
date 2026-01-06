#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


bool is_valid_input(const std::string& s1, const std::string& s2);
std::string replace_all(const std::string& content, const std::string& s1, const std::string& s2);

#endif