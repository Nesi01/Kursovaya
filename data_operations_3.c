#include "data_operations.h"



void search_info(head *head_file)
{
    int choice, chk, i;
    float temp, value0, value2;
    float (*kind[5])(node*);


    kind[1] = YearValue;
    kind[2] = PriceValue;
    kind[3] = ReviewValue;
    kind[4] = RatingValue;
    do
    {
        print_header();
        list_out(head_file);
        printf("\nSEARCHING INFO\n");
        printf("| | Search by field    |\n");
        printf("+-+--------------------+\n");
        printf("|1| - Year             |\n");
        printf("|2| - Price            |\n");
        printf("|3| - Reviews          |\n");
        printf("|4| - Rating           |\n");
        printf("|0| - Cancel           |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice!=0)
        {
            printf("Find exactly value or interval?\n");
            printf("|1| - exactly\n");
            printf("|2| - interval\n");
            scanf("%d", &i);
            if(i==1)
            {
                printf("Enter value: ");
                scanf("%f", &value0);
            }
            else if(i==2)
            {
                printf("Enter TWO values: ");
                scanf("%f%f", &value0,&value2);
                if (value2<value0)
                {
                    temp = value2;
                    value2 = value0;
                    value0 = temp;
                }
            }
            else choice = 0;

        }
        chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            if(i==1) chk = search_value(value0,head_file,kind[choice]);
            else chk = search_between_value(value0,value2,head_file,kind[choice]);
            if (chk==0)
            {
                system("cls");
                printf("There is no such value\n\n");
            }
            else
            {
                normalize_id(head_file);
                system("cls");
                printf("Search results:\n");
                printf("If you want more filters, make search again\n");
                choice = 0;
            }

            break;
        case 0:
            system("cls");

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }
    }while(choice!=0);

}


int search_value(float value, head *head, float (*funcName)(node*))
{
    node *p, *p1;
    int chk = 0;

    p1 = head->first;

    if(funcName(p1)==value) chk = 1;
    do
    {
        p1 = p1->next;
        if(funcName(p1)==value) chk = 1;
    } while(p1->next!=NULL&&chk!=1);

    p1 = head->first;

    if(chk==1)
    {
        //Deleting head until data isn't appropriate//
        while(funcName(p1)!=value)
        {
            //delete_node(1,head);
            p = p1->next;
            free(p1);
            p1 = p;
            p1->prev = NULL;
            head->first = p1;
            head->cnt -= 1;
           // chk = 1;
        }

        //Goes through list and delete nodes//
        //With appropriate data             //
        do
        {
            p = p1->next;
            if(funcName(p)!=value)
            {
              //  chk = 1;
                p1->next = p->next;
                if(p->next!=NULL) p->next->prev = p1;
                else head->last = p1;
                head->cnt -= 1;
                free(p);
            }
            else
            {
                p1 = p1 -> next;
            }
        }while (p1->next!=NULL);
    }

    return chk;
}


int search_between_value(float value0, float value2, head *head, float (*funcName)(node*))
{
    node *p, *p1;
    int chk = 0;


    p1 = head->first;

    if((funcName(p1)>=value0)&&(funcName(p1)<=value2)) chk = 1;
    if(chk!=1)
    {
        do
        {
            p1 = p1->next;
            if((funcName(p1)>=value0)&&(funcName(p1)<=value2)) chk = 1;
        } while(p1->next!=NULL&&chk!=1);
    }
    p1 = head->first;

    if(chk==1)
    {
        //Deleting head until data isn't appropriate//
        while((funcName(p1)<value0)||(funcName(p1)>value2))
        {
            //delete_node(1,head);
            p = p1->next;
            free(p1);
            p1 = p;
            p1->prev = NULL;
            head->first = p1;
            head->cnt -= 1;
         //   chk = 1;
        }

        //Goes through list and delete nodes//
        //With appropriate data             //
        do
        {
            p = p1->next;

            if((funcName(p)<value0)||(funcName(p)>value2))
            {
              //  chk = 1;
                p1->next = p->next;
                if(p->next!=NULL) p->next->prev = p1;
                else head->last = p1;
                head->cnt -= 1;
                free(p);
            }
            else
            {
                p1 = p1 -> next;
            }
        }while (p1->next!=NULL);
    }

    return chk;
}


int sort_info(head *head_file, int is_reverse)
{
    int choice, chk, i;
    float temp, value0, value2;
    float (*kind[5])(node*);


    kind[1] = YearValue;
    kind[2] = PriceValue;
    kind[3] = ReviewValue;
    kind[4] = RatingValue;
    do
    {
        print_header();
        list_out(head_file);
        printf("\n| |       Sort by      |\n");
        printf("+-+--------------------+\n");
        printf("|1| - Year             |\n");
        printf("|2| - Price            |\n");
        printf("|3| - Reviews          |\n");
        printf("|4| - Rating           |\n");
        printf("|5| - Reverse          |\n");
        printf("|0| - Cancel           |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        //chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            sort_value(head_file,kind[choice]);
            //normalize_id(head_file);
            //system("cls")
            break;
        case 5:
            if(is_reverse==1) is_reverse = 0;
            else is_reverse = 1;
            choice = 0;
            system("cls");

            break;
        case 0:
            system("cls");

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }
    }while(choice!=0);

    return is_reverse;
}


void sort_value(head *head_file, float (*funcName)(node*))
{
    node *p, *p1, *temp;
    int i,k;

    p1 = head_file->first;

    for(i=0;i<head_file->cnt-1;i++)
    {
        p1 = head_file->first;
        p = p1->next;
        for(k=0;k<head_file->cnt-i-2;k++)
        {
            if(funcName(p1)>funcName(p))
            {
                /*temp = p1->prev;
                p1->next = p->next;
                p1->next->prev = p1;
                p->prev = temp;
                if(p->prev!=NULL) p->prev->next = p;
                p->next = p1;
                p1->prev = p;*/

                if(p1->prev!= NULL) p1->prev->next = p;
                p->prev = p1->prev;
                temp = p->next;
                p->next = p1;
                p1->prev = p;
                p1->next = temp;
                p1->next->prev = p1;

            }
            else
            {
                if(p1->next!=NULL) p1 = p1->next;
            }
            if(p1->next!=NULL) p = p1->next;
        }
    }

}
