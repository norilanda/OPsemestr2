#pragma once
#include <vector>
#include "TVector.h"

using std::vector;

void create_arr_of_vectors(vector <TVector*>& arr, int n, int m);
void display_vector(vector <TVector*> arr, int start = 0, int end = 0);

double calc_sum_of_parallels(vector <TVector*> arr, int n, int m, vector <TVector*>& arrPar);
double calc_sum_of_perpendicular(vector <TVector*> arr, int n, int m, vector <TVector*>& arrPerp);
