import time


# def fibo_recursion(n):
#     if n == 1 or n == 2:  # base condition
#         return 1
#     else:
#         return fibo_recursion(n - 1) + fibo_recursion(n - 2)


# def fibo_memorization(n,table=None):
#     if table is None:
#         table= {}
#     if n == 1 or n == 2:
#         return 1
    
#     if n not in table[n]:
#         result = fibo_memorization(n - 1,table) + fibo_memorization(n - 2,table)
#         table[n]=result
#     return table[n]

def fibo_memorization(n, table=None):
    # Initialize the table (memoization cache) if it's not passed
    if table is None:
        table = []

    # Base case: the first two Fibonacci numbers are 1
    if n == 1 or n == 2:
        return 1
    
    # If the result is already computed, return it from the table
    if n in table:
        return table[n]
    
    # Recursive case: compute Fibonacci number using memoization
    table[n] = fibo_memorization(n - 1, table) + fibo_memorization(n - 2, table)
    
    # Return the computed result
    return table[n]


user_input = int(input("Enter nth term :"))
# inital_time1 = time.time()
# result_1 = fibo_recursion(user_input)
# time1 = time.time() - inital_time1
# print(f" Using recursion : {result_1} \n Time taken: {time1} seconds")
inital_time2 = time.time()
result_2 = fibo_memorization(user_input)
time2 = time.time() - inital_time2
print(f" Using memorization : {result_2} \n Time taken : {time2}")
