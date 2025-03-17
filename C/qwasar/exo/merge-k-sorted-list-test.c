#include <stdlib.h>
#include <stdio.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode {
    int val;
    struct s_listnode* next;
} listnode;
#endif

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array {
    int size;
    listnode **array;
} listnode_array;
#endif

listnode* merge_k_sorted_lists(listnode_array* head_array) {
    if (head_array == NULL || head_array->array == NULL) {
        return NULL;
    }

    listnode *list1 = malloc(sizeof(listnode));
    listnode *head = list1; 
    listnode *list2 = NULL;
    int index_array = 0;

    while (index_array < head_array->size) { 
        list2 = head_array->array[index_array]; 
        
        while (list2!= NULL) {
            head->next = malloc(sizeof(listnode));
            head = head->next;

            head->val = list2->val;
            head->next = NULL;

            list2 = list2->next;
        }

        index_array++;
    }

    listnode* result = list1->next;
    free(list1);

    return result;
}


void get_list_sort(listnode *head) {
   listnode *temp = head;
   listnode *temp1;
   listnode *temp3;
   int min;

     while (temp != NULL) {
        temp3 = temp;
        min = temp->val;
        temp1 = temp->next;
        while(temp1 != NULL) {
            if(min > temp1->val) {
            temp3 = temp1;
            min = temp3->val;
            }
            temp1 = temp1->next;
        }
        temp3->val = temp->val;
        temp->val = min;
        temp = temp->next;
    }
}