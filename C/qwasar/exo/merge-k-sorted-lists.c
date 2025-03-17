#include <stdlib.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

listnode *CreateNode(int val) {
    listnode *NewNode = malloc(sizeof(listnode));

    if(NewNode == NULL) {
        return NULL;
    }
    NewNode->val = val;
    NewNode->next = NULL;

    return NewNode;
}

void PushBack(listnode **head, int val)    {
    listnode *newNode = CreateNode(val);
    if(head == NULL)   {
        *head = newNode;
        return;
    }
    listnode *current = *head;
    while(current->next != NULL)    {
        current = current->next;
    }
    current->next = newNode;
}

listnode* merge_k_sorted_lists(listnode_array* head_array) {
    if (head_array == NULL || head_array->array == NULL) {
        return NULL;
    }
    
    listnode *head = NULL;
    listnode *temp = NULL;

    int index = 0;

    while(index < head_array->size && head_array->array[index] != NULL){
        temp = head_array->array[index];
        while(temp->next != NULL) {
            PushBack(&head, temp->val);
            temp = temp->next;
        }
        index++;
    }

    return head;
}


/* listnode* merge_k_sorted_lists(listnode_array* head_array) {
    ListNode head, *p;
    
    p = &head;
    
    int index = 0;
    while (p->next != NULL) {
        if (l1->val <= l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    // chain remaining
    if (l1) p->next = l1;
    if (l2) p->next = l2;
    
    p = head->next;
    
    return p;
} */

