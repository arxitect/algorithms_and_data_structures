#include <stdio.h>
#include "data.h"

int getMax(const int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);

void main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");
    
    radixSort(data, length);

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}

/* getMax: get max element of array */
int getMax(const int arr[], int n)
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

/*countSort: function to do counting sort of arr*/
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1];
  
    // Build the output array
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
}

/* radixSort */
void radixSort(int arr[], int n) 
{ 
    int m = getMax(arr, n); //get max element of array

    //Do counting sort for every digit.
    for (int exp = 1; m / exp > 0; exp *= 10)//<--
        countSort(arr, n, exp); 
}
