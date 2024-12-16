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


print("-" * 30)

ask_option = int(
    input(
        "Calculate Fibonacci using \n 1)Recursion (!Reminder  Recursion Fails above 49) \n 2) Memorization \n 3)Compare Both\n"
    )
)
user_input = int(input("Enter nth term :"))
inital_time1 = time.time()
result_1 = fibo_recursion(user_input)
time1 = time.time() - inital_time1

inital_time2 = time.time()
result_2 = fibo_memorization(user_input)
time2 = time.time() - inital_time2
if ask_option == 1:
    print("*Recursion")
    result_1 = fibo_recursion(user_input)
    print(f" Using recursion : {result_1} \n Time taken: {time1} seconds")
elif ask_option == 2:
    print("*Memorizaation")
    result_2 = fibo_memorization(user_input)
    print(f" Using memorization : {result_2} \n Time taken : {time2}")
else:
    print("*Comparison")
    print("-" * 30)
    print(f" Using recursion : {result_1} \n Time taken: {time1} seconds")
    print(f" Using memorization : {result_2} \n Time taken : {time2}")
    print("-" * 30)
