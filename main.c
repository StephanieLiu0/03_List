#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main() {
  struct node * startNode = NULL;

  printf("Print empty list: \n");
  print_list(startNode);

  // populate linked list
  for (int i = 0; i < 10; i++) {
   startNode = insert_front(startNode, i);
  }

  printf("Print linked list: \n");
  print_list(startNode);

  // remove nodes
  printf("Remove 9\n");
  startNode = remove_node(startNode, 9);
  print_list(startNode);

  printf("Remove 4\n");
  startNode = remove_node(startNode, 4);
  print_list(startNode);

  printf("Remove 0\n");
  startNode = remove_node(startNode, 0);
  print_list(startNode);

  printf("Remove -2\n");
  startNode = remove_node(startNode, -2);
  print_list(startNode);

  // free list
  printf("Free list:\n");
  startNode = free_list(startNode);
  printf("Print list: ");
  print_list(startNode);

  return 0;
}
