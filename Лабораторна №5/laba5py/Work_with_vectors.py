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

    
