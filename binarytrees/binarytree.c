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

//additional function
void insert_node(Node* node_ptr, int data){
    printf("insert node function has been summoned\n");
    struct Node* n = (Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    if(node_ptr->data < data){
        printf("left\n");
        if(node_ptr->right == NULL){
            printf("left is null\n");
            node_ptr->right = n;
        }
        else{
            insert_node(node_ptr->right, data);
        }
    }
    else if(node_ptr->data >= data){
        printf("right\n");
        if(node_ptr->left != NULL){
            insert_node(node_ptr->left, data);
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
        printf("Reached the else statement\n");
        struct Node* node_ptr = tree->root;
        printf("created a node pointer pointing to root\n");
        printf("The value of data at node_ptr is %d\n", node_ptr->data);
        insert_node(node_ptr, data);
        printf("inserted node\n");
        return 1;
    }
    
}

Node* check_branch(BinaryTree *t, Node* n, int d){ //if a function returns a pointer to something on stack, then it's a bad idea
    n = t->root;
    if(d < t->root->data){
        t->root = t->root->left;
    }
    else if(d > t->root->data){
        t->root = t->root->right;
    }
    
    return t->root;
}

int insert_better(BinaryTree *tree, int data) {

    if (tree == NULL) return -1;
    //if (data == NULL) return -1; // This would prevent data == 0 to enter into the system

    if (tree->root == NULL){
        struct Node* n = (Node*)malloc(sizeof(struct Node));
        tree->root = n;
        return 0;
    }
    else {
        struct Node* node_ptr = tree->root;
        check_branch(tree, node_ptr, data);
        return 0;
    } // compare data to left and right nodes.
    
}

/**
 *  @brief Retrieves the value from the binary tree.
 * 
 *  @param tree Pointer to the binary tree.
 *  @param out_value Pointer to the variable to store the retrieved value.
 *  @return 0 if the retrieval is successful, -1 if the tree is NULL.
 */
int get(BinaryTree *tree, int* out_value) {

}

int delete(BinaryTree *tree, int value) {

}

void freeTree(BinaryTree *tree){ // do it reccursively

}

// int main(int argc, char *argv[])
// {
//   return EXIT_SUCCESS;
// }