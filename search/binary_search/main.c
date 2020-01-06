#include <stdio.h>
#include "data.h"

int binsearch(int[], int, int);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    int pattern; /* user input */

    for( int i = 0; i < length; i++) // printing data
        printf("%d ", data[i]);
    printf(" Data\n");

    printf("Input search number: ");
    scanf("%d",&pattern);
    binsearch(data, pattern, length);

    return 0;
}

/* binary search */
int binsearch(int arr[], int pattern, int length)
{   
    int low, mid, high;

    low = 0;
    high = length - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(pattern < arr[mid])
            high = mid - 1;
        else if(pattern > arr[mid])
            low = mid + 1;
        else{ 
            printf("Value %d has found!\n", pattern);
            return 0;
        }
    }

    printf("Value %d not found!\n", pattern);
    return 0;
}
