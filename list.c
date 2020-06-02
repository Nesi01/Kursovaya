#include "list.h"


head *create_head()
{
    head *ph=NULL;

    ph=(head*)malloc(sizeof(head));
    if(ph)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}



void create_node(comps *data, head *head)
{
      node *temp=NULL;
      temp = (node *)malloc(sizeof(node));
      temp->data = (comps*)malloc(sizeof(comps));

      temp->next = NULL;
      temp->prev = NULL;
      head->first = temp;
      head->last = temp;
      head->cnt += 1;
      temp->data = data;
}


void list_out(head *head)
{
        node *p;
        int i;

        p = head->first;
        //while(p != NULL){  //Isn't used because of circular list
        for(i=0;i<head->cnt;i++)
        {
            printf("|%30s |%10s |%5d |%16.2f |%6d |%5.1f |\n",
            p -> data -> name,
            p -> data -> type,
            p -> data -> year,
            p -> data -> cost,
            p -> data -> reviews,
            p -> data -> rating);
            p = p->next;
        }
        printf("\n");
}
