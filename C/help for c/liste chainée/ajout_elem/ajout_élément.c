#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

void pushfront(struct list **head/*, truc_1, truc_2, ...*/)   {
    struct list *newNode = CreateNode(/* truc */);
    newNode->next = *head;
    *head = newNode;
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    PushFront(&MyList/*, truc_1, truc_2, ...*/);

    return 0;
}