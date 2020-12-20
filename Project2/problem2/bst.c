#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {

   // check if tree is empty
    if (*root == NULL){
    
        *root = (struct bst_node *)malloc(sizeof(struct bst_node));
        // printf("NEW NODE! loc:%p\n", *root);
        // printf("NEW NODE! word:%s\n", word);

        (*root)->data = word;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    // if not empty, add value to child
    if (strcmp((*root)->data, word) >= 0) {
        add(&((*root)->left), word);
    } else {
        add(&((*root)->right), word);
    }

}

 
void inorder ( bst_node * root ) {
    
    
    if (root == NULL) {return;}
    // printf("---- start printing tree ---\n");
    // printf("current root: %p", root);
    // printf("current root left: %p", root->left);

    // print left child
    inorder(root->left);

    // print values stored at root
    printf("%s ", root->data);

    // print right child
    inorder(root->right);

    return;
}


 
char * removeSmallest (  bst_node ** root ){
    
    if (*root != NULL){   

        // current node NON-empty, go to left child 
        char* result;
        result = removeSmallest(&((*root)->left));

        // check if left child contains a min
        if (result == NULL) {
            // left child doesn't have a min => current node is the min
            char* ret_val = (*root)->data;
            (*root) = (*root)->right;
            return ret_val;
        }

        return result;  // left child has a min, return the min
    }
    
    // current node is NULL, return NULL
    return NULL;
}

 
char * removeLargest (  bst_node ** root ){
    if (*root != NULL){   

        // current node NON-empty, go to right child 
        char* result;
        result = removeLargest(&((*root)->right));

        // check if right child contains a max
        if (result == NULL) {
            // right child doesn't have a max => current node is the max
            char* ret_val = (*root)->data;
            (*root) = (*root)->left;
            return ret_val;
        }

        return result;  // right child has a max, return the max
    }
    return NULL;
}




