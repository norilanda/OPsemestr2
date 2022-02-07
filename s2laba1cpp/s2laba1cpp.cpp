#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    string pathOfFile = "file.txt";
    create_file(pathOfFile);
    cout << "Here is the first file:\n";
    print_file(pathOfFile);

}

