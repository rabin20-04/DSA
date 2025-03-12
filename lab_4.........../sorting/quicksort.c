// lab four

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int A[], int l, int r)
{
    int X = l, Y = r, pivot = A[l], temp;
    while (X < Y)
    {
        while (A[X] <= pivot && X < r)
        {
            X++;
        }
        while (A[Y] > pivot && Y > l)
        {
            Y--;
        }
        if (X < Y)
        {
            // swap(A[X], A[Y]);
            temp = A[Y];
            A[Y] = A[X];
            A[X] = temp;
        }
    }
    // swap(A[l], A[Y]);
    temp = A[Y];
    A[Y] = A[l];
    A[l] = temp;

    return Y;
}

void QuickSort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p + 1, r);
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[100000], n, i;
    clock_t start, end, diff;
    printf("Enter n : ");
    scanf("%d", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 10;
    // A[i] = rand();
    display(A, n);
    start = clock();
    QuickSort(A, 0, n - 1);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("The time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}
// bubble
//  10  -- 0.000008 seconds
//  100 --0.000044 seconds
//  1000 --- 0.069656 seconds
//  100000 --- 5.017452 seconds
//  insertion
//  10  -- 0.000006 seconds
//  100 -  0.000019 seconds
//  1000 --- 0.001227 seconds
//  100000 --- 2.801168 seconds
//  selection
//  10  -- 0.000008 seconds
//  100 -  0.000046 seconds
//  1000 --- 0.079094 seconds
//  100000 --- 4.965936 seconds