#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "TVector.h"

using namespace std;

int main()
{
    srand(time(NULL));
    R3 r(1.0, 0.0, -1.0);
    R3 r1(2.0, 8.0, 2.0);
    r.display(); cout << "\n";
    r1.display();
    TVector* basePtr;
    basePtr = &r1;

    cout << r1.calc_length() << "\n";
    cout << r.is_parallel(basePtr) << "\n";
    cout << r.is_perpendicular(basePtr) << "\n";
}