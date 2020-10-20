# Program to find kth smallest Number from all numbers formed by the digits of a given non zero integer


import math
import itertools


def seperate(x):  # This Function takes an integer and returns a list containing its Digits
    y = int(math.log(x, 10))
    e = []
    for j in range(y + 1):
        f = x % 10
        x = int(x / 10)
        e.append(f)
    e.reverse()
    return e


def possible_numbers(z):  # This function takes a list of integer and returns a list containing all possible Numbers
    b = []
    y = itertools.permutations(z)
    for i in list(y):
        b.append(i)
    return b


def convert(y):  # This function convert a tuple in a list(Can be used only for tuple in a list)
    for i in y:
        for i in range(len(y)):
            y[i] = list(y[i])
    return y


def joint(y):  # This function takes a list of integers and concatenate its integers to make a single integer
    g = 0
    for n, i in enumerate(y):
        k = y[n]*(10**n)
        g = g+k
    return g


a = int(input("Enter an Integer:-"))
b = seperate(a)
c = possible_numbers(b)
d = convert(c)
x = []
for i in list(d):
    b = joint(i)
    x.append(b)
    x.sort()
e = int(input("Enter The Value of K to get Kth smallest value:-"))
print("The List of all possible numbers is ", x)
print(f"The value of {e}th smallest number is ", x[e-1])
