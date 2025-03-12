import time


def fibo_recursion(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibo_recursion(n - 1) + fibo_recursion(n - 2)


table = {}


def fibo_memorization(num):
    if num == 1 or num == 2:
        return 1
    elif num not in table:
        table[num] = fibo_memorization(num - 1) + fibo_memorization(num - 2)
    return table[num]


print("-" * 30)

ask_option = int(
    input(
        "Calculate Fibonacci using \n"
        " 1) Recursion (!Reminder: Recursion fails above 49) \n "
        "2) Memorization \n 3) Compare Both\n"
    )
)
user_input = int(input("Enter nth term: "))

if ask_option == 1:
    initial_time1 = time.time()
    result_1 = fibo_recursion(user_input)
    time1 = time.time() - initial_time1
    print("*Recursion")
    print(f"Using recursion: {result_1} \nTime taken: {time1} seconds")
elif ask_option == 2:
    initial_time2 = time.time()
    result_2 = fibo_memorization(user_input)
    time2 = time.time() - initial_time2
    print("*Memorization")
    print(f"Using memorization: {result_2} \nTime taken: {time2} seconds")
else:
    print("*Comparison")
    print("-" * 30)
    initial_time1 = time.time()
    result_1 = fibo_recursion(user_input)
    time1 = time.time() - initial_time1
    initial_time2 = time.time()
    result_2 = fibo_memorization(user_input)
    time2 = time.time() - initial_time2
    print(f"Using recursion: {result_1} \nTime taken: {time1} seconds")
    print(f"Using memorization: {result_2} \nTime taken: {time2} seconds")
    print("-" * 30)
