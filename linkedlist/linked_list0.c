#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

//insert data into the linked list
void insert(struct Node* head, int data) {
    
    while (head->next != NULL){
        head = head->next;
    }

    //add another node as the tail
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    head->next = newNode;

}

void print_ben(struct Node* head) {
  if (head != NULL)
    printf("%d", head->data);
  
  head = head->next;

  while (head->next != NULL) {
    printf("->%d", head->data);
    head = head->next;
  }

  printf("->%d\n", head->data);
}

void print(struct Node* head){
    while (head != NULL){
        printf("%d", head->data);
        if (head->next != NULL){
            printf("->");
        }
        head = head->next;
    }  
}

void delete_tail (struct Node* head){
    if (head != NULL && head -> next != NULL){ 
        while (head ->next ->next != NULL){ 
            head = head->next;
        }

        free(head->next->next); //how do you test this?? -> in your dreams
        head->next = NULL;

    }

}

int main(int argc, char** argv){
    
    //make a node 
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = 0;
    newNode->next = NULL;

    insert(newNode, 1);
    print_ben(newNode);

    delete_tail(newNode);

    free(newNode);//gives "dangling" pointer if used without deteting tail or the other nodes in the list
    
    return 0;

    //we're done with the code right?? :)
    //Thank you professor Dr. Standfield

}