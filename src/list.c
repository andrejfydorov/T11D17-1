#include "list.h"
#include "door_struct.h"
#include <stdlib.h>

struct node *init(struct door *door, int n) {

  struct node *head = NULL;
  struct node *temp = NULL;
  struct node *p = NULL;

  for (int i = 0; i < n; i++) {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->value = &door[i];

    if (head == NULL)
      head = temp;
    else {
      p = head;
      while (p->next != NULL) {
        p = p->next;
      }
      p->next = temp;
    }
  }

  return head;
}

struct node *add_door(struct node *elem, struct door *door) {

  struct node *n = (struct node *)malloc(sizeof(struct node));
  struct node *p = elem->next;
  elem->next = n;

  n->value = door;
  n->next = p;

  return n;
}

struct node *find_door(int door_id, struct node *root) {
  struct node *p = root;
  while (p->value->id != door_id) {
    p = p->next;
  }

  return p;
}

struct node *remove_door(struct node *elem, struct node *root) {
  if (elem == root) {
    struct node *p = elem;
    // printf("%d\n", p->value->id);
    root = root->next;
    free(p);
    return root;
  } else {
    struct node *p = root;
    while (p->next != elem) {
      p = p->next;
    }

    p->next = elem->next;

    free(elem);
    return p;
  }
}

void destroy(struct node *root, int n) {

  struct node **nodeArr = (struct node **)malloc(sizeof(struct node *) * n);

  for (int i = 0; root != NULL; i++, root = root->next) {
    nodeArr[i] = root;
  }

  for (int i = 0; i < n; i++) {
    free(nodeArr[i]);
  }

  free(nodeArr);
}

void print_nodes(struct node *root) {
  struct node *p = root;
  while (p->next != NULL) {
    printf("id = %d status = %d\n", p->value->id, p->value->status);
    p = p->next;
  }
  printf("id = %d status = %d\n", p->value->id, p->value->status);
}

struct node *shift_node(struct node *root, int shift_size) {
  struct node *p = root;
  for (int i = 0; i < shift_size; i++) {
    p = p->next;
  }
  return p;
}

int counter_nodes(struct node *root) {
  int counter = 0;
  struct node *p = root;
  while (p->next != NULL) {
    counter++;
    p = p->next;
  }
  counter++;
  return counter;
}