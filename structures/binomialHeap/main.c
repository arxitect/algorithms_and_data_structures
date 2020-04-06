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
node *mergeBinomialTrees(node *b1, node *b2);
void swap(node *b1, node *b2);
/*makeBinomialHeap();
binomialHeapMinimum();
binomialHeapUnion();*/

int main()
{
   
    return 0;
}

/*newNode: to create a new node of heap*/
node *newNode(int key)
{
    node *temp = malloc(sizeof(node));
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}

node *mergeBinomialTrees(node *b1, node *b2)
{
    if(b1->data > b2->data)
        swap(b1, b2);

    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;
}

/*swap: swap two binomial trees*/
void swap(node *b1, node *b2)
{
    node *temp = malloc(sizeof(node));
    *temp = *b1;
    *b1 = *b2;
    *b2 = *temp;
}