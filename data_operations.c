#include "data_operations.h"


void menu(head* clipboard,head* head_file,char* filename)
{
    int choice;
    comps *str0=NULL;

    system("cls");
    do
    {
        printf("File %s\n",filename);
        if(head_file->first!=NULL)
        {
            printf("\n");
            print_header();
            list_out(head_file);

            printf("| |     ACTIONS WITH DATA     |\n");
            printf("+-+---------------------------+\n");
            printf("|1| - Add new                 |\n");
            printf("|2| - Change                  |\n");
            printf("|3| - Search                  |\n");
            printf("|4| - Sort                    |\n");
            printf("|5| - Delete                  |\n");
            printf("|6| - Copy                    |\n");
            printf("|7| - Paste                   |\n");
            printf("|8| - Save file               |\n");
            printf("|0| - Exit                    |\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            getchar();

            switch(choice)
            {
            case 1:
                system("cls");
                printf("File %s\n",filename);
                printf("\n");
                print_header();
                list_out(head_file);
                add_info(head_file);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                    //ADD FUNC IN EMPTY FILE TOO
                break;
            case 8:

                break;
            case 0:
                system("cls");

                break;
            default:
                system("cls");
                puts("Incorrect input!");
                break;
            }
        }
        else
        {
            printf("\nFile is empty\n\n");
            printf("| |     ACTIONS WITH DATA     |\n");
            printf("+-+---------------------------+\n");
            printf("|1| - Add new                 |\n");
            printf("|2| - Paste                   |\n");
            printf("|0| - Exit                    |\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            getchar();

            switch(choice)
            {
            case 1:
                system("cls");
                printf("Adding:\n");
                str0 = new_struct();
                create_node(str0,head_file);
                system("cls");
                break;
            case 2:
                                //ADD PASTE FUNCTION
                break;
            case 0:
                system("cls");

                break;
            default:
                system("cls");
                puts("Incorrect input!");
                break;
            }
        }

    } while(choice!=0);

}



void add_info(head *head_file)
{
    int choice, n;
    comps *str0=NULL;

    do
    {
        printf("| |      Position to add      |\n");
        printf("+-+---------------------------+\n");
        printf("|1| - First                   |\n");
        printf("|2| - Last                    |\n");
        printf("|3| - Number                  |\n");
        printf("|0| - Cancel                  |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            printf("Adding:\n");
            str0 = new_struct();
            add_first(head_file,str0);
            normalize_id(head_file);       //Making right id order
            system("cls");
            printf("Added the first\n");
            choice = 0;
            break;
        case 2:     //User inputs data for new node
            system("cls");
            printf("Adding:\n");
            str0 = new_struct();
            add_last(head_file,str0);
            system("cls");
            printf("Added the last\n");
            choice = 0;
            break;
        case 3:
            do
            {
                printf("Enter number of position to add: ");
                scanf("%d",&n);
                getchar();
                if(n>head_file->cnt+1) printf("There are less than %d positions!\n",n);
            } while (n>head_file->cnt+1);
            system("cls");
            printf("Adding into position number %d:\n",n);
            str0 = new_struct();
            add_in_position(head_file,str0,n);
            normalize_id(head_file);
            system("cls");
            printf("Added into the position number %d\n",n);
            choice = 0;

            break;
        case 0:
            system("cls");
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);

}


void add_first(head *head_file, comps *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (comps*)malloc(sizeof(comps));
    temp->prev = NULL;
    temp->next = head_file->first;
    head_file->first->prev = temp;
    head_file->first = temp;
    head_file->cnt += 1;
    temp->id = head_file->cnt;
    temp->data = data;
}


void add_last(head *head_file, comps *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (comps*)malloc(sizeof(comps));
    temp->next = NULL;
    temp->prev = head_file->last;
    head_file->last->next = temp;
    head_file->last = temp;
    head_file->cnt += 1;
    temp->id = head_file->cnt;
    temp->data = data;
}


void add_in_position(head *head_file, comps *data, int n)
{
    node *temp;
    node *temp2;
    int i;

    if(n==1) add_first(head_file,data);
    else if(n==head_file->cnt+1) add_last(head_file,data);
    else
    {
        temp2 = head_file->first;
        temp = (node *)malloc(sizeof(node));
        temp->data = (comps*)malloc(sizeof(comps));

        for(i=1;i<n;i++) temp2 = temp2->next;
        temp->next = temp2;
        temp->prev = temp2->prev;
        temp2->prev->next = temp;
        temp2->prev = temp;
        head_file->cnt += 1;
        temp->id = head_file->cnt;
        temp->data = data;
    }

}
