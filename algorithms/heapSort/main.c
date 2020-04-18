#include <stdio.h>
#include "data.h"

void heapSort(int arr[], int length);
void heapify(int arr[], int n, int i);
void swap(int *from, int *to);

void main()
{   
    int length = sizeof(data) / sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    heapSort(data, length);

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* heapify: to heapify subtree with root node */
void heapify(int arr[], int n, int i)
{   
    int largest = i;   //Largest as root

    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    // if left child is larger then root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    //if right is larger then root
    if (r < n && arr[r] > arr[largest])
        largest = r;

    //if largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* heapSort: sorting array */
void heapSort(int arr[], int length)
{   
    // build heap
    for (int i = length / 2 - 1; i >= 0 ; i--)
        heapify(arr, length, i);

    // Extract elements from heap
    for (int i = length - 1; i >= 0; i--)
    {   
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // call heapify on the reduce heap
        heapify(arr, i, 0);
    }
}

/* swap: swap two values*/
void swap(int *from, int *to)
{
    int tmp = *from;

    *from = *to;
    *to = tmp;
}