#include "file_operations.h"



void create_file()
{
    FILE *file;
    char filename[32];
    int slen;

    printf("Enter name of file to create: ");
    fgets(filename,31,stdin);
    slen=strlen(filename);
    filename[slen-1]='\0';

    file = fopen(filename,"w");
    fclose(file);
    printf("File %s was created.\n", filename);
}



void delete_file()
{
    FILE *file;
    char filename[32];
    int slen;

    printf("Enter name of file to delete: ");
    fgets(filename,31,stdin);
    slen=strlen(filename);
    filename[slen-1]='\0';

    file = fopen(filename,"r");
    while(!file)
    {
        printf("File was not found.\n");
		printf("Enter name of file to delete: ");
        fgets(filename,31,stdin);
        slen=strlen(filename);
        filename[slen-1]='\0';
        file = fopen(filename,"r");
    }
    fclose(file);
    if (remove(filename)==0) printf("File %s was deleted.\n",filename);
    else printf("File %s wasn't deleted.\n",filename);
}
