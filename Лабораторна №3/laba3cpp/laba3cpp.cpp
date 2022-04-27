#include <iostream>
#include <vector>
#include "Word.h"

using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n; cin.ignore();
    cout << "Enter your words. You can not use any delimeters exept hyphen(-), apostrophe(') and stress(`)\n";
    vector <Word>arr = create_arr(n);
    cout << "\nThe words in the array:\n";
    print_arr(arr);
    vector <Word> maxDigitWords = word_with_max_number_of_digits(arr);
    if (maxDigitWords.empty())
        cout << "Words does not contain digits.\n";
    else
    {
        cout << "There are words with max number of digits:\n";
        print_arr(maxDigitWords);
    }
}