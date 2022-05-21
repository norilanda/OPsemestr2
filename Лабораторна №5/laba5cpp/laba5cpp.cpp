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
    cout << "R2: \n";
    display_vector(arr, 0, n);
    cout << "R3: \n";
    display_vector(arr, n);

    double parallelSum = calc_sum_of_parallels(arr, n, m, arrPar);
    cout << "\nVectors which are parallel to the first R2 vector:\n";
    display_vector(arrPar);
    cout << "\nSum of R2 vectors, which are parallel = " << parallelSum << "\n";
    
    double perpendicular = calc_sum_of_perpendicular(arr, n, m, arrPerp);
    cout << "\nVectors which are perpendicular to the first R3 vector:\n";
    display_vector(arrPerp);
    cout << "\nSum of R3 vectors, which are perpendicular = " << perpendicular << "\n";
}