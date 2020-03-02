#include <stdio.h>

#define MAX 10

//push to stack
void push(int *data,int n)
{
    *data++ = n;
}

//pop from stack
int pop(int *data)
{   
    printf("%d \n", (*data)--);
    return 0;
}

int main()
{   
    int data[MAX] = {0}; // stack

    int i = 0;
    while(i++ < MAX){
        printf("Enter some number: \n");
        int n;
        scanf("%d", &n);
        push(data, n);
    }

    int j = 0;
    while(j++ < MAX){
        pop(data);
    }

    return 0;
}

