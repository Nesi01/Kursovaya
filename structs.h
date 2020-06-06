#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct bike_components {
    char *name;         //Name of the component
    char *type;         //Type of the component (Wheel,frame,fork etc)
    int year;           //Model year
    float cost;         //Price
    int reviews;        //Amount of reviews
    float rating;       //Rating based on these reviews (from 0 to 5)
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
    int cnt;        //Amount of nodes in the list
    struct node *first;
    struct node *last;
};
typedef struct head head;


#endif // STRUCTS_H_INCLUDED
