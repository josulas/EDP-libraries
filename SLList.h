#ifndef SL_LIST_H
#define SL_LIST_H

#include <stdlib.h>
#include "datatype.h"

typedef struct node_SL node_SL;
typedef node_SL* node_SL_p;
typedef struct list_SL list_SL;


struct node_SL{
    data node_data;
    node_SL_p next;
};

// The inclusion of functions' memory directions is only conceptual
struct list_SL{
    node_SL_p first;
    size_t length;
    /* 0 is for default or char
     * 1 is for integer
     * 2 is for rational number
     * 3 is for string
     * 10 is non-uniform
     * */
    unsigned type;
    //"Methods" list
    unsigned (*add)(list_SL *, data);
    unsigned (*append)(list_SL *, data);
    unsigned (*insert)(list_SL *, size_t, data);
    void (*removeFirst)(list_SL *);
    void (*pop)(list_SL *);
    unsigned (*deleteNode)(list_SL *, size_t);
    size_t *(*getIndex)(list_SL *, data);
    data *(*getElement)(list_SL *, size_t);
    unsigned (*swap)(list_SL *, size_t, size_t);
    unsigned (*modifyNode)(list_SL *, size_t, data);
    void (*clear)(list_SL *);
};

void actualize_SL(list_SL *self);
void freeNode_SL(node_SL_p to_free);
unsigned add_SL(list_SL *self, data input);
unsigned append_SL(list_SL *self, data input);
unsigned insert_SL(list_SL *self, size_t index, data input);
void removeFirst_SL(list_SL *self);
void pop_SL(list_SL *self);
unsigned deleteNode_SL(list_SL *self, size_t index);
size_t *getIndex_SL(list_SL *self, data input);
data *getElement_SL(list_SL *self, size_t index);
unsigned swapNodes_SL(list_SL *self, size_t index1, size_t index2);
unsigned modifyNode_SL(list_SL *self, size_t index, data input);
void clear_SL(list_SL *self);
void printList_SL(list_SL *to_show);

// This global list incorporates the memory directions. A new list must be created with this in order to use them
list_SL new_SL_list = {NULL, 0, 0, &add_SL, &append_SL, &insert_SL,
                       &removeFirst_SL, &pop_SL, &deleteNode_SL,
                       getIndex_SL, getElement_SL, &swapNodes_SL, &modifyNode_SL,
                       &clear_SL};

#include "SLList.c"

#endif //SL_LIST_H
