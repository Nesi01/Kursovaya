#include "data_operations.h"


void delete_info(head *head_file)
{
    int choice, chk;
    float value;
    float (*kind[5])(node*);


    kind[1] = YearValue;
    kind[2] = PriceValue;
    kind[3] = ReviewValue;
    kind[4] = RatingValue;
    do
    {
        print_header();
        list_out(head_file);
        printf("\nDELETING INFO\n");
        printf("| | Choose field: |\n");
        printf("+-+---------------+\n");
        printf("|1| - Year        |\n");
        printf("|2| - Price       |\n");
        printf("|3| - Reviews     |\n");
        printf("|4| - Rating      |\n");
        printf("|0| - Cancel      |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice!=0)
        {
        printf("Enter value: ");
        scanf("%f", &value);
        }
        chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
            chk = delete_value(value,head_file,kind[choice]);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 2:
            chk = delete_value(value,head_file,kind[choice]);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 3:
            chk = delete_value(value,head_file,kind[choice]);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 4:
            chk = delete_value(value,head_file,kind[choice]);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
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


float YearValue(node *p)
{
    return p->data->year;
}

float PriceValue(node *p)
{
    return p->data->cost;
}

float ReviewValue(node *p)
{
    return p->data->reviews;
}

float RatingValue(node *p)
{
    return p->data->rating;
}


int delete_value(float value, head *head, float (*funcName)(node*))
{
    node *p, *p1;
    int chk;

    p1 = head->first;
    //Deleting head until data isn't appropriate//
    while(funcName(p1)==value)
    {
        p = p1->next;
        free(p1);
        p1 = p;
        p1->prev = NULL;
        head->first = p1;
        head->cnt -= 1;
        chk = 1;
    }

    //Goes through list and delete nodes//
    //With appropriate data             //
    do
    {
        p = p1->next;
        if(funcName(p)==value)
        {
            chk = 1;
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

    return chk;
}


void copy_info(head *clipboard,head *head_file)
{
    int i;
    node *temp;

    temp = head_file->first;
    create_node(temp->data,clipboard);
    if(clipboard->cnt!=0) //MAKE CLEANING
    for(i=1;i<head_file->cnt;i++)
    {
        temp = temp->next;
        add_last(clipboard,temp->data);
    }
}


void paste_info(head *clipboard,head *head_file)
{
    int i=1;
    node *temp;

    temp = clipboard->first;
    if(head_file->cnt==0)
    {
        create_node(temp->data,head_file);
        i = 2;
        temp = temp->next;
    }
    add_last(head_file,temp->data);
    for(i;i<clipboard->cnt;i++)
    {
        temp = temp->next;
        add_last(head_file,temp->data);
    }
}
