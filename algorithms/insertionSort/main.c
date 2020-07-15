#include <stdio.h>
#include "data.h"

void insertionSort( int arr[], int length);
void swap(int *from, int *to);

int main()
{   
    int length = sizeof(data) / sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    insertionSort(data, length);

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* insertionSort */
void insertionSort( int arr[], int length)
{
    for(int i = 1; i < length; i++){
        int k = i;
        while(k > 0 && arr[k - 1] > arr[k]){ // while element not sorted
            swap(&arr[k - 1], &arr[k]);
            k--;
        }
    }
}

/* swap: swap two values*/
void swap(int *from, int *to)
{
    int tmp = *from;

    *from = *to;
    *to = tmp;
}