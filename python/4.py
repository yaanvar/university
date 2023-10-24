from math import *


def main(n):
    if n == 0:
        return -0.26
    else:
        return main(n-1)**2 + 1 + main(n-1)/76

print(main(7))
print(main(4))
print(main(2))
print(main(8))
print(main(3))