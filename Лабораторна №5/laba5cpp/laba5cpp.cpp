#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "TVector.h"

using namespace std;

int main()
{
    srand(time(NULL));
    R2 r;
    R2 r1(2.3, -0.44);
    r.display(); cout << endl;
    r1.display();
}