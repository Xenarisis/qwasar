#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void rmAt(struct list **head, int position) {
    if(position < 0 || *head == NULL)   {
        puts("Postion invalide ou liste vide");
        return;
    }
    if(position == 0)   {
        /*popFront(head);*/
        return;
    }
    struct list *current = *head;
    int currentPosition = 0;
    while(current->next != NULL && currentPosition < position - 1)  {
        current = current->next;
        currentPosition += 1;
    }
    if(current->next = NULL)    {
        puts("Position invalide");
        return;
    }
    struct list *temp = current->next;
    current->next = current->next->next;
    /*free(temp->truc)*/
    free(temp);
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    rmAt(&MyList/*nbr*/);

    return 0;
}