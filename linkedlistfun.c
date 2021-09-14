#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
  int value;
  struct node* next;
};

void remove_ith(struct node** head, int i) {
    int a=i;
    if(a==0){
        struct node *f=*
        head;
        head=head->next;
        free(f);
    }else{
        while(head->next&&a>0){
            if(a>0){
                head=head->next;
                --a;
            }
        }
        if(a==0){
        struct node *f=head->next;
        head->next=head->next->next;
        free(f);
        }else{
            return;
        }
    }
}


void remove_maximum(struct node** head) {
    int x=head->value;
    while(head->next){
        if(head->value>x){
            x=head->value;
            head=head->next;
        }else{
            head=head->next;
        }
    }
    while(1){
        if(x==head->next->value){
            struct *p=head->next;
            head->next=head->next->next;
            free(p);
        }else{
            head=head->next;
        }
    }

}

void filter(struct node** head, bool (*pred)(int)) {

}

bool is_sorted(struct node* head, bool(*compare_func)(int, int)) {

}

void split(struct node* head, struct node** left, struct node** right) {

}

/* for testing filter, do not change */

bool is_even(int n) {
  return n % 2 == 0;
}

bool is_odd(int n) {
  return n % 2 == 1;
}

bool is_smaller(int n1, int n2) {
  return n1 < n2;
}

/* utility functions for testing */

struct node* create_linked_list(int *arr, int len) {
  struct node* head = NULL;
  struct node** curr = &head;
  for(int i = 0; i < len; i++) {
    *curr = malloc(sizeof(struct node));
    (*curr)->value = arr[i];
    (*curr)->next = NULL;
    curr = &((*curr)->next);
  }
  return head;
}

int value_at(struct node* head, int i) {
  if(i == 0) {
    return head->value;
  }
  return value_at(head->next, i - 1);
}

int linked_list_len(struct node* head) {
  if(!head) {
    return 0;
  }
  return 1 + linked_list_len(head->next);
}

void free_linked_list(struct node* head) {
  if(head == NULL) {
    return;
  }
  free_linked_list(head->next);
  free(head);
}

void print_linked_list(struct node* head) {
  if(head == NULL) {
    printf("\n");
    return;
  }
  printf("%d ", head->value);
  print_linked_list(head->next);
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  struct node* head = create_linked_list(arr1, 10);

  /* test remove_ith */
  remove_ith(&head, 0);
  remove_ith(&head, 4);
  assert(value_at(head, 0) == 2);
  assert(value_at(head, 1) == 3);
  assert(value_at(head, 2) == 4);
  assert(value_at(head, 3) == 5);
  assert(value_at(head, 4) == 7);
  assert(value_at(head, 5) == 8);
  assert(value_at(head, 6) == 9);
  assert(value_at(head, 7) == 10);
  assert(linked_list_len(head) == 8);

  printf("remove_ith passed!\n");
  free_linked_list(head);

  int arr2[] = {2, 1, 3, 4, 5};
  head = create_linked_list(arr2, 5);
  remove_maximum(&head);
  assert(linked_list_len(head) == 4);
  assert(value_at(head, 0) == 2);
  assert(value_at(head, 1) == 1);
  assert(value_at(head, 2) == 3);
  assert(value_at(head, 3) == 4);

  remove_maximum(&head);
  assert(linked_list_len(head) == 3);
  assert(value_at(head, 0) == 2);
  assert(value_at(head, 1) == 1);
  assert(value_at(head, 2) == 3);

  remove_maximum(&head);
  assert(linked_list_len(head) == 2);
  assert(value_at(head, 0) == 2);
  assert(value_at(head, 1) == 1);

  remove_maximum(&head);
  assert(linked_list_len(head) == 1);
  assert(value_at(head, 0) == 1);

  printf("remove_maximum passed!\n");
  free_linked_list(head);

  head = create_linked_list(arr1, 10);
  filter(&head, is_even);
  assert(linked_list_len(head) == 5);
  assert(value_at(head, 0) == 2);
  assert(value_at(head, 1) == 4);
  assert(value_at(head, 2) == 6);
  assert(value_at(head, 3) == 8);
  assert(value_at(head, 4) == 10);
  free_linked_list(head);

  head = create_linked_list(arr1, 10);
  filter(&head, is_odd);

  assert(linked_list_len(head) == 5);
  assert(value_at(head, 0) == 1);
  assert(value_at(head, 1) == 3);
  assert(value_at(head, 2) == 5);
  assert(value_at(head, 3) == 7);
  assert(value_at(head, 4) == 9);
  free_linked_list(head);
  printf("filter passed\n");

  head = create_linked_list(arr1, 10);
  assert(is_sorted(head, is_smaller) == 1);
  free_linked_list(head);

  head = create_linked_list(arr2, 5);
  assert(is_sorted(head, is_smaller) == 0);
  free_linked_list(head);

  printf("is sorted passed\n");

  head = create_linked_list(arr1, 10);
  struct node* left;
  struct node* right;
  split(head, &left, &right);
  assert(linked_list_len(left) == 5);
  assert(linked_list_len(right) == 5);

  free_linked_list(left);
  free_linked_list(right);

  int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  head = create_linked_list(arr3, 11);
  print_linked_list(head);
  split(head, &left, &right);
  assert(linked_list_len(left) == 6);
  assert(linked_list_len(right) == 5);
  free_linked_list(left);
  free_linked_list(right);

  printf("split passed!\n");
  printf("you mastered linked list !!\n");

  return 0;
}
