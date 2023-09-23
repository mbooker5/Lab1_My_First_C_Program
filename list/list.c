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
  // node_t* curr = l->head;
  // while(curr->next != NULL){
  //  free(curr);
  //  curr = curr->next;
  // }
  // printf("Freed");
  // l = NULL;
  // list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  // mylist->head = NULL;
  // l = mylist;
  free(l);
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  l = mylist;
}

void list_print(list_t *l) {
  node_t* curr = l->head;

  while(curr != NULL){
    if (curr != NULL){
      printf("%d\n", curr->value);
      curr = curr->next;
    }
    else{
      printf("%p\n", NULL);
      break;
    }
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
  node_t* head = l->head;
  node_t* last_node = l->head;

  while(last_node != NULL){
    if (last_node->next != NULL){
      last_node = last_node->next;
    }
    else{
      last_node->next = cur_node;
      l->head = head;
      break;
    }
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  /* Insert to front */

  node_t* head = l->head;  // get head of list

  cur_node->next = head;
  head = cur_node;
  l->head = head;
}

void list_add_at_index(list_t *l, elem value, int index) {
  int curr_index = 0;
  node_t* cur_node = (node_t *) malloc(sizeof(node_t));
  cur_node->value = value;
  cur_node->next = NULL;

  node_t* head = l->head;
  printf("%d\n", head->value);
  node_t* index_node = l->head;
  if (index == 0){
    cur_node->next = head;
    head = cur_node;
    l->head = head;
  } else {
      while (index_node != NULL){
      if (curr_index + 1 == index){
        cur_node->next = index_node;
        index_node->value = cur_node->value;
        l->head = head;
        break;
      }
      curr_index = curr_index + 1;
      index_node = index_node->next;
    }
  }
  
}

elem list_remove_from_back(list_t *l) {
  int removed_elem = -1;
  node_t* head = l->head;
  while (head->next != NULL){
    head = head->next;
  }
  removed_elem = head->value;
  head = NULL;
  return removed_elem;
}

elem list_remove_from_front(list_t *l) {
  int removed_elem = -1;
  node_t* head = l->head;
  removed_elem = head->value;
  head = head->next;

  return removed_elem;
}

elem list_remove_at_index(list_t *l, int index) { 
  int curr_index = 0;
  int removed_elem = -1;
  node_t* head = l->head;
  node_t* next;
  while (head != NULL){
    if (curr_index == index){
      removed_elem = head->value;
      if (head->next != NULL){
        head->value = head->next->value;
        head->next = head->next->next;
      }
      else{
        head = NULL;
      }
      break;
    }
    curr_index = curr_index + 1;
    head = head->next;
  }
}

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }

