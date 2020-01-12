#include <stdio.h>
#include <stdlib.h>
#include "data.h"


int main()
{   
    int length = sizeof(data)/sizeof(int); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%d ", data[i]);

    printf(" Input\n");



    for( int i = 0; i < length; i++) // printing output data
        printf("%d ", data[i]);

    printf(" Output\n");

    return 0;
}
