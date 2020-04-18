#include <stdio.h>
#include <stdlib.h>

struct set
{
     int key;
    int data;
};

int hashFunction(int key);
int checkPrime(int n);
int getPrime(int n);
void initArray();
void insert(int key, int data);
void removeElement(int key);
void display();

struct set *array; // pointer for storage data
int capacity = 10; // max size of arr
int size = 0; // size of arr

void main()
{
    int choice, key, data;
    int c = 0;
    initArray();
    do{
        printf("1.Insert item in the Hash Table\n"
                      "2.Remove item from the Hash Table\n"
                      "3.Check the size of Hash Table\n"
                      "4.Display a Hash Table\n\n"
                      "Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter key :\t");
                scanf("%d", &key);
                printf("Enter data :\t");
                scanf("%d", &data);
                insert(key, data);
                break;
            case 2:
                printf("Enter the key to delete:");
                scanf("%d", &key);
                removeElement(key);
                break;
            case 3:
                printf("Size of Hash Table is:%d\n", size);
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid Input\n");
        }
        printf("\nDo you want to continue (press 1 for yes): ");
        scanf("%d", &c);
  }while (c == 1);
}
/*hashFunction: return hash of key*/
int hashFunction(int key)
{
    return (key % capacity);
}
/*checkPrime: to check if given input (i.e n) is prime or not*/
int checkPrime(int n)
{
    if (n == 1 || n == 0)
        return 0;

    for (int i = 2; i < n / 2; i++){
        if (n % i == 0)
            return 0;
    }

    return 1;
}

/*getPrime: returns prime number just greater than array capacity*/
int getPrime(int n)
{
    if(n % 2 == 0)
        n++;

    while(!checkPrime(n))
        n += 2;

    return n;
}

/*initArray: initialize empty array*/
void initArray()
{
    capacity = getPrime(capacity);
    array = (struct set *)malloc(capacity * sizeof(struct set));

    for (int i = 0; i < capacity; i++){
        array[i].key = 0;
        array[i].data = 0;
    }
}

/*insert: insert new element of array*/
void insert(int key, int data)
{
    int index = hashFunction(key);

    if (array[index].data == 0){
        array[index].key = key;
        array[index].data = data;
        size++;
        printf("\n Key (%d) has been inserted \n", key);
    }else if (array[index].key == key)
        array[index].data = data;
    else
        printf("\n Collision occurred  \n");

}

/*removeElement: remove element of array*/
void removeElement(int key)
{
    int index = hashFunction(key);
    if (array[index].data == 0)
        printf("\n This key does not exist \n");
    else{
        array[index].key = 0;
        array[index].data = 0;
        size--;
        printf("\n Key (%d) has been removed \n", key);
    }
}

/*display: display elements of array*/
void display()
{
    for (int i = 0; i < capacity; i++){
        if (array[i].data == 0)
            printf("\n array[%d]: empty ", i);
        else
            printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
    }
}