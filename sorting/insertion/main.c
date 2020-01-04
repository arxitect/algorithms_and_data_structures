#include <stdio.h>
#include "data.h"

void insort(int, int[]);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    insort(length, data);

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* insertion sort */
void insort(int length, int arr[])
{
    for(int i = 1; i < length; i++){
        int k = i;
        while(k > 0 && arr[k - 1] > arr[k]){
            int tmp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = tmp;
            k--;
        }
    }

}