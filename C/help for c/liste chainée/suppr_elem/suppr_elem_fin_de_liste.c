#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void popFront(struct list **head) {
    if(*head == NULL)   {
        puts("La liste est vide");
        return;
    }
    struct list *temp = *head;
    *head = (*head)->next;
    /*free(temp->truc)*/;
    free(temp);
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    popFront(&MyList);

    return 0;
}