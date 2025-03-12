// lab four

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int A[], int l, int m, int r)
{
    int i = l;
    int j = m;
    int k = l;
    int B[100];
    while (i < m && j <= r)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i < m; i++, k++)
        B[k] = A[i];
    for (; j <= r; j++, k++)
        B[k] = A[j];
    for (k = l; k <= r; k++)
        A[k] = B[k];
}

void merge_Sort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        merge_Sort(A, l, m);
        merge_Sort(A, m + 1, r);
        merge(A, l, m + 1, r);
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
        A[i] = rand() % 10;
    // A[i] = rand()%10;
    display(A, n);
    start = clock();
    merge_Sort(A, 0, n - 1);
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