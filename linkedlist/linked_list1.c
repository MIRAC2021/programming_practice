#include <assert.h>
#include <stdlib.h>

/**
 * @brief Node structure representing each element in the linked list.
 */
typedef struct Node {
    int data;              /**< Data stored in the node */
    struct Node* next;     /**< Pointer to the next node */
} Node;

/**
 * @brief Linked list structure containing the head and tail pointers.
 */
typedef struct LinkedList {
    Node* head;            /**< Pointer to the first node (head) */
    Node* tail;            /**< Pointer to the last node (tail) */
    int size;              /**< Number of elements in the list */
} LinkedList;

// /**
//  * @brief Initializes a new linked list.
//  * 
//  * @return A pointer to the initialized LinkedList.
//  */
// LinkedList* create_list(){
//   struct Node *newNode = malloc(sizeof(struct Node));;
//   struct LinkedList *newList = malloc(sizeof(struct LinkedList));
//   int count = 0;
  
//   newList->head = newNode; //what exactly does this do?
//   newList->head = newNode->data;

//   if (newList->head != NULL && newList->head!= NULL){ 
//         while (newList->head->next!= NULL){ 
//             newList->tail = newList->head->next;
//             count ++;
//         }
//   }

//   newList->size = count + 1;

// }

/**
 * @brief Initializes a new linked list.
 * 
 * @return A pointer to the initialized LinkedList.
 */
LinkedList* create_list() {
    // This is our new list.
    struct LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    // No values to assign yet
    list->head = NULL;
    list->tail = NULL;

    // List size is initially 0
    list->size = 0;

    return list;
}

/**
 * @brief Inserts a new node at the head of the list.
 * 
 * @param list Pointer to the linked list.
 * @param value The data to insert.
 */
void insert_head(LinkedList* list, int value){
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
  
}

/**
 * @brief Inserts a new node at the tail of the list.
 * 
 * @param list Pointer to the linked list.
 * @param value The data to insert.
 */
void insert_tail(LinkedList* list, int value){
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = value;

  if(list->tail == NULL){
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
    list->size++;
  }
  else{
    list->tail->next = newNode;
    list->tail = newNode;
    newNode->next = NULL;
    list->size++;
    
    // for(int i = 0; i = list->size; i++){
    //   while(list->head)
    //   list->head = list->head->next;
    // }
  }

}

/**
 * @brief Deletes the node at a specific index.
 * 
 * @param list Pointer to the linked list.
 * @param index The index of the node to delete (0-based index).
 * @return 0 if the deletion is successful, -1 if the index is invalid.
 */
int delete_at_index(LinkedList* list, int index){
  struct Node *newNode = list->head;

  if (list->head != NULL && index >0 && index < list->size){
    struct Node *nodeTwo = list->head;
    for(int i = 0; i < index-1; i++){
      newNode = newNode->next;
      nodeTwo = nodeTwo->next;
    }
    if (index == list->size -1){ //in case of Tail
      newNode->next = NULL;
    }
    nodeTwo = nodeTwo->next;
    newNode->next = newNode->next->next;
    free(nodeTwo);
    list->size--;

    return 0;
  } 
  else if(index == 0){ //in case of Head
    Node* n;
    if (list->head != NULL){
      n->next = list->head->next;
      free(list->head);
      list->head = n;
      list->size--;
      return 0;
    }
  }
  else{
    return -1;
  }
}

/**
 * @brief Retrieves the data from the node at a specific index.
 * 
 * @param list Pointer to the linked list.
 * @param index The index of the node to retrieve (0-based index).
 * @param out_value Pointer to an integer to store the retrieved value.
 * @return 0 if retrieval is successful, -1 if the index is invalid.
 */
int get_at_index(LinkedList* list, int index, int* out_value){

  if (list->head != NULL && index >=0 && index < list->size){
    struct Node *newNode = list->head;
    for(int i = 0; i < index; i++){
      newNode = newNode->next;
    }
    *out_value = newNode->data;  //pointer doing pointy things
    return 0;
  }
  else{
    return -1;
  }
}

/**
 * @brief Updates the data of the node at a specific index.
 * 
 * @param list Pointer to the linked list.
 * @param index The index of the node to update (0-based index).
 * @param new_value The new value to set in the node.
 * @return 0 if the update is successful, -1 if the index is invalid.
 */
int update_at_index(LinkedList* list, int index, int new_value){
  struct Node *newNode = list->head;

  if (list->head != NULL && index >0 && index < list->size){
    struct Node *nodeTwo = list->head;
    for(int i = 0; i < index-1; i++){
      newNode = newNode->next;
      nodeTwo = nodeTwo->next;
    }
    if (index == list->size -1){ //in case of Tail
      newNode->next = NULL;
    }
    nodeTwo = nodeTwo->next;
    newNode->next = newNode->next->next;
    free(nodeTwo);
    list->size--;

    return 0;
  } 
  else if(index == 0){ //in case of Head
    Node* n;
    if (list->head != NULL){
      n->next = list->head->next;
      free(list->head);
      list->head = n;
      list->size--;
      return 0;
    }
  }
  else{
    return -1;
  }
}

/**
 * @brief Frees the memory allocated for the linked list.
 * 
 * @param list Pointer to the linked list.
 */
void free_list(LinkedList* list){
  //find a way to do it without making second pointer
  //apparently this is a "dirty" way of doing it 
  Node* newNode;
  if (list->head != NULL){
    while (list->size != 0){
      newNode = list->head->next;
      free(list->head);
      list->size--;
      list->head = newNode;
    }
  }
  free(list);
}

//THE CLEAN CODE:
// /**
//  * @brief Frees the memory allocated for the linked list.
//  * 
//  * @param list Pointer to the linked list.
//  */
// void free_list(LinkedList* list) {
//     struct Node* parent = list->head;
//     struct Node* child;

//     while (parent != NULL) {
//         child = parent->next;
//         free(parent);
//         parent = child;
//     }
//     free(list);
// }

// i guess this frees both head Node (including the data and the next pointer)?

int main(int argc, char *argv[])
{
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);
  insert_tail(list, 5);
  insert_tail(list, 4);

  int value = -1;
  assert(get_at_index(list, 0, &value) == 0);
  assert(value == 0);

  assert(update_at_index(list, 3, 4) == 0);
  assert(get_at_index(list, 3, &value) == 0);
  assert(value == 4);


  assert(delete_at_index(list, 4) == 0);
  assert(get_at_index(list, 4, &value) == -1);

  free_list(list);

  return EXIT_SUCCESS;
}
