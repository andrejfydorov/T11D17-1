#include "list.h"
#include <stdio.h>

void add_door_test(struct node *nodes) {
  struct door d = {.id = 15, .status = 1};
  printf("Input: %d  %d\n", d.id, d.status);

  struct node *added = add_door(shift_node(nodes, 14), &d);
  printf("Output: %d  %d\n", added->value->id, added->value->status);

  struct node *res = shift_node(nodes, 15);
  if (res->value->id == 15 && res->value->status == 1)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  remove_door(res, nodes);
  //---------------------------------
  d.id = 16;
  d.status = 0;
  printf("Input: %d  %d\n", d.id, d.status);

  added = add_door(shift_node(nodes, 10), &d);
  printf("Output: %d  %d\n", added->value->id, added->value->status);

  res = shift_node(nodes, 11);
  if (res->value->id == 16 && res->value->status == 0)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  remove_door(res, nodes);
  //------------------------------------
  d.id = 17;
  d.status = 1;
  printf("Input: %d  %d\n", d.id, d.status);

  added = add_door(nodes, &d);
  printf("Output: %d  %d\n", added->value->id, added->value->status);

  res = shift_node(nodes, 1);
  if (res->value->id == 17 && res->value->status == 1)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  remove_door(res, nodes);
}

void remove_door_test(struct node *nodes) {

  struct door *temp = find_door(14, nodes)->value;
  printf("Input: %d  %d\n", temp->id, temp->status);
  int c1 = counter_nodes(nodes);

  remove_door(shift_node(nodes, 14), nodes);
  // print_nodes(nodes);
  // printf("\n");

  int c2 = counter_nodes(nodes);

  if (c1 > c2)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  add_door(shift_node(nodes, 13), temp);

  // print_nodes(nodes);
  // printf("\n");
  //---------------------------------
  temp = find_door(10, nodes)->value;
  printf("Input: %d  %d\n", temp->id, temp->status);

  c1 = counter_nodes(nodes);

  remove_door(shift_node(nodes, 10), nodes);

  c2 = counter_nodes(nodes);

  if (c1 > c2)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  add_door(shift_node(nodes, 9), temp);
  //---------------------------------------
  temp = find_door(0, nodes)->value;
  printf("Input: %d  %d\n", temp->id, temp->status);

  c1 = counter_nodes(nodes);

  print_nodes(nodes);
  printf("\n");

  remove_door(nodes, nodes);

  print_nodes(nodes);
  printf("\n");

  c2 = counter_nodes(nodes);

  if (c1 > c2)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  add_door(nodes, temp);
  print_nodes(nodes);
  printf("\n");
}