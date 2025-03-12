// lab four

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SelectionSort(int A[], int n)
{
    int i, j, least, POS, temp;
    for (i = 0; i < n; i++)
    {
        least = A[i];
        POS = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < least)
            {
                least = A[j];
                POS = j;
            }
        }
        if (i != POS)
        {
            temp = A[i];
            A[i] = A[POS];
            A[POS] = temp;
        }
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
    // display(A, n);
    start = clock();
    SelectionSort(A, n);
    end = clock();
    // display(A, n);
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