#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void popBack(struct list **head)    {
    if(*head == NULL)   {
        puts("La liste est vide");
        return;
    }
    if((*head)->next == NULL)   {
        /* free((*head)->truc)*/
        free(*head);
        *head = NULL;
        return;
    }
    struct list *current = *head;
    while(current->next->next != NULL)  {
        current = current->next;
    }
    /* free(current->next->truc) */
    free(current->next);
    current->next = NULL;
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    popBack(&MyList);

    return 0;
}