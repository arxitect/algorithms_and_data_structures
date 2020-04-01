#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

typedef char DATA;
 
struct node
{
    DATA d;
    struct node *left;
    struct node *right;
};
 
typedef struct node NODE;
typedef NODE *BTREE;
 
BTREE newNode(void);
BTREE initNode(DATA d, BTREE p1, BTREE p2);
BTREE createTree(DATA a[], int i, int size);
void preorder (BTREE root);
void inOrder (BTREE root);
void postOrder (BTREE root);
 

int main(void)
{
    char a[ARRAY_SIZE] = {'g','d','i','b','f','h','j','a','c','e'};
    BTREE root;
 
    root = createTree(a, 0, ARRAY_SIZE) ;
    assert(root != NULL);

    printf("Preorder\n");
    preorder(root);
    printf("\n");

    printf("Inorder\n");
    inOrder(root);
    printf("\n");
 
    printf("Postorder\n");
    postOrder(root);
    printf("\n");
}

BTREE newNode()
{
    return ((BTREE)malloc(sizeof(NODE)));
}
 
BTREE initNode(DATA d1, BTREE p1, BTREE p2)
{
    BTREE t;
 
    t = newNode();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}
 
BTREE createTree(DATA a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return(initNode(a[i],
    createTree(a, 2*i+1, size),
    createTree(a, 2*i+2, size)));
}
 

void preorder(BTREE root)
{
    if (root != NULL) {
        printf("%c ", root->d);
        preorder(root -> left);
        preorder(root -> right);
    }
}
 

void inOrder(BTREE root)
{
    if (root != NULL) {
        inOrder(root -> left);
        printf("%c ", root->d);
        inOrder(root -> right);
    }
}
 
 
void postOrder (BTREE root)
{
    if (root != NULL) {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%c ", root->d);
    }
}