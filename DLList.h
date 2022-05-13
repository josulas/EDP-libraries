#ifndef DL_LIST_H
#define DL_LIST_H

#include <stdlib.h>
#include "datatype.h"

typedef struct node_DL node_DL;
typedef node_DL* node_DL_p;
typedef struct list_DL list_DL;


struct node_DL{
    node_DL_p prev;
    data node_data;
    node_DL_p next;
};

// The inclusion of functions' memory directions is only conceptual
struct list_DL{
    node_DL_p first;
    node_DL_p last;
    size_t length;
    /* 0 is for default or char
     * 1 is for integer
     * 2 is for rational number
     * 10 is non-uniform
     * */
    unsigned type;
    //"Methods" list
    unsigned (*add)(list_DL *, data);
    unsigned (*append)(list_DL *, data);
    unsigned (*insert)(list_DL *, size_t, data);
    void (*removeFirst)(list_DL *);
    void (*pop)(list_DL *);
    unsigned (*deleteNode)(list_DL *, size_t);
    size_t *(*getIndex)(list_DL *, data);
    data *(*getElement)(list_DL *, size_t);
    unsigned (*swap)(list_DL *, size_t, size_t);
    unsigned (*modifyNode)(list_DL*, size_t, data);
    void (*clear)(list_DL *);
};

void actualize_DL(list_DL *self);
void freeNode_DL(node_DL_p to_free);
unsigned add_DL(list_DL *self, data input);
unsigned append_DL(list_DL *self, data input);
unsigned insert_DL(list_DL *self, size_t index, data input);
void removeFirst_DL(list_DL *self);
void pop_DL(list_DL *self);
unsigned deleteNode_DL(list_DL *self, size_t index);
size_t *getIndex_DL(list_DL *self, data input);
data *getElement_DL(list_DL *self, size_t index);
unsigned swapNodes_DL(list_DL *self, size_t index1, size_t index2);
unsigned modifyNode_DL(list_DL *self, size_t index, data input);
void clear_DL(list_DL *self);
void printList_DL(list_DL *to_show, unsigned reverse);

list_DL new_DL_list = {NULL, NULL, 0, 0, &add_DL, &append_DL, &insert_DL,
                       &removeFirst_DL, &pop_DL, &deleteNode_DL,
                       getIndex_DL, getElement_DL, &swapNodes_DL, &modifyNode_DL,
                       &clear_DL};

#include "DLList.c"

#endif //DL_LIST_H
