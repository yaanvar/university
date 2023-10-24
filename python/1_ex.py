import math

def main(R):
    Z = [r / 4 + 2 * r for r in R if r < -10 or r > 9]
    L = [8 * r + math.fabs(r) for r in R if not (r > 10 or r < -9)]
    v = len(Z) - sum(L)
    return v

print(main([-5.47, -0.11, 2.82, -4.26, 1.05])) # = 34.05
print(main([-0.94, -9.1, -8.91, -2.29, 3.28])) # = 5.55e+01