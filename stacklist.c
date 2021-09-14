#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynarrayfun.h"

struct slist
{
  /* fill your struct */
};

struct slist* create_slist()
{
  return NULL;
}

void destroy_slist(struct slist* lst)
{

}
void insert_slist(struct slist* lst, int position, int value)
{

}

void append_slist(struct slist* lst, int value)
{
}

int item_at_slist(struct slist* lst, int position)
{
  return 0;
}

int length_slist(struct slist* lst)
{
  return 0;
}

void print_slist(struct slist* lst)
{

}

int main(void)
{
  struct slist* lst = create_slist();
  append_slist(lst, 1);
  append_slist(lst, 2);
  append_slist(lst, 3);
  append_slist(lst, 4);
  append_slist(lst, 5);
  insert_slist(lst, 0, 0);
  insert_slist(lst, 2, 100);
  print_slist(lst);
  destroy_slist(lst);
  return 0;
}
