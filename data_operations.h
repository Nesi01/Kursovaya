#ifndef DATA_OPERATIONS_H_INCLUDED
#define DATA_OPERATIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "struct_csv.h"
#include "list.h"


void menu(head* clipboard,head* head_file, char* filename);
void add_info(head *head_file);
void add_first(head *head_file, comps *data);
void add_last(head *head_file, comps *data);
void add_in_position(head *head_file, comps *data, int n);



#endif // DATA_OPERATIONS_H_INCLUDED
