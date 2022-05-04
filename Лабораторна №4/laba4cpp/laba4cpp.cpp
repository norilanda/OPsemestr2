#include <iostream>
#include <time.h> 
#include "Polynomial.h"

using namespace std;

int main()
{
    srand(time(0));
    double c, c0, c1, c2, c3;
    int min, max;
    cout << "Enter one number to initiate coefficients: "; cin >> c;
    init_coefficients(c0, c1, c2, c3);
    intit_range(min, max);

    Polynomial P1(c);    
    Polynomial P2(c0, c1, c2, c3);  
    Polynomial P3(min, max);

    cout << "\nPolynomials\n";
    cout << "P1: " << P1.get_polynomial_as_string();
    cout << "P2: " << P2.get_polynomial_as_string();
    cout << "P3: " << P3.get_polynomial_as_string();

    cout << "\nEnter number to increase/decrease polynomials: ";
    double n; cin >> n;
    P1 += n;
    P2 -= n;
    
    cout << "\nNew polynomials increased/decreased by " << n << "\n";
    cout << "P1: " << P1.get_polynomial_as_string();
    cout << "P2: " << P2.get_polynomial_as_string();

    if (P1 == P2)
        cout << "Coefficients of P1 and P2 are equal\n";
    else
        cout << "Coefficients of P1 and P2 are NOT equal\n";

    cout << "\nEnter x to calculate P3: ";
    double x; cin >> x;
    cout << "Value of the P3 at the point x = " << P3.calculate_polynomial(x) << "\n";
}