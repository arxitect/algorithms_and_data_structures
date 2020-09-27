#include <stdlib.h>
#include <stdio.h>

struct binTree {
    int data;
    struct binTree *right, *left; // children of node
};

typedef struct binTree node;

void insert(node **tree, int val);
void printPreorder(node *tree);
void printInorder(node *tree);
void printPostorder(node *tree);
void delTree(node *tree);
node *search(node **tree, int val);

int main()
{
    node *root;
    node *tmp;

    root = NULL;
    // Inserting nodes into tree 
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    // Printing nodes of tree 
    printf("Pre Order Display\n");
    printPreorder(root);

    printf("In Order Display\n");
    printInorder(root);

    printf("Post Order Display\n");
    printPostorder(root);

    // Search node into tree 
    tmp = search(&root, 4);
    if (tmp)
        printf("Searched node = %d\n", tmp->data);
    else
        printf("Data Not found in tree.\n");

    // Deleting all nodes of tree 
    delTree(root);
}

/* insert: insert to tree */
void insert(node **tree, int val)
{
    node *temp = NULL;
    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
        insert(&(*tree)->left, val);
    else if(val > (*tree)->data)
        insert(&(*tree)->right, val);

}

/* printPreorder: print tree */
void printPreorder(node *tree)
{
    if (tree){
        printf("%d\n",tree->data);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }

}

/* printInorder: print tree */
void printInorder(node *tree)
{
    if (tree){
        printInorder(tree->left);
        printf("%d\n",tree->data);
        printInorder(tree->right);
    }
}

/* printPostorder: print tree */
void printPostorder(node *tree)
{
    if (tree){
        printPostorder(tree->left);
        printPostorder(tree->right);
        printf("%d\n",tree->data);
    }
}

/* delTree: deleting tree */
void delTree(node *tree)
{
    if (tree){
        delTree(tree->left);
        delTree(tree->right);
        free(tree);
    }
}

/* search: search value in tree */
node *search(node **tree, int val)
{
    if(!(*tree)){
        return NULL;
    }

    if(val < (*tree)->data){
        search(&((*tree)->left), val);
    }else if(val > (*tree)->data){
        search(&((*tree)->right), val);
    }else if(val == (*tree)->data){
        return *tree;
    }
}