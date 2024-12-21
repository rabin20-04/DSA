#  Fibonacci using Binet's formula

import math
import time


def fibonacci(n):

    a = (1 + math.sqrt(5)) / 2
    b = (1 - math.sqrt(5)) / 2

    fib = (a**n - b**n) // math.sqrt(5)

    return int(fib)


n = int(input("Enter the nth term: "))
time1 = time.time()
result = fibonacci(n)
time2 = time.time() - time1
print(f"Fibonacci number of {n} position is : {result}\n Time taken : {time2}")
