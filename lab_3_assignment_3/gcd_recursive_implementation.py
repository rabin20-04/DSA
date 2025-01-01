def iterative_gcd(a, b):
    if b == 0:
        return a
    else:
        while b:
            r = a % b
            a = b
            b = r
    return a


def recursive_gcd(a, b):
    if b == 0:
        return a
    else:
        return recursive_gcd(b, a % b)


num1 = int(input("Enter first numbers a : "))
num2 = int(input("Enter second numbers b : "))
print(f"Iteraive : The GCD of {num1} and {num2} is : {iterative_gcd(num1,num2)}")
print(f"Recursive : The GCD of {num1} and {num2} is : {recursive_gcd(num1,num2)}")
