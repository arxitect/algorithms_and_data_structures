#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void swap(int *, int *);
int partition (int [], int, int) ; 
void quickSort(int [], int, int);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    quickSort(data, 0, length - 1); 

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int q = partition(arr, low, high); 
  
        quickSort(arr, low, q - 1); 
        quickSort(arr, q + 1, high); 
    } 
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 