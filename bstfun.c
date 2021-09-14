#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* do not change these */

struct bstnode {
  int item;
  struct bstnode* left;
  struct bstnode* right;
};

struct bst {
  struct bstnode* root;
};

/* forward declaration */
int bst_size(struct bst* t);

struct bst* bst_create(void)
{
  struct bst* b = malloc(sizeof(struct bst));
  b->root = NULL;
  return b;
}

void free_bst(struct bstnode* bst) {
  if(bst == NULL) {
    return;
  }
  free_bst(bst->left);
  free_bst(bst->right);
  free(bst);
}

void bst_destroy(struct bst* t)
{
  free_bst(t->root);
  free(t);
}

bool bst_insert(struct bst* b, int key) {
  /* copy your code from assignment here */
}

struct bst* sorted_array_to_bst(int *a, int len)
{
  /* copy your code from assignment here */
}

int *bst_to_sorted_array(struct bst* t)
{
  /* copy your code from assignment here */
}

/*
 * helper function for print out the bst, just for your
 * convienece.
 */
void bst_print(struct bstnode* node, int indent) {
  if(node == NULL) {
    return;
  }
  bst_print(node->right, indent + 2);
  for(int i = 0; i < indent; i++) {
    printf(" ");
  }
  printf("%d\n", node->item);
  bst_print(node->left, indent + 2);
}

/* Implement the following functions */

int bst_size(struct bst* t) {
  return 0;
}

void bst_sort_array(int* nums, int len) {

}

int* bst_remove_dup(int* nums, int len, int* newlen) {
  return NULL;
}

int bst_sum_greater(struct bst* t, int threshold) {
  return 0;
}

void bst_stats(struct bst* t, int* height, int* nodes, int* leaves) {
  
}

int main(void) {
  struct bst* bt = bst_create();;
  assert(bst_size(bt) == 0);
  bst_insert(bt, 5);
  assert(bst_size(bt) == 1);
  bst_insert(bt, 8);
  bst_insert(bt, 7);
  bst_insert(bt, 9);
  assert(bst_size(bt) == 4);
  bst_insert(bt, 1);
  bst_insert(bt, 2);
  bst_insert(bt, 0);

  printf("This is da tree\n");
  bst_print(bt->root, 0);

  assert(bst_size(bt) == 7);
  printf("bst_size passed!\n");

  int arr[] = {3, 7, 1, 6, 4, 5, 2, 8};
  bst_sort_array(arr, 8);
  assert(arr[0] == 1);
  assert(arr[1] == 2);
  assert(arr[2] == 3);
  assert(arr[3] == 4);
  assert(arr[4] == 5);
  assert(arr[5] == 6);
  assert(arr[6] == 7);
  assert(arr[7] == 8);


  printf("bst_sort_array passed!\n");

  int arr2[] = {1, 1, 1, 1};
  int newlen = 0;
  int* newarr = bst_remove_dup(arr2, 4, &newlen);
  assert(newlen == 1);
  assert(newarr[0] == 1);
  free(newarr);

  int arr3[] = {1, 2, 1, 3, 2, 1, 3, 2, 1};
  newarr = bst_remove_dup(arr3, 9, &newlen);
  assert(newlen == 3);
  free(newarr);

  printf("bst_remove_dup passed!\n");

  assert(bst_sum_greater(bt, 0) == 32);
  assert(bst_sum_greater(bt, 1) == 31);
  assert(bst_sum_greater(bt, 2) == 29);
  assert(bst_sum_greater(bt, 5) == 24);
  assert(bst_sum_greater(bt, 7) == 17);
  assert(bst_sum_greater(bt, 8) == 9);
  assert(bst_sum_greater(bt, 9) == 0);

  printf("bst_sum_greater passed!\n");

  int height;
  int nodes;
  int leaves;

  bst_stats(bt, &height, &nodes, &leaves);
  assert(height == 3);
  assert(nodes == 7);
  assert(leaves == 4);

  bst_insert(bt, 15);
  bst_stats(bt, &height, &nodes, &leaves);
  assert(height == 4);
  assert(nodes == 8);
  assert(leaves == 4);

  bst_insert(bt, 3);
  bst_stats(bt, &height, &nodes, &leaves);
  assert(height == 4);
  assert(nodes == 9);
  assert(leaves == 4);

  printf("bst_stats passed\n");

  printf("Congraz, you mastered BINARY TREE\n");
  bst_destroy(bt);
}
