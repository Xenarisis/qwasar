#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void insertAt(struct list **head, int position/*, truc ...*/) {
    if(position < 0)    {
        puts("Position invalide");
        return;
    }
    if(position == 0)   {
        pushFront(head/* truc ...*/);
    }
    struct list *newNode = createNode(/* truc */);
    struct list *current = *head;
    int currentPosition = 0;
    while(current != NULL && currentPosition < position - 1)    {
        current = current->next;
        currentPosition += 1;
    }
    if(current == NULL) {
        puts("Position invalide");
        /* free(newNode->truc)*/
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    insertAt(&MyList/*nbr, truc...*/);

    return 0;
}