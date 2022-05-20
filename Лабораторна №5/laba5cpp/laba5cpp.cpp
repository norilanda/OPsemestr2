#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "TVector.h"

using namespace std;

int main()
{
    srand(time(NULL));
    R2 r(1.0, 0.0);
    R2 r1(0.0, 1.0);
    r.display();
    r1.display();
    TVector* basePtr;
    basePtr = &r1;

    cout << r1.calc_length() << "\n";
    cout << r.is_parallel(basePtr) << "\n";
    cout << r.is_perpendicular(basePtr) << "\n";
}