#pragma once
#include <string>
#include "Automobile.h"

char choose_file_mode();
void write_automobiles_into_file(std::string path);
std::vector <Automobile> read_file_into_list(std::string path);
void display_file_information(std::string path);
void write_new_file_of_automobile(std::string pathOld, std::string pathNew);
void display_automobiles_released_before_year(std::string path);