import numpy as np
import math
import matplotlib.pyplot as plt

# matplotlib
def show(coordinates):
    x, y = coordinates
    plt.figure(figsize = (12, 8))

    # plot
    plt.plot(x, y, 'bo--', label='approximate')
    plt.plot(x, function(x, y), 'g', label='exact')
    plt.title('approximate and exact solution')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.grid()
    plt.legend(loc='lower right')

    plt.show()

def showAll(y0, h, n):
    methods = ["euler's method", "trapezoid method", "runge-kutta's method"]
    subplot_number = 1
    for method in methods:
        if method == "euler's method":
            coordinates = euler_method(y0, h, n)
        if method == "trapezoid method":
            trapezoid_method(y0, h, n)
        if method == "runge-kutta's method":
            runge_kutta_method(y0, h, n)

        x, y = coordinates
        plt.figure(figsize = (12, 8))

        # plot
        plt.plot(x, y, 'bo--', label='approximate')
        plt.plot(x, function(x, y), 'g', label='exact')
        plt.title(f'{method}. approximate and exact solution')
        plt.xlabel('x')
        plt.ylabel('f(x)')
        plt.grid()
        plt.legend(loc='lower right')

    plt.show()


def showCoordinates(y0, h, n):
    euler = euler_method(y0, h, n)
    trapezoid = trapezoid_method(y0, h, n)
    runge_kutta = runge_kutta_method(y0, h, n)
    coords = [euler, trapezoid, runge_kutta]

    print('x\teuler\t\t\ttrapezoid\t\t\trunge kutta')
    for i in range(n):
        x1, y1 = coords[0]
        x2, y2 = coords[1]
        x3, y3 = coords[2]
        
        print(f'{x1[i]}\t{y1[i]}\t\t\t{y2[i]}\t\t\t\t{y3[i]}')

# functions
def function(x, y):
    k = 3.6
    return x*x + y * ((k - 1) / 2)
apply = np.vectorize(function)
f = lambda x, y: function(x, y)


def euler_method(y0, h, n):
    # conditions
    x = np.arange(0, h * n, h)
    y = np.zeros(len(x))
    y[0] = y0

    # euler method
    for i in range(0, len(x) - 1):
        y[i + 1] = y[i] + h * f(x[i], y[i])

    # output
    return (x, y)

def trapezoid_method(y0, h, n):
    # conditions
    x = np.arange(0, n * h, h)
    y = np.zeros(len(x))
    y[0] = y0

    # trapezoid method
    for i in range(0, len(x) - 1):
        y[i + 1] = y[i] + (h / 2) * (f(x[i], y[i]) + f(x[i + 1], y[i] + h * f(x[i], y[i])))
        
    # output
    return (x, y)

def runge_kutta_method(y0, h, n):
    # conditions
    x = np.arange(0, n * h, h)
    y = np.zeros(len(x))
    y[0] = y0

    # runge kutta method
    for i in range(0, len(x) - 1):
        k1 = f(x[i], y[i])
        k2 = (f(x[i] + h/2, y[i] + (h * k1) / 2))
        k3 = (f(x[i] + h/2, y[i] + (h * k2) / 2))
        k4 = (f(x[i] + h, y[i] + h * k3))
        k = (k1 + 2*k2 + 2*k3 + k4) * (h / 6)

        y[i + 1] = y[i] + k

    # output
    return (x, y)
    

showAll(2, 0.5, 5)
#show(euler_method(2, 0.5, 5))
#show(trapezoid_method(2, 0.5, 5))
#show(runge_kutta_method(2, 0.5, 5))
showCoordinates(2, 0.5, 5)