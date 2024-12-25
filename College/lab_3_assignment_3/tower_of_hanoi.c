#include <stdio.h>

void tower_of_hanoi(int num, char source, char dest, char temp);

int main()
{
    int num;
    char x = 'A', y = 'B', z = 'C';
    printf("Enter a number of discs : ");
    scanf("%d", &num);
    tower_of_hanoi(num, x, y, z);
    return 0;
}

void tower_of_hanoi(int num, char source, char dest, char temp)
{
    if (num == 1)
    {
        printf("Move disc 1 from %c to %c \n", source, dest);
        return;
    }
    tower_of_hanoi(num - 1, source, temp, dest);
    printf("move disc %d from %c to %c \n", num, source, dest);
    tower_of_hanoi(num - 1, temp, dest, source);
}