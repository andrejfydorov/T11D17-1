#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
  int id;
  int status;
};

void initialize_doors(struct door *doors);
void print_doors(struct door *doors);
void quick_sort(struct door *doors, int first, int last);
void swap(struct door *a, struct door *b);

#endif