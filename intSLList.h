#ifndef INT_SL_LIST_C_H
#define INT_SL_LIST_C_H

#include "SLList.h"
#include <math.h>

data newInteger(long integer);
long max(list_SL *number_list);
double product(list_SL *number_list);
double median(list_SL *number_list);
double variance(list_SL *number_list, double median);
double standardDeviation(double variance);
unsigned frequencies(list_SL *number_list, list_SL *freq, list_SL *freq_elements);

#include "intSLList.c"

#endif //INT_SL_LIST_C_H
