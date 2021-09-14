#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* do not change code for dynarry */
struct da_stack;
struct da_queue;

/* stack functions */

struct da_stack* da_stack_create(void);
void da_stack_destroy(struct da_stack* stk);
void da_stack_push(struct da_stack* stack, int value);
int da_stack_pop(struct da_stack* stack);
int da_stack_peek(struct da_stack* stack);
int da_stack_length(struct da_stack* stack);

/* for queue */

struct da_queue* da_queue_create(void);
void da_queue_destroy(struct da_queue* queue);
void da_queue_enqueue(struct da_queue* queue, int value);
int da_queue_dequeue(struct da_queue* queue);
int da_queue_peek(struct da_queue* queue);
int da_queue_length(struct da_queue* queue);
