#include <stdio.h>
#include "data.h"

void swap(int *, int *);
int partition (int arr[], int low, int high) ; 
void quickSort(int arr[], int low, int high);

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

/*partition: Redistribution of elements in the array in such a way that elements less than the reference are placed in front of it, and more or equal after. */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j < high; j++) 
    { 
        if (arr[j] < pivot) //If smaller than the support element, place in front of it 
        {    
            swap(&arr[++i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* quickSort */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int q = partition(arr, low, high); 
        //Recursive for left and right half
        quickSort(arr, low, q - 1); 
        quickSort(arr, q + 1, high); 
    } 
}

/* swap: swap two values*/
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 