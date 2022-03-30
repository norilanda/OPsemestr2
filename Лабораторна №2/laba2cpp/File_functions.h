#pragma once
#include <string>
#include "Automobile.h"

char choose_file_mode();
void write_automobiles_into_file(std::string path);
void display_file_information(std::string path);