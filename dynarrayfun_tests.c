#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dynarrayfun.h"

int main(void)
{
  /* for stack */
  struct da_stack* stk = da_stack_create();
  da_stack_push(stk, 1);
  da_stack_push(stk, 2);
  da_stack_push(stk, 3);
  assert(da_stack_peek(stk) == 3);
  assert(da_stack_pop(stk) == 3);
  assert(da_stack_pop(stk) == 2);
  assert(da_stack_length(stk) == 1);
  assert(da_stack_pop(stk) == 1);
  assert(da_stack_length(stk) == 0);
  da_stack_destroy(stk);
  printf("Stack code should be fine, but you need write more tests\n");

  /* for queue */

  struct da_queue* queue = da_queue_create();
  da_queue_enqueue(queue, 1);
  da_queue_enqueue(queue, 2);
  da_queue_enqueue(queue, 3);
  assert(da_queue_peek(queue) == 1);
  assert(da_queue_dequeue(queue) == 1);
  assert(da_queue_dequeue(queue) == 2);
  assert(da_queue_length(queue) == 1);
  assert(da_queue_dequeue(queue) == 3);
  assert(da_queue_length(queue) == 0);
  da_queue_destroy(queue);
  printf("Queue code should be fine, but you need write more tests\n");

  return 0;
}
