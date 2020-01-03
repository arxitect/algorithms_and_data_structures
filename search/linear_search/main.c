#include <stdio.h>
#include "data.h"

int linsearch(int[], int, int);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    int pattern; /* user input */

    for( int i = 0; i < length; i++) // printing data
        printf("%d ", data[i]);
    printf(" Data\n");

    printf("Input search number: ");
    scanf("%d",&pattern);
    linsearch(data, pattern, length);

    return 0;
}

/* insertion sort */
int linsearch(int arr[], int pattern, int length)
{
    for( int i = 0; i < length; i++){ // printing data
        if(arr[i] == pattern){
            printf("Value %d has found!\n", pattern);
            return 0;
        }
    }

    printf("Value %d not found!\n", pattern);
    return 0;
}
