#include <stdio.h>
#include <malloc.h>
#include "data.h"

void countSort(int array[], int length);
int getMax(const int array[], int size);

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

/* getMax: pull max element of array */
int getMax(const int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/* count sort */
void countSort(int array[], int length)
{
    int k = getMax(array, length) + 1;

    int *c = (int *)malloc(sizeof(int) * k); // array for counting

    for (int i = 0; i <= length; i++){
        c[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        c[array[i]]++; // counting elements
    }

    int b = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < c[i]; j++) {
            array[b++] = i; // insert elem
        }
    }
}