#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void PushBack(struct list **head/*, truc */)    {
    struct list *newNode = CreateNode(/* truc */);
    if(*head == NULL)   {
        *head = newNode;
        return;
    }
    struct list *current = *head;
    while(current->next != NULL)    {
        current = current->next;
    }
    current->next = newNode;
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    PushBack(&MyList/*, truc_1, truc_2, ...*/);

    return 0;
}
