#include "file_operations.h"



void open_csv(head* clipboard)
{
    int slen;
    FILE *file;
    char filename[32];
    head *head_file=NULL;

    head_file = create_head();
    printf("Enter name of file to open: ");
    fgets(filename,31,stdin);
    slen=strlen(filename);
    filename[slen-1]='\0';

    file = fopen(filename,"r");
    while(!file)
    {
        printf("File was not found.\n");
		printf("Enter name of file to open: ");
        fgets(filename,31,stdin);
        slen=strlen(filename);
        filename[slen-1]='\0';
        file = fopen(filename,"r");
    }

    fseek(file, 0, SEEK_END);
    if(ftell(file)!=0)
    {
        fseek(file, 0, SEEK_SET);
        read_from_csv(file,head_file);
    }
    fclose(file);

    //FUNC FROM DATA_OPERATIONS
    //probably menu with: add,save,change,delete,sort,search
    //OTHER FUNCS
    menu(clipboard,head_file,filename); //Operations with data


    /*if((head2->cnt) == 1) free_head(head2);
    else if((head2->cnt) > 1) free_list(head2);        //LATER, mb in some func
    else if ((head2->cnt) == 0) free(head2);*/


}


void read_from_csv(FILE* file, head* head_file)
{
    int slen,i,number_of_lines;
    char **s2=NULL;
    comps *s3=NULL;
    char s1[256];
    char sep;
    sep=';';

    number_of_lines=0;
    while((fgets(s1,256,file))!=NULL) number_of_lines++;
    rewind(file);
    fgets(s1,256,file);
    slen=strlen(s1);
    s1[slen-1]='\0';
    slen=strlen(s1);

    s2=simple_split(s1,slen,sep);
    s3 = struct_fill(s2);
    create_node(s3,head_file); //Creating first node

      //Splitting other strings, creating//
      //structures and making list      //
    for(i=0;i<number_of_lines-1;i++)
    {
        fgets(s1,256,file);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);

        s2=simple_split(s1,slen,sep);
        s3 = struct_fill(s2);
        add_last(head_file,s3); //REPLACE
    }

}


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
    printf("File %s was created.\n\n", filename);
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
    system("cls");
    if (remove(filename)==0) printf("File %s was deleted.\n\n",filename);
    else printf("File %s wasn't deleted.\n\n",filename);
}
