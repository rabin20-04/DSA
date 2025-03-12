import time


def fact_recursion(n):
    if n == 1:
        return 1
    else:
        return n * fact_recursion(n - 1)


def tail_recursion_fact(n, a):
    if n == 1:
        return a
    else:
        return tail_recursion_fact(n - 1, n * a)


a = int(input("Enter a number to calculate factorial:"))
time1 = time.time()
result1 = tail_recursion_fact(a, 1)
time2 = time.time()
result2 = fact_recursion(a)
time3 = time.time()
print(f"Result fact-recursion : {result2}, time :{time3-time2}")
print(f"Result tail-recursion : {result1}, time : {time2-time1}")

# print(f"diff:{(time3-time2)-(time2-time1)}")
