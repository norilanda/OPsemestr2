from TVector import  R2, R3
import random

def create_arr_of_vectors(n, m):
    arr = []
    mode = input("Random or manually? Random - enter 'r', manually - enter 'm': ")
    while mode != 'r' and mode !='m':
        mode = input("Try again! ")
    if mode == 'r':
        limits = input("Enter range (first min than max value): ").split()
        rangeMin = int(limits[0])
        rangeMax = int(limits[1])       
        for i in range(n):
            x = random.randint(rangeMin, rangeMax)
            y = random.randint(rangeMin, rangeMax)
            arr.append(R2(x, y))
        for i in range(m):
            x = random.randint(rangeMin, rangeMax)
            y = random.randint(rangeMin, rangeMax)
            z = random.randint(rangeMin, rangeMax)
            arr.append(R3(x, y, z))
    else:
        print("R2:")
        for i in range(n):
            values = input("x, y: ").split()
            x = int(values[0])
            y = int(values[1])
            arr.append(R2(x, y))
        for i in range(m):
            values = input("x, y, z: ").split()
            x = int(values[0])
            y = int(values[1])
            z = int(values[2])
            arr.append(R3(x, y, z))
    return arr

#make one function

def display_vector(arr):
    for i in arr:
        i.display()
        print(f"| length = {i.calc_length()}")

def calc_sum_of_parallels(arr, n):
    arr_par = []
    sum_length = 0
    for i in range(1, n):
        if arr[0].is_parallel(arr[i]):
            arr_par.append(arr[i])
            sum_length += arr[i].calc_length()
    return sum_length, arr_par

def calc_sum_of_perpendicular(arr, n, m):
    arr_perp = []
    sum_length = 0
    for i in range(n + 1, n + m):
        if arr[n].is_perpendicular(arr[i]):
            arr_perp.append(arr[i])
            sum_length += arr[i].calc_length()
    return sum_length, arr_perp
