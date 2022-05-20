#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "TVector.h"

using namespace std;

int main()
{
    srand(time(NULL));
  
    R2 r1(4.0, -3.0);
   
    r1.display();
    cout << r1.calc_length();
    //cout << r.is_parallel(r1);
}