#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "data_operations.h"
#include "list.h"
#include "struct_csv.h"
#include "structs.h"


int main()
{
    int choice;
    head *clipboard=NULL; //to copy and paste through the files

    clipboard = create_head();

    do
    {
        printf("ALL CSV FILES:\n");
        system("dir /b *.csv");         //Outputs names of files
        printf("\n\n| |      MENU     |\n");
        printf("+-+---------------+\n");
        printf("|1| - Open file   |\n");
        printf("|2| - Create file |\n");
        printf("|3| - Delete file |\n");
        printf("|0| - Exit        |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:     //Open file
            open_csv(clipboard);
            break;
        case 2:     //Create file
            system("cls");
            create_file();
            break;
        case 3:     //Delete file
            //system("cls");
            delete_file();
            break;
        case 0:
            system("cls");
            printf("EXIT\n");
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);

    free_at_all(clipboard);

    return 0;
}
