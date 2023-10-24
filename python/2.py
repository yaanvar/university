import math


def main(x):
    res = 0
    if x < 87:
        res = math.atan(x)**6 + (x**3 / 81) - 67 - 64*x
    elif x < 124 and x >= 87:
        res = 57 * math.log(x)**4 - x
    elif x >= 124:
        res = ((x**3 / 71) + 63*x**2 + x)**7 / 18 + 5*x**6
    return res

print(main(118))
print(main(133))
print(main(94))
print(main(96))
print(main(77))