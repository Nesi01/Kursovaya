#include "data_operations.h"


void menu(head* clipboard,head* head_file,char* filename)
{
    int choice;

    do
    {
        system("cls");
        printf("    File %s\n",filename);
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

    } while(choice!=0);

}
