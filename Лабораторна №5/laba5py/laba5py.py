from TVector import  R2, R3

#//division by 0
f = R2(0, 5)
h = R3(1,0,-1)
j = R3(1, 1, 1)
f.display()
print()
h.display()
print(j.is_perpendicular(h))
print(f.calc_length())
