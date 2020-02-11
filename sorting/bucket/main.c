#include <stdio.h>
#include "data.h"


int main()
{   
    int length = sizeof(data)/sizeof(double); // size of data

    for( int i = 0; i < length; i++) // printing input data
        printf("%.2f ", data[i]);

    printf(" Input\n");


    for( int i = 0; i < length; i++) // printing input data
        printf("%.2f ", data[i]);

    printf(" Output\n");

    return 0;
}
