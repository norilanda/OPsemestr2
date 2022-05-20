#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "TVector.h"

using namespace std;

int main()
{
    srand(time(NULL));
    TVector t;
    t.display();
    
}