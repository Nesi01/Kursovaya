#include "data_operations.h"


void menu(head* clipboard,head* head_file,char* filename)
{
    int choice, n;
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
            printf("|2| - Edit                    |\n");
            printf("|3| - Search                  |\n");    //SKIPPED
            printf("|4| - Sort                    |\n");    //SKIPPED
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
                normalize_id(head_file); //Making right id order
                break;
            case 2:
                do
                {
                    printf("Enter number of node to edit: ");
                    scanf("%d",&n);
                    getchar();
                    if(n>head_file->cnt) printf("There are less than %d positions!\n",n);
                } while (n>head_file->cnt);
                system("cls");
                edit_info(n,head_file);
                break;
            case 3:
                system("cls");
                search_info(head_file);

                break;
            case 4:
                system("cls");
                sort_info(head_file);

                break;
            case 5:
                system("cls");
                delete_info(head_file);
                normalize_id(head_file);
                break;
            case 6:
                copy_info(clipboard,head_file);
                system("cls");
                printf("Information copied\n");
                break;
            case 7:
                system("cls");
                if(clipboard->cnt!=0) paste_info(clipboard,head_file);
                else printf("Clipboard is empty\n");
                break;
            case 8:
                system("cls");
                save_info(head_file,filename);
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
                system("cls");
                if(clipboard->cnt!=0) paste_info(clipboard,head_file);
                else printf("Clipboard is empty\n");

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


void edit_info(int n, head *head_file)
{
    node *temp;
    int choice, i;

    temp = head_file->first;
    for(i=1;i<n;i++) temp = temp->next;
    do
    {
        //Node output
        print_header();
        printf("|%3d|%30s |%10s |%5d |%16.2f |%6d |%5.1f |\n\n",
        temp->id,
        temp->data->name,
        temp->data->type,
        temp->data->year,
        temp->data->cost,
        temp->data->reviews,
        temp->data->rating);

        printf("| | What data do you want to edit? |\n");
        printf("+-+--------------------------------+\n");
        printf("|1| - All data                     |\n");
        printf("|2| - Name                         |\n");
        printf("|3| - Type                         |\n");
        printf("|4| - Year                         |\n");
        printf("|5| - Price                        |\n");
        printf("|6| - Reviews                      |\n");
        printf("|7| - Rating                       |\n");
        printf("|0| - Cancel                       |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            printf("Enter name: ");
            fgets(temp->data->name,64,stdin);
            printf("Enter type: ");
            fgets(temp->data->type,32,stdin);
            printf("Enter year: ");
            scanf("%d",&temp->data->year);
            printf("Enter price: ");
            scanf("%f",&temp->data->cost);
            printf("Enter amount of reviews: ");
            scanf("%d",&temp->data->reviews);
            printf("Enter rating: ");
            scanf("%f",&temp->data->rating);
            temp->data->name[strlen(temp->data->name)-1]='\0';
            temp->data->type[strlen(temp->data->type)-1]='\0';
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 2:
            system("cls");
            printf("Enter name: ");
            fgets(temp->data->name,64,stdin);
            temp->data->name[strlen(temp->data->name)-1]='\0';
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 3:
            system("cls");
            printf("Enter type: ");
            fgets(temp->data->type,32,stdin);
            temp->data->type[strlen(temp->data->type)-1]='\0';
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 4:
            system("cls");
            printf("Enter year: ");
            scanf("%d",&temp->data->year);
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 5:
            system("cls");
            printf("Enter price: ");
            scanf("%f",&temp->data->cost);
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 6:
            system("cls");
            printf("Enter amount of reviews: ");
            scanf("%d",&temp->data->reviews);
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 7:
            system("cls");
            printf("Enter rating: ");
            scanf("%f",&temp->data->rating);
            choice = 0;
            system("cls");
            printf("Node %d edited.\n",n);
            break;
        case 0:
            system("cls");

            break;
        default:
            system("cls");
            puts("Incorrect input!\n");
            break;
        }
    }while(choice!=0);

}
