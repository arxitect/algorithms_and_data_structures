#include <stdio.h>
#include "data.h"
#include <string.h>
#define RANGE 255

void countSort(int arr[], int length);

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

/* count sort */
void countSort(int arr[],int length) 
{ 

    char output[length]; 
  
    int count[RANGE + 1], i; 
    memset(count, 0, sizeof(count)); 
  
    for(i = 0; arr[i]; ++i) 
        ++count[arr[i]]; 

    for (i = 1; i <= RANGE; ++i) 
        count[i] += count[i-1]; 
  
    for (i = 0; arr[i]; ++i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 
  
    /* 
     For Stable algorithm  
     for (i = sizeof(arr)-1; i>=0; --i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    }    
    For Logic : See implementation 
    */
  
    for (i = 0; arr[i]; ++i) 
        arr[i] = output[i]; 
} 