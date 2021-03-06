#ifndef FILE_OPERATIONS_H_INCLUDED
#define FILE_OPERATIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "data_operations.h"


void open_csv(head* clipboard);
void read_from_csv(FILE* file, head* head_file);
void create_file();
void delete_file();


#endif // FILE_OPERATIONS_H_INCLUDED
