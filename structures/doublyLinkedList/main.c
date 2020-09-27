#include <stdio.h>
#include <stdlib.h>

// Node of linked list
struct node  {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

// Head of list
Node* head = NULL; 

Node* getNewNode(int x);
void insertAtHead(int x);
void insertAtTail(int x);
void print();
void reversePrint();

int main() {
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

    return 0;
}
/*getNewNode: create New node of list*/
Node* getNewNode(int x) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* insertAtHead: put element to top of list */
void insertAtHead(int x) 
{
    Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head; 
    head = newNode;
}

/* insertAtTail: put element to end of list */
void insertAtTail(int x)
{
    Node* temp = head;
    Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; 
    temp->next = newNode;
    newNode->prev = temp;
}

/* print: to display list */
void print() 
{
    Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* reversePrint: to display reverse list */
void reversePrint() 
{
    Node* temp = head;
    if(temp == NULL) return;

    while(temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}