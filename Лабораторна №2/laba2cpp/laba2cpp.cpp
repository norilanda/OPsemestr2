#include <iostream>
#include <string>
#include "File_functions.h"

using namespace std;

int main()
{
    string pathAutoList = "automobiles\\List of automobiles.txt";
    string newPathAutoList = "automobiles\\New automobiles.txt";
    write_automobiles_into_file(pathAutoList);
    cout << "\nThere is information in file:\n\n";
    display_file_information(pathAutoList);
}

