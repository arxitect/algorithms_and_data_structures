#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void mergeSort(int arr[], int l, int r);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    mergesort(data, 0, length - 1);

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

void mergesort(int arr[], int l, int r)
{
    if (l == r) return; // if one elem
    int mid = (l + r) / 2;  // mid of data

    mergesort(arr, l, mid); // start merge sort first half
    mergesort(arr, mid + 1, r); // start merge sort seconf half
    int i = l; 
    int j = mid + 1;

    int *tmp = (int*)malloc(r * sizeof(int)); 
    
    for (int step = 0; step < r - l + 1; step++){
        if ((j > r) || ((i <= mid) && (arr[i] < arr[j]))) {
          tmp[step] = arr[i];
          i++;
        }
        else {
          tmp[step] = arr[j];
          j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++)
        arr[l + step] = tmp[step];
}