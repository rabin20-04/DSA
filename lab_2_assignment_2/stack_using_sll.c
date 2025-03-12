#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int data;
    struct SLL *next;
};

struct SLL *top = NULL;

struct SLL *createNode(int element) {
    struct SLL *NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        return NULL;
    NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;
}

void push(int element) {
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL) {
        printf("Cannot allocate memory\n");
    } else {
        NewNode->next = top;
        top = NewNode;
        printf("%d pushed to stack\n", element);
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct SLL *temp = top;
        int element = temp->data;
        top = top->next;
        free(temp);
        printf("%d popped from stack\n", element);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct SLL *temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    push(10);
    display();
    push(20);
    display();
    push(30);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}