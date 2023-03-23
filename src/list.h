#include "door_struct.h"

#ifndef LIST_H
#define LIST_H

struct node {
  struct door *value;
  struct node *next;
};

struct node *init(struct door *door, int n);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root, int n);
void print_nodes(struct node *root);
struct node *shift_node(struct node *root, int shift_size);
int counter_nodes(struct node *root);

#endif