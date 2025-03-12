import random
import time


def bubble_sort(A, n):
    for i in range(n - 1):
        for j in range(n - i - 1):
            if A[j] > A[j + 1]:
                temp = A[j]
                A[j] = A[j + 1]
                A[j + 1] = temp
                # A[j], A[j + 1] = A[j + 1], A[j]


def display(A, n):
    for i in range(n - 1):
        print(f"{A[i]}")
    print("\n")


A = []
input_num = int(input("Enter n : "))
for i in range(input_num):
    A.append(random.randint(1, 500))

display(A, input_num)
start = time.time()
bubble_sort(A, input_num)
diff = (time.time()) - start
display(A, input_num)
print(f"the time taken to sort is {diff}")
