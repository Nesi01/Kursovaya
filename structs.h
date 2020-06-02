#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct bike_components {
    char *name;
    char *type;
    int year;
    float cost;
    int reviews;
    float rating;
};
typedef struct bike_components comps;


struct node{

    int id;
    comps *data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;


struct head {
    int cnt;
    struct node *first;
    struct node *last;
};
typedef struct head head;


#endif // STRUCTS_H_INCLUDED
