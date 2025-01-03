#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  @brief Node structure representing each element in the binary tree.
 */
typedef struct Node {
  struct Node* left;
  struct Node* right;
  int data;
} Node;

/**
 *  @brief Binary tree structure containing the root pointer.
 */
typedef struct BinaryTree {
  struct Node* root;
} BinaryTree;

/**
 *  @brief Initializes a new binary tree.
 * 
 *  @return A pointer to the initialized BinaryTree.
 */
BinaryTree* createTree() {
    struct BinaryTree* tree = (BinaryTree*)malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    return tree;
}


int get(BinaryTree *tree, int* out_value);

//additional function
void insert_node(Node* node_ptr, int data){
    struct Node* n = (Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    if(node_ptr->data < data){
        if(node_ptr->right != NULL){
            insert_node(node_ptr->right, data);
            free(node_ptr);
        }
        else{
            node_ptr->right = n;
        }
    }
    else if(node_ptr->data >= data){
        if(node_ptr->left != NULL){
            insert_node(node_ptr->left, data);
            free(node_ptr);
        }
        else{
            node_ptr->left = n;
        }
    }
    else printf("check insert node function\n");
}

/**
 *  @brief Inserts a new node with the given data into the binary tree.
 * 
 *  @param tree Pointer to the binary tree.
 *  @param data The data to insert.
 *  @return 0 if the insertion is successful, -1 if the tree is NULL.
 */
int insert(BinaryTree *tree, int data) {

    if (tree == NULL) return -1;
    //if (data == NULL) return -1; // This would prevent data == 0 to enter into the system

    if (tree->root == NULL){
        struct Node* n = (Node*)malloc(sizeof(struct Node));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        tree->root = n;
        return 0;
    }
    else {
        struct Node* node_ptr = tree->root;
        insert_node(node_ptr, data);
        return 1;
    } 
}

int check_for_val(BinaryTree * tree, Node * node_ptr, int* out_value){

    if(node_ptr->data < * out_value){
        if(node_ptr->right != NULL){
            if(node_ptr->right->data == * out_value){
                return * out_value;
            }
            else{
                check_for_val(tree, tree->root->right, out_value);
            }
        }
        else{
            printf("out value does not exist in right\n");
            return 0;
        }
    }
    else if(tree->root->data >= * out_value){
        if(tree->root->left != NULL){
            if(node_ptr->left->data == * out_value){
                return * out_value;
            }
            else{
                check_for_val(tree, tree->root->left, out_value);
            }
        }
        else{
            printf("out value does not exist in left\n");
            return 1000;
        }
    }
    else printf("check try_get function\n");
        return -1000;
}


/**
 *  @brief Retrieves the value from the binary tree.
 * 
 *  @param tree Pointer to the binary tree.
 *  @param out_value Pointer to the variable to store the retrieved value.
 *  @return 0 if the retrieval is successful, -1 if the tree is NULL.
 */
int get(BinaryTree *tree, int* out_value) {
    if (tree == NULL) return -1;
    if (tree->root == NULL) return 0;

    if (tree->root->data == * out_value){
        return * out_value;
    }
    else{
        struct Node* n = (Node*)malloc(sizeof(struct Node));
        n = tree->root;
        check_for_val(tree,n, out_value);
    }

}

int delete(BinaryTree *tree, int value) {

}

void freeTree(BinaryTree *tree){ // do it reccursively

}

// int main(int argc, char *argv[])
// {
//   return EXIT_SUCCESS;
// }