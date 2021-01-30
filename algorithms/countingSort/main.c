#include <stdio.h>
#include <malloc.h>

void countSort(int array[], int length);
int getMax(const int array[], int size);
void printData(const int data[], int length);

int main()
{
    int data[9] = { 54, 38, 82, 61, 0, 11, 23, 76, 23 };
    int length = sizeof(data)/sizeof(int);

    printData(data, length);

    printf(" Input\n");

    countSort(data, length);

    printData(data, length);

    printf(" Output\n");

    return 0;
}

/* getMax: pull max element of array */
int getMax(const int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/* count sort */
void countSort(int array[], int length)
{
    int k = getMax(array, length) + 1;

    // array for counting
    int *c = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i <= length; i++) {
        c[i] = 0;
    }

    // counting elements
    for (int i = 0; i < length; i++) {
        c[array[i]]++;
    }

    int b = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < c[i]; j++) {
            array[b++] = i; // insert element
        }
    }
}

void printData(const int data[], int length)
{
    for( int i = 0; i < length; i++)
        printf("%d ", data[i]);
}
