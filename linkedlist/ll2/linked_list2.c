#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

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

/**
 * @brief Initializes a new linked list.
 * 
 * @return A pointer to the initialized LinkedList.
 */
LinkedList* create_list(){ //LinkedList* means return pointer of type LinkedList
  struct LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
  //struct LinkedList l;
  // // Do I need to create a Node??
  // struct Node* n = malloc(sizeof(Node)); 
  // /**
  //  * @test why does struct Node n = malloc(sizeof(Node)); not work??
  //  * */
  // n->data = NULL;
  // n->next = NULL;
  // l->head = n;
  l->head = NULL;
  l->tail = NULL;
  l->size = 0; //should I initialize it to NULL or 0?
  return l;
}

/**
 * @brief Inserts a new node at the head of the list.
 * 
 * @param list Pointer to the linked list.
 * @param value The data to insert.
 */
int insert_head(LinkedList* list, int value){
  if (list == NULL){
    return -1;
  }
  
  struct Node* n = malloc(sizeof(struct Node));
  n->data = value;
  n->next = list->head;

  if(list != NULL){
    list->head = n;
    list->size++;
  }
  if(list->tail == NULL){ //in case size is 0
    list->tail = n;
  }
  return 0;
}

/**
 * @brief Inserts a new node at the tail of the list.
 * 
 * @param list Pointer to the linked list.
 * @param value The data to insert.
 */
int insert_tail(LinkedList* list, int value){
  struct Node* n = (Node*)malloc(sizeof(struct Node));
  n->data = value;
  n->next = NULL;

  if (list == NULL) //this should not be a case right?
    return -1;

  if(list->tail != NULL){
    list->tail->next = n;
    list->tail = n;
  }
  else{
    list->head = n;
    list->tail = n;
  }
  list->size++;

  return 0;
}

/**
 * @brief Deletes the node at a specific index.
 * 
 * @param list Pointer to the linked list.
 * @param index The index of the node to delete (0-based index).
 * @return 0 if the deletion is successful, -1 if the index is invalid.
 */
int delete_at_index(LinkedList* list, int index){
  
  if(list == NULL) return -1;

  if(list->head == NULL) //if list doesn't exist, return -1; I could potentially add other cases in which the function won't be valid..
    return -1;

  if(index == 0){
      struct Node* node1 = list->head;  //node1 points to list head
      list->head = list->head->next;
      if(list->size == 1)
        list->tail = node1->next; //shouldn't this be list->tail = NULL; (well, technically, it should be the same thing..)
      free(node1);
      list->size--;
      return 0;
    }

  if(index > 0 && index<=list->size -1){
    struct Node* node1 = list->head;  //node1 points to list head
    struct Node* temp = list->head; //temp points to list head

    for (int i = 0; i < index-1; i++){ //stops at 1 before the node that needs to be deleted
      node1 = node1->next;
    }
    temp = node1->next;
    
    if(index == list->size-1)
      list->tail = node1;
    
    node1->next = node1->next->next;
    free(temp);
    list->size--;
    return 0;
  }
  else return -1;
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
  if (list == NULL) {
        return -1; // Return -1 if the list is NULL, empty, or index is out of bounds.
   }
  if(list->head == NULL) {
    return -1;
  }
  else if(index < 0 || index >= list->size){
    return -1;
  }
  else{
    Node* node1 = list->head;

    if(index == 0){
      *out_value = node1->data;
    }
    else{
      for(int i = 0; i< index; i++){
        node1 = node1->next;
      }
      *out_value = node1->data;
    }
    return 0;
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
  if(list == NULL) return -1;

  if(list->head == NULL)
    return -1;

  if(index == 0){ //if the list has only 1 node, would this update the value for the tail?
      list->head->data = new_value;
      return 0;
  }

  if(index == list->size-1){
      list->tail->data = new_value;
      return 0;
  }

  else if (index>0 && index<list->size-1){
    struct Node* temp = list->head;
    
    for (int i = 0; i < index; i++){ //stops at 1 before the node that needs to be deleted
      temp = temp->next;
    }

    temp->data = new_value;

    //free(temp);
    return 0;
  }
  else return -1;
}

/**
 * @brief Frees the memory allocated for the linked list.
 * 
 * @param list Pointer to the linked list.
 */
void free_list(LinkedList* list){
  if (list == NULL) return;

  if (list != NULL && list -> size == 0){
    free(list);
  }
  else{
    

    if(list->size == 1){
      // printf("freeing 1\n");
      free(list->head);
      //free(list->tail);
      list->size = 0;
      free(list);
      return;
    }
    if(list->size == 2){
      //  printf("freeing 2\n");
      free(list->head);
      free(list->tail);
      list->size = 0;
      free(list);
      return;
    }

    if (list->size >2){
      //  printf("freeing more than 2\n");
      Node* node1 = list->head;
      while(list->size != 2){
        node1 = node1->next;
        free(node1);
        list->size--;
      }
    }
    free(list->head);
    free(list->tail);
    list->size = 0;
    free(list);
  }
}

// int main(int argc, char *argv[])
// {
//   LinkedList* list = create_list();
//   printf("1\n");
//   insert_head(list, 0);
//   printf("2\n");
//   insert_tail(list, 1);
//   insert_tail(list, 2);
//   insert_tail(list, 5);
//   insert_tail(list, 4);

//   int value = -1;
//   printf("3\n");
//   assert(get_at_index(list, 0, &value) == 0);
//   printf("4\n");
//   assert(value == 0);

//   assert(update_at_index(list, 3, 4) == 0);
//   printf("5\n");
//   assert(get_at_index(list, 3, &value) == 0);
//   assert(value == 4);

//   printf("6\n");
//   assert(delete_at_index(list, 4) == 0);
//   printf("7\n");
//   assert(get_at_index(list, 4, &value) == -1);
//   printf("8\n");
//   free_list(list);
//   printf("9\n");

//   return EXIT_SUCCESS;
// }