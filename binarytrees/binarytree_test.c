#include "binarytree.c"

//createTree
void should_return_tree_with_null_root_value(){
    BinaryTree* tree = createTree();
    if (tree->root == NULL){
        printf("success part 1\n");
    }
    else printf("check create binary tree function\n");
}

//insert
void should_return_neg_one_for_insterting_in_null_tree(){
    BinaryTree* tree = NULL;
    int data = 0;
    if(insert(tree, data) == -1){
        printf("success part 2\n");
    }
    else printf("check insert\n");
}

void insert_root_and_return_zero(){
    BinaryTree* tree = createTree();
    int data = 10;
    if(insert(tree, data) == 0 && tree->root->data == 10){
        printf("success part 3\n");
    }
    else printf("check insertion of root\n");
}

void should_insert_node_to_left(){
    BinaryTree* tree = createTree();
    int data = 10;
    int data2 = 5;
    insert(tree, data);
    printf("tree root data is %d\n", tree->root->data );
    printf("hello\n");
    //if (tree->root->left->data == NULL) printf("null\n");
    //printf("%d\n", tree->root->left->data);
    //
    insert(tree, data2);
    printf("tree data is %d\n", tree->root->right->data );

    // if(insert(tree, data2) == 1){// && tree->root->left->data == 5){
        
    //     printf("success part 4\n");
    // }
    // else printf("check insert left of root\n");
}

void should_insert_node_to_right(){
    BinaryTree* tree = createTree();
    int data = 10;
    int data2 = 15;
    insert(tree, data);
    if(insert(tree, data2) == 0 && tree->root->right->data == 15){
        printf("success part 5\n");
    }
    else printf("check insert right of root\n");
}

int main(){

    should_return_tree_with_null_root_value();
    should_return_neg_one_for_insterting_in_null_tree();
    insert_root_and_return_zero();
    should_insert_node_to_left();
    //should_insert_node_to_right();

    return EXIT_SUCCESS;
}