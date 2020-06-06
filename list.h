#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"


head *create_head();
void create_node(comps *data, head *head);
void list_out(head *head);
//void list_out_reverse(head *head);
void normalize_id(head *head_file);
void free_head(head *q);
void free_node(node *temp);
void free_list(head *q);
void free_at_all(head *head2);
void free_nodes_only(head *q);

#endif // LIST_H_INCLUDED
