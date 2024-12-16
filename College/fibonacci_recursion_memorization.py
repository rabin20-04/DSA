import time


def fibo_recursion(n):
    if n == 1 or n == 2:  # base condition
        return 1
    else:
        return fibo_recursion(n - 1) + fibo_recursion(n - 2)


def fibo_memorization(n, table=None):
    if table is None:
        table = {}
    if n == 1 or n == 2:
        return 1

    if n not in table[n]:
        result = fibo_memorization(n - 1, table) + fibo_memorization(n - 2, table)
        table[n] = result
    return table[n]


global table
table = {}


def fibo_memorization(n):
    if n == 2 or n == 1:
        return 1

    else:
        if n not in table:
            result = fibo_memorization(n - 1) + fibo_memorization(n - 2)
            table[n] = result

    return table[n]


ask_option = input("Try using \n1)recursion \n 2) Memorization")
user_input = int(input("Enter nth term :"))
inital_time1 = time.time()
result_1 = fibo_recursion(user_input)
time1 = time.time() - inital_time1

inital_time2 = time.time()
result_2 = fibo_memorization(user_input)
time2 = time.time() - inital_time2
print("-" * 30)
print(f" Using recursion : {result_1} \n Time taken: {time1} seconds")
print("-" * 30)
print(f" Using memorization : {result_2} \n Time taken : {time2}")
print("-" * 30)
