#include "data_operations.h"


void delete_info(head *head_file)
{
    int choice, chk, card0, card2, i;
    float value;
    float (*kind[5])(node*);

    kind[1] = YearValue;
    kind[2] = PriceValue;       //These functions return value
    kind[3] = ReviewValue;      //that is stored in the node
    kind[4] = RatingValue;
    do
    {
        print_header();
        list_out(head_file);
        printf("\nDELETING INFO\n");
        printf("| | Delete by field    |    | | Delete by number   |\n");
        printf("+-+--------------------+----+-+--------------------+\n");
        printf("|1| - Year             |    |5| - Certain node     |\n");
        printf("|2| - Price            |    |6| - Interval from-to |\n");
        printf("|3| - Reviews          |\n");
        printf("|4| - Rating           |\n\n");
        printf("|0| - Cancel           |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice!=0&&choice!=5&&choice!=6)
        {
        printf("Enter value: ");
        scanf("%f", &value);
        }
        chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            chk = delete_value(value,head_file,kind[choice]);
            if (chk==0)
            {
                system("cls");
                printf("There is no such value\n\n");
            }
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }
            break;
        case 5:
            printf("Enter number to delete: ");
            scanf("%d",&card0);
            if(card0>head_file->cnt)
            {
                system("cls");
                printf("There are less than %d values\n\n",card0);
            }
            else if(card0<=0)
            {
                system("cls");
                choice = 0;
            }
            else
            {
                delete_node(card0,head_file);
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }
            break;
        case 6:
            printf("Enter two numbers: ");
            scanf("%d%d",&card0,&card2);
            if(card0>head_file->cnt&&card2>head_file->cnt)
            {
                system("cls");
                printf("There are less than %d and %d values\n\n",card0, card2);
            }
            else if(card0<=0&&card2<=0)
            {
                system("cls");
                choice = 0;
            }
            else
            {
                if(card0>card2)
                {
                    chk = card0;
                    card0 = card2;
                    card2 = chk;
                }
                if(card2>head_file->cnt) card2 = head_file->cnt;
                if(card0<=0) card0 = 1;
                for(i=card0;i<=card2;i++)
                {
                    delete_node(card0,head_file);
                }
                system("cls");
                printf("Nodes between %d and %d have been deleted\n", card0,card2);
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
    int chk = 0;

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


//Deletes node with curtain id//
void delete_node(int num,head *head_file)
{
    node *p, *p1;
    int i;

    if(num<=head_file->cnt) //Check for getting out the border
    {
        p1 = head_file->first;
        if (num==1)
        {
            p = p1->next;
            free(p1);
            p1 = p;
            p1->prev = NULL;
            head_file->first = p1;
            head_file->cnt -= 1;
        }
        else
        {
            for(i=0;i<num-1;i++) p1 = p1->next;

            p = p1->prev;
            if(p1->next!=NULL)
            {
                p->next = p1->next;
                p1->next->prev = p;
            }
            else
            {
                p->next = NULL;
                head_file->last = p;
            }
            head_file->cnt -=1;
            free(p1);
            p1 = p;
        }
    }
}


//Copies list to external list to paste in other file//
void copy_info(head *clipboard,head *head_file)
{
    int i;
    node *temp;
    comps *str0=NULL;

    temp = head_file->first;

    if(clipboard->cnt!=0) free_nodes_only(clipboard);
    str0 = copy_struct(temp->data);
    create_node(str0,clipboard);

    for(i=1;i<head_file->cnt;i++)
    {
        temp = temp->next;
        str0 = copy_struct(temp->data);
        add_last(clipboard,str0);
    }
}


void paste_info(head *clipboard,head *head_file)
{
    int i=1;
    node *temp;
    comps *str0=NULL;

    temp = clipboard->first;
    if(head_file->cnt==0)
    {
        str0 = copy_struct(temp->data);
        create_node(str0,head_file);
        i = 2;
        temp = temp->next;
    }
    str0 = copy_struct(temp->data);
    add_last(head_file,str0);
    for(;i<clipboard->cnt;i++)
    {
        temp = temp->next;
        str0 = copy_struct(temp->data);
        add_last(head_file,str0);
    }
}


void save_info(head* head_file,char* filename)
{
    int choice, slen;
    FILE *file;

    do
    {
        printf("File %s\n",filename);
        printf("\n");
        print_header();
        list_out(head_file);

        printf("|1| - Save as %s\n",filename);
        printf("|2| - Save as...\n");
        printf("|0| - Cancel\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            file = fopen(filename,"w");

            save_in_file(file,head_file);

            fclose(file);
            choice = 0;
            system("cls");
            printf("Information saved to %s\n",filename);
            break;
        case 2:
            printf("Enter name of file to save: ");
            fgets(filename,31,stdin);
            slen=strlen(filename);
            filename[slen-1]='\0';
            file = fopen(filename,"w");

            save_in_file(file,head_file);

            fclose(file);
            choice = 0;
            system("cls");
            printf("Information saved to %s\n",filename);
            break;
        case 0:
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }
    }while(choice!=0);
}


void save_in_file(FILE *file, head *head_file)
{
    int i;
    node *temp;

    temp = head_file->first;

    for (i=0;i<head_file->cnt;i++)
    {
        fprintf(file,"%s;",temp->data->name);
        fprintf(file,"%s;",temp->data->type);
        fprintf(file,"%d;",temp->data->year);
        fprintf(file,"%.2f;",temp->data->cost);
        fprintf(file,"%d;",temp->data->reviews);
        fprintf(file,"%.1f\n",temp->data->rating);
        temp = temp->next;
    }
}
