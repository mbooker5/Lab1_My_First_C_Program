// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
}

void list_free(list_t *l) {
  node_t* curr = l->head;
  while(curr != NULL){
    free(curr);
  }
}

void list_print(list_t *l) {
  node_t* curr = l->head;
  while(curr != NULL){
    printf("%d\n", curr->value);
    curr = curr->next;
  }
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int count = 0;
  node_t* head = l->head;

  while(head != NULL){
    count = count + 1;
    head = head->next;
  }
  
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  /* Insert to back*/
  node_t* last_node = l->head;

  while(last_node != NULL){
    last_node = last_node->next;
  }
  last_node = cur_node;
}

void list_add_to_front(list_t *l, elem value) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  /* Insert to front */

  node_t* head = l->head;  // get head of list


  cur_node->next = head;
  head = cur_node;


}
void list_add_at_index(list_t *l, elem value, int index) {
  int curr_index = 1;
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  node_t* head = l->head;
  node_t* next;
  while (head != NULL){
    if (curr_index == index){
      next = head;
      head->value = value;
      head->next = next;
    }
    curr_index = curr_index + 1
    head = head->next;
  }

}

elem list_remove_from_back(list_t *l) { return -1; }
elem list_remove_from_front(list_t *l) { return -1; }
elem list_remove_at_index(list_t *l, int index) { return -1; }

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }

