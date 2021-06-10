#include "stack.h"

void print_stack(struct tnode *head)
{
    printf("head ->");
    if (!head)
    {
        printf("NULL\n");
        return;
    }

    int size = 0;
    struct tnode *walker = head;
    for (; walker; walker = walker->next)
    {
        size++;
    }

    walker = head;
    // printf("%d ", size);
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            walker = walker->next;
        }
        printf(" ['%d'] ->", walker->value);
        walker = head;
    }

    printf(" NULL\n");
}

void push_one(struct tnode **head, struct tnode *el)
{
    if (*head == NULL)
    {
        *head = el;
    }
    else
    {
        el->next = *head;
        *head = el;
    }
}

struct tnode *push_many(struct tnode *head, struct tnode **list_elements)
{

    struct tnode *walker = *list_elements;
    for (; walker->next; walker = walker->next)
    {
    }
    walker->next = head;
    walker = *list_elements;
    *list_elements = NULL;
    return walker;
}

struct tnode *pop_one(struct tnode **head)
{
    if (*head == NULL)
    {
        printf("! Stos pusty !");
        return NULL;
    }
    struct tnode *pop = *head;
    *head = (*head)->next;

    return pop;
}

struct tnode *pop_x(struct tnode **head, int x)
{
    struct tnode *start = *head;
    struct tnode *walker = *head;
    int size = 1;
    for (int i = 0; (i < (x - 1)) && walker->next; i++)
    {
        walker = walker->next;
        size++;
    }
    if (size < x)
    {
        printf("\n! Stos ma mniejszy rozmiar !\n");
    }

    *head = walker->next;
    walker->next = NULL;

    return start;
}

void clear_stack(struct tnode **head)
{
    struct tnode *walker = *head;
    while (walker)
    {
        struct tnode *next = walker->next;
        free(walker);
        walker = next;
    }

    *head = NULL;
}