// lab four

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubbleSort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
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
    {
        A[i] = rand() % 100;
    }
    display(A, n);
    start = clock();
    bubbleSort(A, n);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("The time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}
// 10  -- 0.000008
// 100 --0.000044 seconds
// 1000 --- 0.069656 seconds
// 100000 --- 5.017452 seconds