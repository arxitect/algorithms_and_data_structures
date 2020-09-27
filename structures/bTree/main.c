#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
 
struct bTree
{
    char d;
    struct bTree *left, *right;
};

typedef struct bTree node;
 
node *newNode(void);
node *initNode(char d, node *p1, node *p2);
node *createTree(char a[], int i, int size);
void preOrder (node * root);
void inOrder (node * root);
void postOrder (node * root);

int main(void)
{
    char arr[ARRAY_SIZE] = {'g','d','i','b','f','h','j','a','c','e'};
    node *root;
 
    root = createTree(arr, 0, ARRAY_SIZE) ;
    assert(root != NULL);

    printf("Preorder\n");
    preOrder(root);
    printf("\n");

    printf("Inorder\n");
    inOrder(root);
    printf("\n");
 
    printf("Postorder\n");
    postOrder(root);
    printf("\n");

    return 0;
}

/* newNode: allocate memory for new node */
node *newNode()
{
    return ((node *)malloc(sizeof(node)));
}
 
/* initNode: initialize new node */
node *initNode(char d1, node *p1, node *p2)
{
    node * t;
 
    t = newNode();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}
 
/* createTree: create new tree */
node *createTree(char arr[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return (initNode(arr[i], createTree(arr, 2*i+1, size), createTree(arr, 2*i+2, size)));
}
 
/*preOrder: print tree*/
void preOrder(node * root)
{
    if (root != NULL) {
        printf("%c ", root->d);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
 
/* inOrder: print tree */
void inOrder(node * root)
{
    if (root != NULL) {
        inOrder(root -> left);
        printf("%c ", root->d);
        inOrder(root -> right);
    }
}
 
 /* postOrder: print tree */
void postOrder (node * root)
{
    if (root != NULL) {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%c ", root->d);
    }
}