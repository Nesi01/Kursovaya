#ifndef STRUCT_CSV_H_INCLUDED
#define STRUCT_CSV_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


char **simple_split(char *str, int length, char sep);
comps *struct_fill(char **str);
comps *new_struct();
void print_header();


#endif // STRUCT_CSV_H_INCLUDED
