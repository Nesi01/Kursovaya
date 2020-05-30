#include "struct_csv.h"



char **simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else
        {

            for(i=0;i<count;i++)
            {
                free(str_array[i]);
                str_array[i]=NULL;
            }
            free(str_array);
            str_array = NULL;
        }
     }
     return str_array;
}


comps *struct_fill(char **str)
{
    comps *str0=NULL;

    str0=(comps*)malloc(sizeof(comps));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->type=str[1];
        str0->year=atoi(str[2]);
        str0->cost=atof(str[3]);
        str0->reviews=atoi(str[4]);
        str0->rating=atof(str[5]);
    }
    return str0;
}

comps *new_struct()
{
    comps *str0=NULL;

    str0=(comps*)malloc(sizeof(comps));
    str0 -> name = (char*)malloc(sizeof(char)*32);
    str0 -> type = (char*)malloc(sizeof(char)*32);
    if(str0!=NULL)
    {
        printf("Enter name: ");
        fgets((*str0).name,64,stdin);
        printf("Enter type: ");
        fgets((*str0).type,32,stdin);
        printf("Enter year: ");
        scanf("%d",&(*str0).year);
        printf("Enter price: ");
        scanf("%f",&(*str0).cost);
        printf("Enter amount of reviews: ");
        scanf("%d",&(*str0).reviews);
        printf("Enter rating: ");
        scanf("%f",&(*str0).rating);
        str0->name[strlen(str0->name)-1]='\0';
        str0->type[strlen(str0->type)-1]='\0';
    }
    return str0;
}


void print_header()
{
    printf("|%30s |%10s |%5s |%9s |%4s|%5s|\n","Name of the bike component","Type","Year","Price(in pounds)","Reviews","Rating");
    printf("+-------------------------------+-----------+------+-----------------+-------+------+\n");
}
