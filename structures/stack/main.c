#include <stdio.h>
#define MAXSIZE 5
 
struct stack
{
    int top; // key of first element
    int data[MAXSIZE];
};

struct stack stackInstance;
 
void push(void);
void pop(void);
void display(void);
 
int main ()
{
    int choice;
    int option = 1;
    stackInstance.top = -1;
 
    printf ("STACK OPERATIONS\n");
    while (option) {
        printf("------------------------------------------\n");
        printf("1    -->    PUSH               \n");
        printf("2    -->    POP               \n");
        printf("3    -->    DISPLAY               \n");
        printf("4    -->    EXIT           \n");
        printf("------------------------------------------\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &option);
    }
}

/* push: put new element to stack */
void push ()
{
    int num;
    if (stackInstance.top == (MAXSIZE - 1))
        printf ("stackInstance is Full\n");
    else{
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        stackInstance.top++;
        stackInstance.data[stackInstance.top] = num;
    }
}

/* pop: extract element from stack */
void pop ()
{
    if (stackInstance.top == - 1)
        printf ("stackInstance is Empty\n");
    else{
        printf ("poped element is = %d\n", stackInstance.data[stackInstance.top]);

        stackInstance.data[stackInstance.top] = 0;
        stackInstance.top--; 
    }
}

/* display: show stack */
void display ()
{
    int i;
    if (stackInstance.top == -1)
        printf ("stackInstance is empty\n");
    else{
        printf ("\n The status of the stack is \n");
        for (i = stackInstance.top; i >= 0; i--)
            printf ("%d\n", stackInstance.data[i]);
    }
    printf ("\n");
}