def main(x):
    res = 0
    for i in x:
        res += 18 * (11 * i - 57 * i ** 3 - i ** 2 / 57) ** 6
    return res

print(main([0.5, -0.08, 0.58, -0.23]))
print(main([0.13, -0.27, -0.72, 0.23]))
print(main([0.41, -0.08, -0.67, -0.29]))
print(main([-0.68, 0.65, -0.98, -0.21]))
print(main([-0.84, -0.44, 0.27, -0.43]))