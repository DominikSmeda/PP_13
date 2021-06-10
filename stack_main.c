
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main(void)
{
    struct tnode *stack = NULL;
    struct tnode *list_elements = NULL;

    print_stack(stack);
    for (int i = 0; i < 10; i++)
    {
        struct tnode *el = malloc(sizeof(struct tnode));
        el->value = i;
        push_one(&stack, el);
    }

    for (int i = 0; i < 5; i++)
    {
        struct tnode *el = malloc(sizeof(struct tnode));
        el->value = 20 + i;
        push_one(&list_elements, el);
    }

    printf("stack: \n");
    print_stack(stack);
    printf("\n");
    printf("list_elements: \n");
    print_stack(list_elements);

    printf("\n");
    printf("stack = push_many(stack, list_elements): \n");
    stack = push_many(stack, &list_elements);
    print_stack(stack);

    printf("\n");
    struct tnode *tab[3];
    tab[0] = pop_one(&stack);
    tab[1] = pop_one(&stack);
    tab[2] = pop_one(&stack);

    printf("pop_one(stack) = %d\n", tab[0]->value);
    printf("pop_one(stack) = %d\n", tab[1]->value);
    printf("pop_one(stack) = %d\n", tab[2]->value);

    for (int i = 0; i < 3; i++)
    {
        free(tab[i]);
    }

    printf("\n");
    printf("pop_x(stack,10)\npop_list:\n");

    struct tnode *pop_list = pop_x(&stack, 13);
    print_stack(pop_list);

    printf("\nstack:\n");
    print_stack(stack);
    clear_stack(&pop_list);

    printf("\n");

    printf("pop_one(stack)\n");
    pop_one(&stack);

    clear_stack(&stack);
    printf("\n-----\n");
    return 0;
}
