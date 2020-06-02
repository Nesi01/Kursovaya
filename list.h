#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"


head *create_head();
void create_node(comps *data, head *head);
void list_out(head *head);
void normalize_id(head *head_file);

#endif // LIST_H_INCLUDED
