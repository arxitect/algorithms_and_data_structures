#include <stdio.h>
#include "data.h"

void heappfy(int [], int , int );
void heapSort(int [], int);
void swap(int *, int *);

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

void heapify(int arr[], int n, int i)
{   
    int largest = i;   
// Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void swap(int *from, int *to)
{
    int tmp = *from;

    *from = *to;
    *to = tmp;
}