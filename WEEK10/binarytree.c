#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node{
	int value;
	struct node* left;
	struct node* right;
};

struct node* newNode(int value) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->value = value; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
}

bool printPath(struct node* root, struct node* target_leaf)
{
    if (root == NULL) 
        return false; 
  
    if (root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf)) { 
        printf("%d ", root->value); 
        return true; 
    } 
  
    return false; 
} 
  
void getTargetLeaf(struct node* node, int* max_sum_ref, int curr_sum, struct node** target_leaf_ref) 
{ 
    if (node == NULL) 
        return; 
  
    curr_sum = curr_sum + node->value; 
  
    if (node->left == NULL && node->right == NULL) { 
        if (curr_sum > *max_sum_ref) { 
            *max_sum_ref = curr_sum; 
            *target_leaf_ref = node; 
        } 
    } 
  
    getTargetLeaf(node->left, max_sum_ref, curr_sum, target_leaf_ref); 
    getTargetLeaf(node->right, max_sum_ref, curr_sum, target_leaf_ref); 
} 
  
int maxSumPath(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
  
    struct node* target_leaf; 
    int max_sum = INT_MIN; 
  
    getTargetLeaf(node, &max_sum, 0, &target_leaf); 
  
    printPath(node, target_leaf); 
  
    return max_sum;  
} 
  
  
int main() 
{ 
    struct node* root = NULL; 
  
    root = newNode(2); 
    root->left = newNode(7); 
    root->right = newNode(5); 
    root->left->left = newNode(2); 
    root->left->right = newNode(6); 
  	root->left->right->left = newNode(5); 
    root->left->right->right = newNode(11); 
	root->right->right = newNode(9);
	root->right->right->left = newNode(4);

    printf("Following are the nodes on the maximum "
           "sum path \n"); 
    int sum = maxSumPath(root); 
    printf("\nSum of the nodes is %d ", sum); 
   
    return 0; 
}
