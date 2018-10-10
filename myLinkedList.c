#include <stdio.h>
#include <stdlib.h>

struct node { int cargo; struct node *next; };
struct node * curr_head = NULL;

void print_list(struct node * foo) {
  if (curr_head == NULL) {
    printf("NULL Called");
  }else{
    while (foo) {
      printf("Node is: %i\n", foo->cargo);
      foo = foo->next;
    }
  }
}

struct node * insert_front(struct node * foo, int new_cargo) {
  if (curr_head) {
    foo->cargo = new_cargo;
    foo->next = curr_head;
    curr_head = foo;
    return curr_head;
  }else{
    return NULL;
  }
}

struct node * free_list(struct node * foo) {
    struct node * pointer = foo;
    while (pointer->next->next){
        pointer = pointer->next;
    }
    //printf("pointer cargo:%i\n", pointer->cargo);
    pointer->next = NULL;
    if (pointer == foo) {
        return foo;
    }
    return free_list(foo);
}

int main() {
  
  struct node a, b, c, d;
  a.cargo = 0;
  curr_head = &a;
  b.cargo = 1;
  c.cargo = 2;
  d.cargo = 3;

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = NULL;

  print_list(&a);

  struct node f;
  f.cargo = 6;
  f.next = NULL;
  printf("Adding stuff in:\n");
  insert_front(&f, 10);
  print_list(curr_head);

  free_list(&f);
  printf("We freed a list:\n");
  print_list(curr_head);
    
  return 0;
}

