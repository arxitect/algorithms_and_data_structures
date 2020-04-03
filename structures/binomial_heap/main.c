#include <stdio.h>
#include <malloc.h>
 
struct node {
    int n; 
    int degree;//count of child elements of node
    struct node* parent; //pointer to parent node
    struct node* child; //pointer to child node
    struct node* sibling; //pointer to right brother of node
};
 
int main()
{
    
    return 0;
}