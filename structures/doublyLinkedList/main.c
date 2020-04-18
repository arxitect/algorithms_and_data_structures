#include <stdio.h>
#include <stdlib.h>

//Doubly linked list
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};

//Head of list
struct Node* head = NULL; 

struct Node* getNewNode(int x);
void insertAtHead(int x);
void insertAtTail(int x);
void print();
void reversePrint();

void main() {
    insertAtHead(43); 
    print();

    insertAtTail(2); 
    print(); 
    reversePrint();

    insertAtTail(4); 
    print(); 
    reversePrint();

    insertAtTail(6); 
    print();
    reversePrint();

    insertAtTail(8); 
    print(); 
    reversePrint();
    
}
/*getNewNode: create New node of list*/
struct Node* getNewNode(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*insertAtHead: put element to top of list*/
void insertAtHead(int x) 
{
    struct Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head; 
    head = newNode;
}

/*insertAtTail: put element to end of list*/
void insertAtTail(int x)
{
    struct Node* temp = head;
    struct Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; 
    temp->next = newNode;
    newNode->prev = temp;
}

/*print: to display list*/
void print() 
{
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*reversePrint: to display reverse list*/
void reversePrint() 
{
    struct Node* temp = head;
    if(temp == NULL) return;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}