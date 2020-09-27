#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node  *next;
};
typedef struct node  Node;
// Start of list
Node *start = NULL;

void insertAtBegin(int x);
void insertAtEnd(int x);
void traverse();
void deleteFromBegin();
void deleteFromEnd();

int count = 0;

int main ()
{
    int i, data;

    while (true) {
        printf("1. Insert an element at the beginning of linked list.\n");
        printf("2. Insert an element at the end of linked list.\n");
        printf("3. Traverse linked list.\n");
        printf("4. Delete an element from beginning.\n");
        printf("5. Delete an element from end.\n");
        printf("6. Exit\n");

        scanf("%d", &i);

        switch(i){
            case 1:
                printf("Enter value of element\n");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("Enter value of element\n");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                traverse();
                break;
            case 4:
                deleteFromBegin();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                return 0;
            default:
                 printf("Please enter valid input.\n");
                 continue;
        }
    }
}

/* insertAtBegin: insert element to top of list */
void insertAtBegin(int x) 
{
    Node *temp;

    temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    count++;

    if (start == NULL) {
        start = temp;
        start->next = NULL;
        return;
    }

    temp->next = start;
    start = temp;
}

/* insertAtEnd: insert element to end of list */
void insertAtEnd(int x) 
{
    Node *newNode, *temp;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    count++;

    if (start == NULL) {
        start = newNode;
        start->next = NULL;
        return;
    }

    temp = start;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = NULL;
}

/* traverse: show elements of list */
void traverse() 
{
    Node *temp;

    temp = start;

    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("There are %d elements in linked list.\n", count);

    while (temp->next != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

/* deleteFromBegin: deleting element from top of list */
void deleteFromBegin() 
{
    Node *temp;
    int n;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    n = start->data;
    temp = start->next;
    free(start);
    start = temp;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}

/* deleteFromEnd: deleting element from end of list */
void deleteFromEnd() 
{
    Node *target, *u;
    int n;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    count--;

    if (start->next == NULL) {
        n = start->data;
        free(start);
        start = NULL;
        printf("%d deleted from end successfully.\n", n);
        return;
    }

    target = start;

    while (target->next != NULL) {
        u = target;
        target = target->next;
    }

    n = target->data;
    u->next = NULL;
    free(target);

    printf("%d deleted from end successfully.\n", n);
}