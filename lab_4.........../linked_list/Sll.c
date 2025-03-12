#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int data;
    struct SLL *next;
};

struct SLL *first = NULL, *last = NULL;

struct SLL *createNode(int element) {
    struct SLL *NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;
}

void insertAtBeginning(int element) {
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL) {
        printf("Memory Allocation Failed\n");
    } else {
        if (first == NULL)
            first = last = NewNode;
        else {
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning\n", first->data);
    }
}

void insertAtEnd(int element) {
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL) {
        printf("Memory Allocation Failed\n");
    } else {
        if (first == NULL)
            first = last = NewNode;
        else {
            last->next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted at the end\n", last->data);
    }
}

void insertAtSpecificPoint(int element, int position) {
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL) {
        printf("Memory Allocation Failed\n");
    } else if (position == 1) {
        insertAtBeginning(element);
    } else {
        struct SLL *temp = first;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position %d not found in list\n", position);
            free(NewNode);
        } else {
            NewNode->next = temp->next;
            temp->next = NewNode;
            if (NewNode->next == NULL) {
                last = NewNode;
            }
            printf("%d was inserted at position %d\n", element, position);
        }
    }
}

int deletefromthebeginning() {
    struct SLL *temp;
    int element = -1;
    if (first == NULL) {
        printf("List is empty\n");
    } else if (first->next == NULL) {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    } else {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deletefromtheEnd() {
    struct SLL *temp;
    int element = -1;
    if (first == NULL) {
        printf("List is empty\n");
    } else if (first->next == NULL) {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    } else {
        temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        element = temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}

void display() {
    struct SLL *temp;
    if (first == NULL) {
        printf("List is empty\n");
    } else {
        temp = first;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int data;

    insertAtBeginning(100);
    display();
    insertAtEnd(200);
    display();
    insertAtBeginning(500);
    display();
    insertAtSpecificPoint(300, 1);
    data = deletefromthebeginning();
    if (data != -1)
        printf("%d was deleted from the beginning\n", data);
    display();
    data = deletefromtheEnd();
    if (data != -1)
        printf("%d was deleted from the end\n", data);
    display();
    insertAtSpecificPoint(455, 2);
    display();

    return 0;
}