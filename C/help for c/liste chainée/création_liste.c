#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list {
    /* truc donc int, char, etc */
    struct list* next;
} list_a;

struct list *CreateNode(/* truc_1, truc_2 */)   {
    struct list *NewNode = malloc(sizeof(list_a));
    
    if(NewNode == NULL) {
        puts("Erreur avec malloc");
        return NULL;
    }
    /* NewNode->truc = truc_1/truc_2 */
    NewNode->next = NULL;

    return NewNode;
}

int main()  {
    struct list *MyList = malloc(sizeof(list_a));

    MyList = CreateNode(/* truc */);

    return 0;
}