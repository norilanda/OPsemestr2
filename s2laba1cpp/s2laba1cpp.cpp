#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    string pathOfFile = "file.txt";
    string pathOfNewFile = "new file.txt";
    create_file(pathOfFile);
    cout << "Here is the first file:\n";
    print_file(pathOfFile);
    rewrite_text_into_new_file(pathOfFile, pathOfNewFile);
    cout << "The new file:\n";
    print_file(pathOfNewFile);

}

