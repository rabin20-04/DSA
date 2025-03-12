#include <stdio.h>

int search(int arr[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x;
    
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Enter number to search : ");
    scanf("%d", &x);
    int result = search(arr, N, x);
    if (result == -1) {
        printf("Element %d is not present in array\n", x);
    } else {
        printf("Element %d is present at index %d\n", x,result);
    }
    
    return 0;
}