#include <stdio.h>
#define MAX 5
// struct  ------
struct linear_Queue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
typedef struct linear_Queue LQ;

// enqueue -------
void enqueue(LQ *Q, int element)
{
    if (Q->REAR == MAX)
    {
        printf("Queue is Full!\n");
        printf("!!!!!!!    Can't Enqueue %d !!!!!!!!\n", element);
        return;
    }
    else
    {
        Q->DATA[Q->REAR] = element;
        Q->REAR += 1;
        printf("%d was enqueued!\n", element);
    }
}
// Dequeue --------
void dequeue(LQ *Q)
{
    if (Q->REAR == Q->FRONT)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("%d was Dequeued!\n", Q->DATA[Q->FRONT]);
        Q->FRONT += 1;
    }
}
// Display
void display(LQ *Q)
{
    if (Q->FRONT == Q->REAR)
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = Q->FRONT; i < Q->REAR; i++)
    {
        printf("%d ", Q->DATA[i]);
    }
    printf("\n");
}

// main  -----------
int main()
{
    int num, choice;
    LQ Q = {0, 0};

    do
    {
        printf("------------\n*Linear Queue* Enter any choices:  \n 1.Enqueue\n 2.Dequeue\n 3.View Queue\n 4.Exit\n Choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter a number you want to Enqueue: ");
            scanf("%d", &num);
            enqueue(&Q, num);
        }
        else if (choice == 2)
        {
            dequeue(&Q);
        }
        else if (choice == 3)
        {
            display(&Q);
        }
        else if (choice == 4)
        {
            printf("BYE");
            break;
        }
        else
        {
            printf("!!!!! Enter a Valid choice !!!!\n");
        }
    } while (choice != 4);
    return 0;
}