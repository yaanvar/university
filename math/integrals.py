import math


def f(x):
    return (x + l) / (x**2 + x + k)

def newton_leibniz(a, b, k, l):
    fa = (0.5 * math.log(a ** 2 + a + k) + (l - 0.5) / (math.sqrt(k - 0.25)) * math.atan((a + 0.5) / (math.sqrt(k - 0.25))))
    fb = (0.5 * math.log(b ** 2 + b + k) + (l - 0.5) / (math.sqrt(k - 0.25)) * math.atan((b + 0.5) / (math.sqrt(k - 0.25))))
    ans = fb - fa
    print("newton-leibniz", ans)

def trapezoid_method(ans, x):
    for i in range(n - 1):
        ans += 2 * f(x[i])
    ans *= h / 2
    print("trapezoid method", ans)

def simpsons_method(a, b, n, h, x):
    if n == 6:
        x = []
        n = 8
        h = (b - a) / n
        for i in range(n - 1):
            x.append(a + (i + 1) * h)
        print(x)
        ans = f(a) + f(b)
        for i in range(n - 1):
            if (i + 1) % 2 == 0:
                ans += 2 * f(x[i])
            else:
                ans += 4 * f(x[i])
        ans *= h / 3
    else:
        ans = f(a) + f(b)
        for i in range(n - 1):
            if (i + 1) % 2 == 0:
                ans += 2 * f(x[i])
            else:
                ans += 4 * f(x[i])
        ans *= h / 3
    print("simpson's method", ans)

def gaussian_method(a, b, n):
    ans = 0
    if n == 4:
        t = [-0.861136, -0.339981, 0.339981, 0.861136]
        A = [0.347854, 0.652145, 0.652145, 0.347854]
        for i in range(n):
            ans += A[i] * f(((a + b) / 2) + ((b - a) / 2) * t[i])
        ans *= (b - a) / 2
    elif n == 6:
        t = [-0.932464, -0.661209, -0.238619, 0.238619, 0.661209, 0.932464]
        A = [0.171324, 0.360761, 0.467913, 0.467913, 0.360761, 0.171324]
        for i in range(n):
            ans += A[i] * f(((a + b) / 2) + ((b - a) / 2) * t[i])
        ans *= (b - a) / 2
    elif n == 8:
        t = [-0.960289, -0.796666, -0.525532, -0.183434, 0.183434, 0.525532, 0.796666, 0.960289]
        A = [0.101228, 0.222381, 0.313706, 0.362683, 0.362683, 0.313706, 0.222381, 0.101228]
        for i in range(n):
            ans += A[i] * f(((a + b) / 2) + ((b - a) / 2) * t[i])
        ans *= (b - a) / 2
    print("gaussian method", ans)


n = 8
k = 1.2
l = 0.8
a = 0.4
b = 2
h = (b - a) / n
print(h)

ans = f(a) + f(b)
x = []
for i in range(n - 1):
    x.append(a + (i + 1) * h)
print(x)

# Метод Ньютона-Лейбница
newton_leibniz(a, b, k, l)

# Метод трапеций
trapezoid_method(ans, x)

# Метод Симспсона
simpsons_method(a, b, n, h, x)

# Метод Гаусса
gaussian_method(a, b, n)
