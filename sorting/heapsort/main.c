#include <stdio.h>
#include "data.h"

void heappfy(int arr[], int n, int i);
void heapSort(int arr[], int length);
void swap(int *from, int *to);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    heapSort(data, length);

    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* heapify: build heap */
void heapify(int arr[], int n, int i)
{   
    int largest = i;   

    int l = 2 * i + 1; // left
    int r = 2 * i + 2; // right

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* heapSort: sorting array */
void heapSort(int arr[], int length)
{
    for (int i = length / 2 - 1; i >= 0 ; i--)
        heapify(arr, length, i);

    for (int i = length - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void swap(int *from, int *to)
{
    int tmp = *from;

    *from = *to;
    *to = tmp;
}