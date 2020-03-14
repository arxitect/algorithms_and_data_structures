#include <stdio.h>
#include "data.h"
#include <string.h>
#define RANGE 7

void countSort(int arr[], int length);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");
    
    countSort(data, length);

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* count sort */
void countSort(int* array, int n) {
    int c[RANGE] = { 0 }; // array for counting

    for (int i = 0; i < n; i++) {
        c[array[i]]++; // counting elements
    }
        
    int b = 0;

    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < c[i]; j++) {
            array[b++] = i; // insert elem
        }
    }   
}