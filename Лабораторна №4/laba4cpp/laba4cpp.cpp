#include <iostream>
#include <time.h> 
#include "Polynomial.h"

using namespace std;

int main()
{
    srand(time(0));
    double c0, c1, c2, c3, min, max;
    Polynomial P1;
    init_coefficients(c0, c1, c2, c3);
    Polynomial P2(c0, c1, c2, c3);
    intit_range(min, max);
    Polynomial P3(min, max);
    cout << "\nPolynomials\n";
    cout << "P1: ";
    P1.display();
    cout << "P2: ";
    P2.display();
    cout << "P3: ";
    P3.display();
}