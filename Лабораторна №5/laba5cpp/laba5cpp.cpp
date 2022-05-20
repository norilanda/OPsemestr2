#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include "TVector.h"
#include "Work_with_vectors.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 3; // R2
    int m = 4; // R3

    vector <TVector*> arr, arrPar, arrPerp;
    create_arr_of_vectors(arr, n, m);
    display_arr_of_vectors(arr, n, m);

    double parallelSum = calc_sum_of_parallels(arr, n, m, arrPar);
    cout << "\nVectors which are parallel to the first vector:\n";
    display_vector(arrPar);
    cout << "\nSum of R2 vectors, which are parallel = " << parallelSum << "\n";
    
    double perpendicular = calc_sum_of_perpendicular(arr, n, m, arrPerp);
    cout << "\nVectors which are perpendicular to the first vector:\n";
    display_vector(arrPerp);
    cout << "\nSum of R2 vectors, which are perpendicular = " << perpendicular << "\n";

    /*R3 r(1.0, 0.0, -1.0);
    R3 r1(2.0, 8.0, 2.0);
    r.display(); cout << "\n";
    r1.display();
    TVector* basePtr;
    basePtr = &r1;

    cout << r1.calc_length() << "\n";
    cout << r.is_parallel(basePtr) << "\n";
    cout << r.is_perpendicular(basePtr) << "\n";*/
}