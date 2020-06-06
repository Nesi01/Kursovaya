#ifndef DATA_OPERATIONS_H_INCLUDED
#define DATA_OPERATIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "struct_csv.h"
#include "list.h"


//Data_operations.c
void menu(head* clipboard,head* head_file, char* filename);
void add_info(head *head_file);
void add_first(head *head_file, comps *data);
void add_last(head *head_file, comps *data);
void add_in_position(head *head_file, comps *data, int n);
void edit_info(int n, head *head_file);

//Data_operations_2.c
void delete_info(head *head_file);
float YearValue(node *p);
float PriceValue(node *p);
float ReviewValue(node *p);
float RatingValue(node *p);
int delete_value(float value, head *head, float (*funcName)(node*));
void delete_node(int num,head *head_file);

void copy_info(head *clipboard,head *head_file);
void paste_info(head *clipboard,head *head_file);

void save_info(head* head_file,char* filename);
void save_in_file(FILE *file, head *head_file);

//Data_operations_3.c
void search_info(head *head_file);
int search_value(float value, head *head, float (*funcName)(node*));
int search_between_value(float value0, float value2, head *head, float (*funcName)(node*));

int sort_info(head *head_file,int is_reverse);
void sort_value(head *head_file, float (*funcName)(node*));
void sort_string(head *head_file,int choice);

#endif // DATA_OPERATIONS_H_INCLUDED
