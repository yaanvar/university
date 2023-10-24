from math import *


def main(m, b, a):
    res = 0
    for c in range(1, a):
        for j in range(1, b):
            for i in range(1, m):
                res += (c - 79*j**3 - 82*(c**3 - i/71 - 53*i**2) ** 2)
    return(res)

print(main(2, 6, 3))
print(main(7, 5, 6))
print(main(3, 4, 3))
print(main(2, 8, 2))
print(main(7, 7, 4))