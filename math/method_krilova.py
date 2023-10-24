import numpy as np
import math
import sys


def square_equation(x):
    a = 1
    b = x[0]
    c = x[-1]
    discr = b ** 2 - 4 * a * c
    if discr > 0:
        x1 = (-b + math.sqrt(discr)) / (2 * a)
        x2 = (-b - math.sqrt(discr)) / (2 * a)
        return [x1, x2]
    elif discr == 0:
        x = -b / (2 * a)
        return [x, x]
    else:
        return []


# orthogonalization method
def orthogonalization_method(matrix, n):
    # orthogonalization
    a = np.array(matrix).transpose()

    r = [a[0]]
    for i in range(1, n):
        t = []
        for j in range(i):
            new_t = sum(np.multiply(r[j], a[i])) / (sum(np.multiply(r[j], r[j])))
            t.append(new_t)
        new_r = a[i]
        for j in range(i):
            new_r = np.subtract(new_r, np.multiply(t[j], r[j]))
        r.append(new_r)

    # back-substitution
    b = matrix[:, n]
    x = []
    for i in range(n, 0, -1):
        new_x = sum(np.multiply(r[i - 1], b)) / sum(np.multiply(r[i - 1], a[i - 1]))
        b = np.subtract(b, np.multiply(a[i - 1], new_x))
        x.append(new_x)
    x.reverse()

    return x


# matrix input
def matrix_input(n):
    a = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            a[i][j] = float(input('a[' + str(i) + '][' + str(j) + '] = '))
    return a


# matrix output
def matrix_output(x):
    print('solution is: ')
    for i in range(len(x)):
        print('X%d = %0.2f' % (i, x[i]), end='\t')


def krilov_method():
    # input matrix
    n = int(input('enter numbers of variables: '))
    matrix = matrix_input(n)

    y1 = [float(0) for i in range(n - 1)] + [1.]
    y = np.array([np.array(y1)])
    for i in range(n):
        yi = np.dot(matrix, y[i])
        y = np.concatenate((y, [yi]))

    y[-1] = -y[-1]
    y = y.transpose()

    d = orthogonalization_method(y, n)
    d.reverse()
    lambdas = square_equation(d)

    qs = []
    for i in range(len(lambdas)):
        q = [1]
        for j in range(len(lambdas) - 1):
            q.append(lambdas[i] + d[j])
        qs.append(q)

    y = y.transpose()
    res = []
    for i in range(len(qs)):
        x = 0
        qs[i].reverse()
        for j in range(len(qs[i])):
            x += qs[i][j] * y[j]
        res = np.append(res, [x])

    # solution output
    print("lambdas:", lambdas)
    print("x:", np.split(res, n))


krilov_method()