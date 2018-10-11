#include <stdio.h>
#include <stdlib.h>
struct node { int cargo; struct node *next; };

void print_list(struct node *foo) {
    while (foo) {
        printf("[ %i ][ *-]->", foo->cargo);
        foo = foo->next;
    }
    printf("NULL\n");
}

struct node * insert_front(struct node * foo, int new_cargo) {
    struct node * new_node = malloc(sizeof(struct node));
    new_node->cargo = new_cargo;
    new_node->next = foo;
    return new_node;
}

struct node * free_list(struct node * foo) {
    struct node * sub = foo;
    while(sub) {
        struct node * next = sub->next;
        free(sub);
        sub = next;
    }
    /*while (foo->next) {
        struct node * next = foo->next;
        printf("next: %p\tfoo:%p\n", next, foo);
        free(foo);
        foo = next;
    }
    foo->next = NULL;*/
    return sub;
}

int main() {
    struct node end;
    end.cargo = 0;
    end.next = NULL;
    print_list(insert_front(insert_front(insert_front(insert_front(NULL, 0), 1), 2), 3));
    printf("\n");
    struct node * start = insert_front(insert_front(insert_front(&end, 10), 20), 30);
    printf("Cargo: %i\n", start->cargo);
    printf("Got there\n");
    print_list(free_list(start));
    printf("Got here\n");

    return 0;

}