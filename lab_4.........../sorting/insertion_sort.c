// lab four

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        int j = i - 1;
        temp = A[i];
        while (j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
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
    srand(time(NULL));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        // A[i] = rand();
        A[i] = rand() % 10;
    display(A, n);
    start = clock();
    insertionSort(A, n);
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