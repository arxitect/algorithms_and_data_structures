#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// struct of bucket
struct bucket 
{
    int count;
    int *values;
};

void bucketSort(int array[],int n);
int compareIntegers(const void *first, const void *second);

int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");

    bucketSort(data, length);

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/*compareIntegers: function for qsort*/
int compareIntegers(const void* first, const void* second)
{
    return *((int*)first) - *((int*)second);
}

/* bucket sort*/
void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    // Divide the unsorted elements among 3 buckets
    // < 0    : first
    // 0 - 10 : second
    // > 10   : third
    for (i = 0; i < n; i++) {
        if (array[i] < 0){
            buckets[0].values[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10){
            buckets[2].values[buckets[2].count++] = array[i];
        }
        else{
            buckets[1].values[buckets[1].count++] = array[i];
        }
    }

    for (k = 0, i = 0; i < 3; i++) {
        // Use quick sort to sort each bucket individually
        qsort(buckets[i].values, buckets[i].count, sizeof(int), compareIntegers);
        for (j = 0; j < buckets[i].count; j++) {
            array[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count;
        free(buckets[i].values);
    }
}