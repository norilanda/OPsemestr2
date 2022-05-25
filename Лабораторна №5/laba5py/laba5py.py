from Work_with_vectors import *

n = 3
m = 4
arr = create_arr_of_vectors(n, m)
print("There are R2 and R3 vectors: ")
display_vector(arr)
print()

sum_par, arr_par = calc_sum_of_parallels(arr, n)
print("Vectors which are parallel to the first R2 vector:")
display_vector(arr_par)
print(f"Sum of R2 vectors, which are parallel = {sum_par}\n")

sum_perp, arr_perp = calc_sum_of_perpendicular(arr, n, m)
print("Vectors which are perpendicular to the first R3 vector:")
display_vector(arr_perp)
print(f"Sum of R3 vectors, which are perpendicular = {sum_perp}")
