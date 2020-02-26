#include <stdio.h>
#include "data.h"

void bucketSort(int arr[], int length);

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

void bucketSort(int arr[], int n)
{
    int i, j;   
    int count[n];  
    for(i=0; i < n; i++){   
        count[i] = 0;   
    }       
    for(i=0; i < n; i++){    
        (count[arr[i]])++; 
    }     
    for(i=0,j=0; i < n; i++){   
    for(; count[i]>0;(count[i])--) 
        {       
            arr[j++] = i; 
        }  
    }
}