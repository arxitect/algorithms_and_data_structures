#include <stdio.h>
#include "data.h"
#include <string.h>

void countSort(int arr[], int length);
int getMax(int array[], int size);

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

/* get max: pull max element of array */
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/* count sort */
void countSort(int* array, int n) 
{
    const int k = getMax(array, size);

    int c[k]; // array for counting
    for (int i = 0; i <= n; i++){
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        c[array[i]]++; // counting elements
    }
        
    int b = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < c[i]; j++) {
            array[b++] = i; // insert elem
        }
    }   
}