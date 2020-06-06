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

    temp->id = 1;
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
    for(i=0;i<head->cnt;i++)
    {
        printf("|%3d|%30s |%12s |%5d |%16.2f |%6d |%5.1f |\n",
        p->id,
        p->data->name,
        p->data->type,
        p->data->year,
        p->data->cost,
        p->data->reviews,
        p->data->rating);
        p = p->next;
    }
    printf("\n");
}


void list_out_reverse(head *head)
{
    node *p;
    int i;

    p = head->last;
    for(i=0;i<head->cnt;i++)
    {
        printf("|%3d|%30s |%12s |%5d |%16.2f |%6d |%5.1f |\n",
        p->id,
        p->data->name,
        p->data->type,
        p->data->year,
        p->data->cost,
        p->data->reviews,
        p->data->rating);
        p = p->prev;
    }
    printf("\n");
}


//There is no manipulation with id in other functions    //
//So after some functions it is necessary to rearrange id//
void normalize_id(head *head_file)
{
    node *temp = NULL;
    int i, current_id;
    temp = head_file->first;

    for(i=0,current_id=1;i<head_file->cnt;i++,current_id++)
    {
        temp->id = current_id;
        temp = temp->next;
    }
}


void free_head(head *q){
    free_node(q->first);
    q->first = NULL;
    q->last = NULL;
    free(q);
}


void free_node(node *temp){
    if((temp->next) != NULL) temp->next = NULL;
    if((temp -> prev) != NULL) temp -> prev = NULL;

    free(temp->data->name);
    free(temp->data->type);
    free(temp->data);
    free(temp);
}


void free_list(head *q){

    node *temp = NULL;
    node *p = NULL;

    temp = q->first;
    free_head(q);

    while((temp->next) != NULL){
        p = NULL;
        p = temp;
        temp = temp -> next;
        free_node(p);
    }
    free_node(temp);
}

void free_at_all(head *head2)
{
    if((head2->cnt) == 1) free_head(head2);
    else if((head2->cnt) > 1) free_list(head2);
    else if ((head2->cnt) == 0) free(head2);
}


void free_nodes_only(head *q){

    node *temp = NULL;
    node *p = NULL;

    temp = q->first;
    q->cnt = 0;

    while((temp -> next) != NULL){
        p = temp;
        temp = temp -> next;
        free_node(p);
    }
    free_node(temp);

    q->first=NULL;
    q->last=NULL;
}
