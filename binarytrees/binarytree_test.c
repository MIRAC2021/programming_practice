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
    //insert(tree, data2);
    if(insert(tree, data2) == 1 && tree->root->left->data == 5){
        
        printf("success part 4\n");
    }
    else printf("check insert left of root\n");
}

void should_insert_node_to_right(){
    BinaryTree* tree = createTree();
    int data = 10;
    int data2 = 15;
    insert(tree, data);
    if(insert(tree, data2) == 1&&tree->root->right->data == 15){
        printf("success part 5\n");
    }
    else printf("check insert right of root\n");
}

// get function
// void should_return_neg_one_for_tree_doesnt_exist(){
//     BinaryTree* tree = NULL;
//     int val = 10;
//     int *data = &val;
//     if(get(tree, data) == -1){
//         printf("success part 6\n");
//     }
//     else printf("check get for get -1 for tree equals NULL\n");
// }

// void should_get_neg_one_for_root_is_null(){
//     BinaryTree* tree = createTree();
//     int val = 10;
//     int *data = &val;
//     if(get(tree, data) == -1){
//         printf("success part 7\n");
//     }
//     else printf("check get for get -1 for root equals NULL\n");
// }


// try_get function
void should_return_out_value_for_try_get_at_root(){
    BinaryTree* tree = createTree();
    int val = 10;
    insert(tree, 10);
    // printf("root: %d\n", tree->root->data);
    if(try_get(tree, val) == 10){
        printf("success part 8\n");
    }
    else printf("check try_get for returning out value\n");
}

void should_return_out_value_for_try_get_at_left(){
    BinaryTree* tree = createTree();
    int val = 10;
    insert(tree, 10);
    insert(tree, -1);
    //printf("left: %d\n", tree->root->left->data);
    printf("result: %d\n", try_get(tree, -1));
    if(try_get(tree, -1) == -1){
        printf("success part 9\n");
    }
    else printf("check try_get for returning out value\n");
}

// void should_return_out_value_for_try_get_at_right(){

// }

int main(){

    should_return_tree_with_null_root_value();
    should_return_neg_one_for_insterting_in_null_tree();
    insert_root_and_return_zero();
    should_insert_node_to_left();
    should_insert_node_to_right();
    //should_return_neg_one_for_tree_doesnt_exist();
    //should_get_neg_one_for_root_is_null();
    should_return_out_value_for_try_get_at_root();
    should_return_out_value_for_try_get_at_left();

    return EXIT_SUCCESS;
}