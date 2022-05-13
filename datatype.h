#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Error codes are the same in both lists
 * 0 is for no error
 * 1 is for memory alloc error
 * 2 is for index out of range
*/

// WARNING. If saving a string, it must be allocated dynamically
typedef struct data{
    void *ptr;
    //The element can only store 1 type of data. 0 for char, 1 for integer, 2 for float, 3 for string.
    unsigned type;
}data;

//This function takes 2 arguments. One is the identifier, the other is the data.
data newData(unsigned identifier, ...);
int compareData(data *data1, data *data2);
void printData(data *my_data);
void freeData(data *my_data);

#include "datatype.c"

#endif //DATATYPE_H
