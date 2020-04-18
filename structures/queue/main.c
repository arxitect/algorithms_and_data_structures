#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define MAX 50

void insert();
void delete();
void display();

int queue[MAX];
int rear = - 1; 
int front = - 1;

void main()
{
    int choice;
    while (true){
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
}

/* insert: insert element to queue */
void insert()
{
    int item;

    if(rear == MAX - 1)
        printf("Queue Overflow \n");
    else{
        if(front== - 1)
            front = 0;

        printf("Inset the element in queue : ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

/* delete: delete delete element from queue */
void delete()
{
    if(front == - 1 || front > rear)
        printf("Queue Underflow \n");
    else{
        printf("Element deleted from queue is : %d\n", queue[front]);
        front++;
    }
}

/* display: display elements of queue */
void display()
{
    int i;

    if(front == - 1)
        printf("\nQueue is empty \n");
    else{
        printf("\nQueue is : \n");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}