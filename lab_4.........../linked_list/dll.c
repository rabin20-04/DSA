#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *previous,*next;
};
struct DLL *first = NULL, *last = NULL;


struct DLL * createNode(int element){
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    if(NewNode == NULL)
        return NULL;
    else{
        NewNode->previous = NULL;
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element){
    struct DLL *NewNode = createNode(element);
    if(NewNode == NULL){
        printf("Memory Allocation failed\n");
    }
    else{

        if(first == NULL){
            first = NewNode;
            last = NewNode;
        }
        else{
            first->previous = NewNode;
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning\n", first->data);
    }
}





void insertAtEnd(int element){
    struct DLL *NewNode = createNode(element);
    if(NewNode == NULL){
        printf("Memory Allocation failed\n");
    }
    else{

        if(first == NULL){
            first = NewNode;
            last = NewNode;
        }
        else{
            last->next = NewNode;
            NewNode->previous = last;
            last = NewNode;
        }
        printf("%d was inserted at the end\n", last->data);
    }
}



void insertAtPosition(int element,int position){
    struct DLL *NewNode = createNode(element);
    struct DLL *temp,*tempp;
    if(NewNode == NULL){
        printf("Memory Allocation failed\n");
    }
    else{

        if(first == NULL){
            first = NewNode;
            last = NewNode;
        }
        else if(position == 1){
            insertAtBeginning(element);
        }
        else{
            temp = first;
          
            for (int i = 1; i < (position - 1); i++){
                temp = temp->next;
            }
              if(temp->next==NULL){
                  insertAtEnd(element);
              }
              else{
            tempp = temp->next;
            temp->next = NewNode;
            NewNode->previous = temp;
            tempp->previous = NewNode;
            NewNode->next = tempp;
            printf("%d was inserted at the position %d\n", element,position);
              }
                }
   
    }
}


int deleteFromBeginning(){
    int element = -1;
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is Empty\n");
    }
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = first;
        first = first->next;
        first->previous = NULL;
        element = temp->data;
        free(temp);

    }
    return element;
}

int deleteFromEnd(){
    int element = -1;
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is Empty\n");
    }
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = last;
        last = last->previous;
        last->next = NULL;
        element = temp->data;
        free(temp);
    }
    return element;
}


int deleteAtPosition(int position){
    int element = -1;
    struct DLL *temp,*tempp;
    if(position<1){
        printf("Invalid Position\n");
    }
    else if(position==1){
        element = deleteFromBeginning();
    }
    else{

        temp = first;
        for (int i = 1; i < position-1;i++){
            temp = temp->next;
        }
        if(temp->next==last){
            element = deleteFromEnd();
        }
        else{
            tempp = temp->next;
            temp->next = tempp->next;
            (tempp->next)->previous = temp;
            element = tempp->data;
            free(tempp);
        }
    }
    return element;
}



void display(){
    struct DLL *temp;
    if(first == NULL){
        printf("List is empty\n");
    }
    else{
        temp = first;
        do{
            printf("%d->", temp->data);
            temp = temp->next;

        } while (temp != NULL);
        printf("NULL\n");
    }
}

int main(){
    int data;
    insertAtBeginning(100);
    display();
    insertAtEnd(300);
    display();
    insertAtBeginning(200);
    display();
     data = deleteFromBeginning();
     if(data != -1){
         printf("%d was deleted from the beginning\n", data);
     }
     display();
     data = deleteFromEnd();
     if(data != -1)
         printf("%d was deleted from the end\n", data);
     display();
    insertAtPosition(600, 2);
    display();
    data = deleteAtPosition(2);
    if(data != -1)
         printf("%d was deleted\n", data);
     display();
     return 0;
}