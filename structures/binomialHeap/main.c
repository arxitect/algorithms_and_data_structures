#include <stdio.h>
#include <malloc.h>

typedef struct Node node;

struct Node {
    int data; 
    int degree;//count of child elements of node
    node* parent; //pointer to parent node
    node* child; //pointer to child node
    node* sibling; //pointer to right brother of node
};
 
node *newNode(int key);
/*makeBinomialHeap();
binomialHeapMinimum();
binomialHeapUnion();*/

int main()
{
    
    return 0;
}

node *newNode(int key)
{
    node *temp = malloc(sizeof(node));
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}