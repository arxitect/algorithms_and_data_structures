#include <malloc.h> 
  
struct node { 
    struct node* parent; 
    struct node* child; 
    struct node* left; 
    struct node* right; 
    int key; 
}; 
  
struct node* mini = NULL; 
  
int no_of_nodes = 0; 
  
void insertion(int val) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->key = val; 
    new_node->parent = NULL; 
    new_node->child = NULL; 
    new_node->left = new_node; 
    new_node->right = new_node; 
    if (mini != NULL) { 
        (mini->left)->right = new_node; 
        new_node->right = mini; 
        new_node->left = mini->left; 
        mini->left = new_node; 
        if (new_node->key < mini->key) 
            mini = new_node; 
    } 
    else { 
        mini = new_node; 
    } 
} 
  
void display(struct node* mini) 
{ 
    struct node* ptr = mini; 
    if (ptr == NULL) 
        printf("The Heap is Empty\n");
  
    else { 
        printf("The root nodes of Heap are:\n"); 
        do { 
            printf("%d",ptr->key); 
            ptr = ptr->right; 
            if (ptr != mini) { 
                printf("-->");
            } 
        } while (ptr != mini && ptr->right != NULL); 
        printf("\nThe heap has %d nodes\n",no_of_nodes);
    } 
} 
void find_min(struct node* mini) 
{   
    printf("min of heap is: %d\n", mini->key);
} 
  
int main() 
{ 
  
    no_of_nodes = 7; 
    insertion(4); 
    insertion(3); 
    insertion(7); 
    insertion(5); 
    insertion(2); 
    insertion(1); 
    insertion(10); 
  
    display(mini); 
  
    find_min(mini); 
  
    return 0; 
} 