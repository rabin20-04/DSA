#include <stdio.h>
int iterative_gcd(int, int);
int recursive_gcd(int, int);
int main()
{
    int a, b;
    printf("Enter two numbers a,b: ");
    scanf("%d%d", &a, &b);
    printf(" Iterative gcd :%d\n Recursive gcd : %d \n", iterative_gcd(a, b), recursive_gcd(a, b));

    return 0;
}
int iterative_gcd(int a, int b)
{
    int r;
    if (b == 0)
    {
        return a;
    }
    else
    {
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
    }
    return a;
}
int recursive_gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return (recursive_gcd(b, a % b));
    }
}