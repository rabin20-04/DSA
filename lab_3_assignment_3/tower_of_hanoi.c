#include <stdio.h>
int no_counts;

void tower_of_hanoi(int num, char source, char dest, char temp);

int main()
{
    int num;
    char x = 'A', y = 'B', z = 'C';
    printf("Enter a number of discs : ");
    scanf("%d", &num);
    tower_of_hanoi(num, x, z, y);
    printf("Number of moves: %d\n", no_counts);

    return 0;
}

void tower_of_hanoi(int num, char source, char dest, char temp)
{
    no_counts = no_counts + 1;
    if (num == 1)
    {
        printf("Move disc 1 from %c to %c \n", source, dest);
        return;
    }
    tower_of_hanoi(num - 1, source, temp, dest);
    printf("move disc %d from %c to %c \n", num, source, dest);

    tower_of_hanoi(num - 1, temp, dest, source);
}