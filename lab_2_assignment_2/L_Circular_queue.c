#include <stdio.h>
#define MAX 5
struct CircularQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
typedef struct CircularQueue CQ;
void enqueue(CQ *Q, int element)
{
    if (Q->FRONT == (Q->REAR + 1) % MAX)
    {
        printf("!!! Queue is full\n***Cannot enqueue %d!***\n", element);
    }
    else
    {
        Q->DATA[Q->REAR] = element;
        Q->REAR = ((Q->REAR + 1) % MAX);
        printf("%d was queued!\n", element);
    }
}
int dequeue(CQ *Q)
{
    int element = -1;
    if (Q->FRONT == Q->REAR)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = ((Q->FRONT + 1) % MAX);
    }
    return element;
}
int main()
{
    int choice, element, data;
    CQ Q = {0, 0};
    do
    {
        printf("-------\nChoices:\n1. Enqueue\n2. Dequeue\n3. Exit\nChoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter an element you want to enqueue\n");
            scanf("%d", &element);
            enqueue(&Q, element);
            break;
        }
        case 2:
            data = dequeue(&Q);
            {
                if (data != -1)
                {

                    printf("%d was Deququed!\n", data);
                }
                break;
            }
        case 3:
        {
            printf("Bye!");
            break;
        }
        default:
        {
            printf("Invalid Choice!");
        }
        }
    } while (choice != 3);
    return 0;
}