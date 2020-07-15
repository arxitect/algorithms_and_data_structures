#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
 
struct node
{
    char d;
    struct node *left;
    struct node *right;
};
 
struct node *newNode(void);
struct node *initNode(char d, struct node *p1, struct node *p2);
struct node *createTree(char a[], int i, int size);
void preOrder (struct node * root);
void inOrder (struct node * root);
void postOrder (struct node * root);

int main(void)
{
    char arr[ARRAY_SIZE] = {'g','d','i','b','f','h','j','a','c','e'};
    struct node * root;
 
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

/*newNode: allocate memory for new node*/
struct node *newNode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}
 
/*initNode: initialize new node*/
struct node *initNode(char d1, struct node *p1, struct node *p2)
{
    struct node * t;
 
    t = newNode();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}
 
/*createTree: create new tree*/
struct node *createTree(char arr[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return (initNode(arr[i], createTree(arr, 2*i+1, size), createTree(arr, 2*i+2, size)));
}
 
/*preOrder: print tree*/
void preOrder(struct node * root)
{
    if (root != NULL) {
        printf("%c ", root->d);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
 
/*inOrder: print tree*/
void inOrder(struct node * root)
{
    if (root != NULL) {
        inOrder(root -> left);
        printf("%c ", root->d);
        inOrder(root -> right);
    }
}
 
 /*postOrder: print tree*/
void postOrder (struct node * root)
{
    if (root != NULL) {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%c ", root->d);
    }
}