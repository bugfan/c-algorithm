#include <stdio.h>
#include <stdlib.h>
#include "al.h"
struct LinkList{
    void * data;
    struct List * Next;
}List;
int main()
{
    recursion();
    link_list();
    return 0;
}
void link_list(){
    struct LinkList * head;
    head=(struct LinkList *)malloc(sizeof(struct LinkList *));
    head->data=(void *)23;
    printf("z:%d\n",head->data);
    free(head);
}

void recursion(){ 
    printf("zxy\n");
}