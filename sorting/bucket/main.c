#include <stdio.h>
#include "data.h"

void bucketSort(double arr[], int length);

int main()
{   
    int length = sizeof(data)/sizeof(double); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%.2f ", data[i]);

    printf(" Input\n");

    bucketSort(data, length);

    for( int i = 0; i < length; i++) // printing input data
        printf("%.2f ", data[i]);

    printf(" Output\n");

    return 0;
}

void bucketSort(double arr[], int length)
{

}