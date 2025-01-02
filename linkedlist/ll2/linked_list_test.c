#include "linked_list2.c"

// what if I make some common lists that I will be using for different tests?
void insert_head_should_return_neg_one(){
  LinkedList* list = NULL; //create_list();
  if (insert_head(list, 0) == -1){
    printf("success part 1\n");
  }
  else{
    printf("suck it\n");
  }

  free_list(list);
}

void head_and_tail_point_to_node(){
  LinkedList* list = create_list();
  insert_head(list, 1);

  if(list->head->data == list->tail->data == 1){
    printf("success part 2\n");
  }
  else printf("Benjamin sucks but it's kinda bad\n");

  free_list(list);

}

void new_node_is_head(){
  LinkedList* list = create_list();
  insert_head(list, 2);
  insert_head(list, 3);

  if(list->head->data == 3 && list->tail->data == 2){
    printf("success part 3\n");
  }
  else printf("part3 failed like Benjamin\n");

  free_list(list);
}

void insert_tail_should_return_neg_one(){
  LinkedList* list = NULL; //create_list();
  if (insert_tail(list, 0) == -1){
    printf("success part 4\n");
  }
  else{
    printf("why it no work\n");
  }

  free_list(list);
}
 
void tail_and_head_point_to_new_node(){
  LinkedList* list = create_list();
  
  insert_tail(list, 1);

  if(list->head->data == 1 && list->tail->data == 1 && list->size == 1){
    printf("success part 5\n");
  }
  else{
    printf("nooooooooooooooooo\n");
  }

  free_list(list);
}

void tail_points_to_newnode_prev_next_points_to_tail_increment_size(){
  LinkedList* list = create_list();
  insert_head(list, 1);
  insert_tail(list, 2);

  if(list->tail->data == 2 && list->head->next->data == 2 && list->size == 2){
    printf("success part 6\n");
  }
  else printf("lord have mercy\n");

  free_list(list);
}

//tests for delete node at index

void should_return_neg_one(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  if (delete_at_index(list, -2) == -1){
    printf("success part 7\n");
  }
  else printf("delete at index failed to recognize correct index");

  // should this be a separate test?
  if (delete_at_index(list, 3) == -1){
    printf("success part 8\n");
  }
  else printf("i equal to or greater than size should return -1");

  free_list(list);
}

void empty_list_returns_neg_one(){
  LinkedList* list = NULL;

  if(delete_at_index(list, 0) == -1){
    printf("success part 9\n");
  }
  else printf("add case from NULL linked list\n");

  //no need to free linked list, right?
  free_list(list);

}

// delete head
void reassign_head_and_decrease_index(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  delete_at_index(list, 0);

  if(list->head->data == 1 && list->size == 2){
    printf("success part 10\n");
  }
  else printf("check if head is reassigned and size is decrementing\n");

  free_list(list);
}

// delete tail
void reassign_tail_and_decrease_size(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  delete_at_index(list, 2);

  if(list->tail->data == 1 && list->size == 2){
    printf("success part 11\n");
  }
  else printf("check if tail is reassigned and size is decrementing\n");
  free_list(list);
}

// delete the only node
void head_tail_are_null_size_is_zero(){
  LinkedList* list = create_list();

  insert_head(list, 0);

  delete_at_index(list, 0);

  if(list->head == NULL && list->tail == NULL && list->size == 0){
    printf("success part 12\n");
  }
  else printf("check the single node scenario\n");
  free_list(list);
}

// delete middle node
void point_prev_to_next_node_and_decrease_size(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  delete_at_index(list, 1);

  if(list->head->next->data == 2 && list->size == 2){
    printf("success part 13\n");
  }
  else printf("check if middle is deleted properly and size is decrementing\n");
  free_list(list);
}

// TESTING Get at Index

void should_return_neg_one_for_get_at_index(){
  LinkedList* list = NULL;

  int* out_value = NULL;

  if(get_at_index(list, 0, out_value) == -1){
    printf("success part 14\n");
  }
  else printf("check if null list returns -1");
  free_list(list);
}

void should_return_neg_one_for_no_node_in_list(){
  LinkedList* list = create_list();

  int* out_value = NULL;

  if(get_at_index(list, 0, out_value) == -1){
    printf("success part 15\n");
  }
  else printf("check if list with n=0 returns -1");
  free_list(list);
}

void should_return_neg_one_for_invalid_index(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  int* out_value = NULL;

  if(get_at_index(list, -1, out_value) == -1 && get_at_index(list, 3, out_value) == -1){
    printf("success part 16\n");
  }
  else printf("issue with indexing\n");
  free_list(list);

  // printf("just checking\n");

}

void check_values_at_head_tail_middle(){
  LinkedList* list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  int out_value = -1;

  // printf("does it fail here?\n");

  get_at_index(list, 0, &out_value);

  // printf("or is it failing here?\n");

  //printf("out value is %d", out_value);
  int out_value1, out_value2, out_value3 = -1;

  get_at_index(list, 0, &out_value1);
  //printf("out1 is %d", *out_value1);
  get_at_index(list, 1, &out_value2);
  //printf("out2 is %d", *out_value2);
  get_at_index(list, 2, &out_value3);
  //printf("out3 is %d", *out_value3);

  if(out_value1 == 0 && out_value2 == 1 && out_value3 == 2){
    printf("success part 17\n");
  }
  else printf("issue with fetching data when correct list is fed. Check indiidual cases\n");
  free_list(list);
}

// Testing UPDATE AT INDEX
void should_return_neg_one_for_null_list(){
  LinkedList* list = NULL;

  if(update_at_index(list, 0, 12) == -1){
    printf("success part 18\n");
  }
  else printf("check if list is NULL case is covered or not\n");
  free_list(list);
}

void return_neg_one_for_no_node_in_list(){
  LinkedList* list = create_list();

  if(update_at_index(list, 0, 12)== -1){
    printf("success part 19\n");
  }
  else printf("check if no node case is considered\n");
  free_list(list);
}

void return_neg_one_for_unbound_index(){
  LinkedList *list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  if(update_at_index(list, -1, 12) == -1 && update_at_index(list, 3, 13) == -1){
    printf("success part 20\n");
  }
  else printf("check index bounds\n");
  free_list(list);
}

void updates_head(){
  LinkedList *list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  update_at_index(list, 0, 12);

  //printf("%d\n", list->head->data);

  if(list->head->data == 12 && list->head->next->data == 1 && list->size == 3){
    printf("success part 21\n");
  }
  else printf("check update head\n");
  free_list(list);

}

void updates_middle(){
  LinkedList *list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  update_at_index(list, 1, 12);


  if(list->head->next->data == 12 && list->size == 3){
    printf("success part 22\n");
  }
  else printf("check update middle\n");
  free_list(list);

}

void updates_tail(){
  LinkedList *list = create_list();

  insert_head(list, 0);
  insert_tail(list, 1);
  insert_tail(list, 2);

  update_at_index(list, 2, 12);

  if(list->tail->data == 12 && list->size == 3){
    printf("success part 23\n");
  }
  else printf("check update tail\n");
  free_list(list);
}

//Testing FREE LIST




int main(int argc, char *argv[])
{
  insert_head_should_return_neg_one();
  head_and_tail_point_to_node();
  new_node_is_head();
  insert_tail_should_return_neg_one();
  tail_and_head_point_to_new_node();
  tail_points_to_newnode_prev_next_points_to_tail_increment_size();
  should_return_neg_one();
  empty_list_returns_neg_one();
  reassign_head_and_decrease_index();
  reassign_tail_and_decrease_size();
  head_tail_are_null_size_is_zero();
  point_prev_to_next_node_and_decrease_size();
  should_return_neg_one_for_get_at_index();
  should_return_neg_one_for_no_node_in_list();
  should_return_neg_one_for_invalid_index();
  check_values_at_head_tail_middle();
  should_return_neg_one_for_null_list();
  return_neg_one_for_no_node_in_list();
  return_neg_one_for_unbound_index();
  updates_head();
  updates_middle();
  updates_tail();

  return EXIT_SUCCESS;
}