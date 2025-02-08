#include <stdio.h>
#include <stdlib.h>

struct  Node
{   
    int item;
    struct Node*next;
};


void insertAtLast(struct Node **s, int data)
{   
    struct Node *n, *t;

    n = (struct Node*)malloc(sizeof(struct Node));
    n->item = data;
    n->next = NULL;
    if (*s == NULL)
        *s=n;
    else
    {
        t = *s;
        while (t -> next != NULL)
            t = t->next;
        t-> next = n;
    }
}
void deleteFirst(struct Node **s)
{
    struct Node *t;
    if(*s != NULL){
        t = *s;
        *s = t->next;
        free(t);
    }
}

void viewList(struct Node *start)
{
    while(start)
    {
        printf("%d ", start->item);
        start = start->next;
    }
}


int main() 
{
    struct Node *start = NULL;
    
    insertAtLast(&start,25);
    insertAtLast(&start, 35);
    insertAtLast(&start, 25);
    insertAtLast(&start, 39);
    insertAtLast(&start, 45);
    insertAtLast(&start, 23);
    viewList(start);
    printf("\n");
    deleteFirst(&start);
    printf("\n");
    viewList(start);
    printf("\n");
    return 0;    
}