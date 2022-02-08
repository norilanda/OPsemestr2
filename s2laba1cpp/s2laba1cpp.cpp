#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ".1251");
    system("chcp 1251 > null");
    string pathOfFile = "file.txt";
    string pathOfNewFile = "new file.txt";
    create_file(pathOfFile);
    cout << "Here is the first file:\n";
    print_file(pathOfFile);
    rewrite_text_into_new_file(pathOfFile, pathOfNewFile);
    cout << "The new file:\n";
    print_file(pathOfNewFile);

}

