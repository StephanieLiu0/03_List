#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

void print_list(struct node * n) {
  printf("[");
  while (n != NULL) {
    printf( "%d ", n->i);
    n = n->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * n, int newInt) {
  struct node * newNode = malloc (sizeof( struct node));
  newNode->i = newInt;
  newNode->next = n;

  return newNode;
}

struct node * free_list(struct node * n) {
  while (n != NULL) {
    printf( "freeing node: %d\n", n->i);
    struct node * current = n;
    free(current);
    current = NULL;
    n = n->next;
  }
  return n;
}

struct node * remove_node(struct node * front, int data) {
  struct node * current = front->next;
  struct node * previous = front;

  if (front->i == data) {
    free(front);
    front = NULL;
    return current;
  }

  for (; current != NULL; previous = current, current = current->next ) {
    if (current->i == data) {
      struct node * freeNode = current;

      previous->next = freeNode->next;

      free(freeNode);
      freeNode = NULL;
    }
  }

  return front;
}
