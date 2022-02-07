#pragma once
#include <string>

void create_file(std::string path);
void print_file(std::string path);
void rewrite_text_into_new_file(std::string path, std::string newPath);
std::string check_last_char(std::string str);