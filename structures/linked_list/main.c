#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

//Start of list
struct node *start = NULL;

void insert_at_begin(int x);
void insert_at_end(int x);
void traverse();
void delete_from_begin();
void delete_from_end();

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
                insert_at_begin(data);
                break;
            case 2:
                printf("Enter value of element\n");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                traverse();
                break;
            case 4:
                delete_from_begin();
                break;
            case 5:
                delete_from_end();
                break;
            case 6:
                return 0;
            default:
                 printf("Please enter valid input.\n");
                 continue;
        }
    }

    return 0;
}

/*insert_at_begin: insert element to top of list*/
void insert_at_begin(int x) 
{
    struct node *t;

    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    count++;

    if (start == NULL) {
        start = t;
        start->next = NULL;
        return;
    }

    t->next = start;
    start = t;
}

/*insert_at_end: insert element to end of list*/
void insert_at_end(int x) 
{
    struct node *t, *temp;

    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    count++;

    if (start == NULL) {
        start = t;
        start->next = NULL;
        return;
    }

    temp = start;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
    t->next = NULL;
}

/*traverse: show elements of list*/
void traverse() 
{
    struct node *t;

    t = start;

    if (t == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("There are %d elements in linked list.\n", count);

    while (t->next != NULL) {
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("%d\n", t->data);
}

/*delete_from_begin: deleting element from top of list*/
void delete_from_begin() 
{
    struct node *t;
    int n;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    n = start->data;
    t = start->next;
    free(start);
    start = t;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}

/*delete_from_end: deleting element from end of list*/
void delete_from_end() 
{
    struct node *t, *u;
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

    t = start;

    while (t->next != NULL) {
        u = t;
        t = t->next;
    }

    n = t->data;
    u->next = NULL;
    free(t);

    printf("%d deleted from end successfully.\n", n);
}