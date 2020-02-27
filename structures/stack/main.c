#include <stdio.h>

#define MAX 10

//push to stack
void push(int *data,int n)
{
    int range = MAX;
    while(range-- > 1){
        
    }
}
//pop from stack
int pop()
{
    return 0;
}

int main()
{   
    int data[MAX] = {0}; // stack

    int i = 0;
    while(i < 10){
        printf("Enter some number: \n");
        int n;
        scanf("%d", &n);
        push(data, n);
    }
    return 0;
}

