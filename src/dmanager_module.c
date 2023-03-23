#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"
#include "list.c"
#include "list_test.c"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void print_doors(struct door *doors);
void quick_sort(struct door *doors, int first, int last);
void swap(struct door *a, struct door *b);

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);

  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
  }

  quick_sort(doors, 0, DOORS_COUNT - 1);
  print_doors(doors);
  printf("\n");

  struct node *nodes = init(doors, DOORS_COUNT);
  // print_nodes(nodes);
  // printf("\n");

  add_door_test(nodes);
  printf("\n");
  remove_door_test(nodes);

  free(nodes);

  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
  srand(time(0));

  int seed = rand() % MAX_ID_SEED;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % DOORS_COUNT;
    doors[i].status = rand() % 2;
  }
}

void print_doors(struct door *doors) {
  for (int i = 0; i < DOORS_COUNT; i++) {
    if (i != DOORS_COUNT - 1)
      printf("%d, %d\n", doors[i].id, doors[i].status);
    else
      printf("%d, %d", doors[i].id, doors[i].status);
  }
}

void quick_sort(struct door *doors, int first, int last) {
  int i = first, j = last;
  struct door x = doors[(first + last) / 2];

  do {
    while (doors[i].id < x.id)
      i++;
    while (doors[j].id > x.id)
      j--;

    if (i <= j) {
      if (doors[i].id > doors[j].id)
        swap(&doors[i], &doors[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (i < last)
    quick_sort(doors, i, last);
  if (first < j)
    quick_sort(doors, first, j);
}

void swap(struct door *a, struct door *b) {
  struct door temp = *a;
  *a = *b;
  *b = temp;
}