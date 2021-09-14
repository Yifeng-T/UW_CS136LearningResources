#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* do not change code for dynarry */
struct dynarray
{
  int capacity;
  int size;
  int* content;
};

struct dynarray* da_create(void)
{
    struct dynarray* da = (struct dynarray*) malloc(sizeof(struct dynarray));
    da->size = 0;
    da->capacity = 10;
    da->content = (int*) malloc(sizeof(int) * da->capacity);
    return da;
}

void da_destroy(struct dynarray* da)
{
  free(da->content);
  free(da);
}

int da_length(struct dynarray* da)
{
  return da->size;
}

void da_insert(struct dynarray* da, int position, int value)
{
    if(da->size == da->capacity) {
      da->capacity *= 2;
      da->content = (int*) realloc(da->content, sizeof(int) * da->capacity);
    }
    for(int i = da->size; i >= position; i--) {
      da->content[i + 1] = da->content[i];
    }
    da->size++;
    da->content[position] = value;
}

int da_remove(struct dynarray* da, int position)
{
  int rv = da->content[position];
  for(int i = position; i < da->size; i++) {
    da->content[i] = da->content[i+1];
  }
  da->size--;
  return rv;
}

void da_print_content(struct dynarray* da) {
  printf("[");
  for(int i = 0; i < da->size; i++) {
    printf("%d", da->content[i]);
    if(i != da->size - 1) {
      printf(",");
    }
  }
  printf("]\n");
}

/* your work starts from here */


struct da_stack
{
  struct dynarray* da;
};

struct da_queue
{
  struct dynarray* da;
};

/* implement the following functions */

/* for stack */

struct da_stack* da_stack_create(void)
{
  return NULL;
}

void da_stack_destroy(struct da_stack* stk)
{

}

void da_stack_push(struct da_stack* stack, int value)
{
}

int da_stack_pop(struct da_stack* stack)
{
}

int da_stack_peek(struct da_stack* stack)
{
}

int da_stack_length(struct da_stack* stack){
  return 0;
}

/* for queue */

struct da_queue* da_queue_create(void)
{

}

void da_queue_destroy(struct da_queue* queue)
{

}

void da_queue_enqueue(struct da_queue* queue, int value)
{
}

int da_queue_dequeue(struct da_queue* queue)
{
}

int da_queue_peek(struct da_queue* queue)
{
}

int da_queue_length(struct da_queue* queue)
{
}
