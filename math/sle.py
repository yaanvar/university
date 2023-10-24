import numpy as np
import sys

# orthogonalization method
def orthogonalization_method():
    # input matrix
    n = int(input('enter numbers of variables: '))
    matrix = np.array(matrix_input(n))

    # orthogonalization
    a = matrix.transpose()

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

    # output
    matrix_output(x)


def gaussian_method():
    #input matrix
    n = int(input('enter numbers of variables: '))
    matrix = matrix_input(n)

    x = np.zeros(n)
    # gauss elimination
    for i in range(n):
        if matrix[i][i] == 0.0:
            sys.exit('dividing by zero!')
        for j in range(i + 1, n):
            ratio = matrix[j][i] / matrix[i][i]

            for k in range(n + 1):
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k]

    # back-substitution
    x[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1]
    for i in range(n - 2, -1, -1):
        x[i] = matrix[i][n]
        for j in range(i + 1, n):
            x[i] = x[i] - matrix[i][j] * x[j]
        x[i] = x[i] / matrix[i][i]

    # output matrix
    matrix_output(x)


# matrix input
def matrix_input(n):
    a = np.zeros((n, n + 1))
    print('enter matrix coefficients:')
    for i in range(n):
        for j in range(n + 1):
            a[i][j] = float(input('a[' + str(i) + '][' + str(j) + '] = '))
    return a


#matrix output
def matrix_output(x):
    print('solution is: ')
    for i in range(len(x)):
        print('X%d = %0.2f' % (i, x[i]), end='\t')
    

#gaussian_method()
orthogonalization_method()