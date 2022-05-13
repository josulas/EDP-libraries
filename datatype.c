#include "datatype.h"


data newData(unsigned identifier, ...){
    data my_data;
    va_list arg;
    my_data.type = identifier;
    char *ch;
    long *i;
    double *f;
    va_start(arg, identifier);
    switch (identifier) {
        case 0:
            ch = calloc(1, sizeof(char));
            *ch = (char) va_arg(arg, int);
            my_data.ptr = ch;
            break;
        case 1:
            i = calloc(1, sizeof(long));
            *i = va_arg(arg, long);
            my_data.ptr = i;
            break;
        case 2:
            f = calloc(1, sizeof(double));
            *f = va_arg(arg, double);
            my_data.ptr = f;
            break;
        case 3:
            my_data.ptr = va_arg(arg, char*);
            break;
        default:;
    }
    va_end(arg);
    return my_data;
}

int compareData(data *data1, data *data2){
    if(data1->type != data2->type) return 2;
    switch (data1->type) {
        case 0:
            if(*((char*) data1->ptr) > *((char*) data2->ptr)) return 1;
            else if (*((char*) data1->ptr) == *((char*) data2->ptr)) return 0;
            else return -1;
        case 1:
            if(*((long*) data1->ptr) > *((long*) data2->ptr)) return 1;
            else if (*((long*) data1->ptr) == *((long*) data2->ptr)) return 0;
            else return -1;
        case 2:
            if(*((double*) data1->ptr) > *((double*) data2->ptr)) return 1;
            else if (*((double*) data1->ptr) == *((double*) data2->ptr)) return 0;
            else return -1;
        case 3:
            return strcmp(((char*) data1->ptr), ((char*) data2->ptr));
        default:;
    }
}

void printData(data *my_data){
    switch (my_data->type) {
        case 0:
            printf("%c", *((char*) my_data->ptr));
            break;
        case 1:
            printf("%ld", *((long*) my_data->ptr));
            break;
        case 2:
            printf("%lf", *((double*) my_data->ptr));
            break;
        case 3:
            printf("%s", ((char*) my_data->ptr));
            break;
        default:;
    }
}


void freeData(data *my_data){
    free(my_data->ptr);
}
