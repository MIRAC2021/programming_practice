#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* left;
  struct Node* right;
  int data;
} Node;

typedef struct BinaryTree {
  struct Node* root;
} BinaryTree;

BinaryTree* createTree() {
    struct BinaryTree* tree = (BinaryTree*)malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    return tree;
}


//additional function
void insert_node(Node* node_ptr, int data){
    struct Node* n = (Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    if(node_ptr->data <= data){
        if(node_ptr->left != NULL){
            insert_node(node_ptr->left, data);
        }
        else{
            node_ptr->left = n;
        }
    }
    else if(node_ptr->data > data){
        if(node_ptr->right != NULL){
            insert_node(node_ptr->right, data);
        }
        else{
            node_ptr->right = n;
        }
    }
}