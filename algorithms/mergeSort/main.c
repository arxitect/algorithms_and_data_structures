#include <stdio.h>
#include <malloc.h>
#include "data.h"

void mergeSort(int arr[], int l, int r);

void main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    mergeSort(data, 0, length - 1);

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* mergeSort */
void mergeSort(int arr[], int left, int right)
{
    if (left == right)
        return; // if one elem

    int mid = (left + right) / 2;  // mid of data

    mergeSort(arr, left, mid); // start merge sort first half
    mergeSort(arr, mid + 1, right); // start merge sort second half

    int *tmp = (int*)malloc(right * sizeof(int));
    int i = left;
    int j = mid + 1;
    int step;
    for (step = 0; step < right - left + 1; step++) {
        if ((j > right) || ((i <= mid) && (arr[i] < arr[j]))) {
          tmp[step] = arr[i];
          i++;
        }else {
          tmp[step] = arr[j];
          j++;
        }
    }
    
    for (step = 0; step < right - left + 1; step++)
        arr[left + step] = tmp[step];
}