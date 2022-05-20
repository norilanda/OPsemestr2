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
            x = values[0]
            y = values[1]
            arr.append(R2(x, y))
        for i in range(m):
            values = input("x, y, z: ").split()
            x = values[0]
            y = values[1]
            z = values[2]
            arr.append(R3(x, y, z))

#make one function
def display_arr_of_vectors(arr, n, m):
    print("R2:")
    for i in range(n):
        arr[i].display()
        print(f"| length = {arr[i].calc_length()}")
    print("R3:")
    for i in range(m)+n:
        arr[i].display()
        print(f"| length = {arr[i].calc_length()}")

def display_vector(arr):
    for i in arr:
        i.display()
        print(f"| length = {i.calc_length()}")

def calc_sum_of_parallels(arr, n):
    arr_par = []
    sum_length = 0
    for i in range(n-1)+1:
        if arr[0].is_parallel(arr[i]):
            arr_par.append(arr[i])
            sum_length += arr[i].calc_length()
    return sum_length, arr_par

def calc_sum_of_perpendicular(arr, n, m):
    arr_perp = []
    sum_length = 0
    for i in range(m)+n:
        if arr[0].is_perpendicular(arr[i]):
            arr_perp.append(arr[i])
            sum_length += arr[i].calc_length()
    return sum_length, arr_perp
