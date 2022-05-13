#include "intSLList.h"

data newInteger(long integer){
    return newData(1, integer);
}


long max(list_SL *number_list){
    register size_t i;
    data max;
    register node_SL_p actual;
    if(!number_list->length) return 0;
    actual = number_list->first;
    max = actual->node_data;
    for(i = 1; i < number_list->length; i++){
        actual = actual->next;
        if(compareData(&actual->node_data, &max) == 1) max = actual->node_data;
    }
    return *((long*)max.ptr);
}


double product(list_SL *number_list){
    register double product = 1;
    register size_t i;
    node_SL_p actual;
    if(!number_list->length) return 0;
    actual = number_list->first;
    product *= (double ) *((long*)actual->node_data.ptr);
    for(i = 1; i < number_list->length; i++){
        actual = actual->next;
        product *= (double) *((long*)actual->node_data.ptr);
        if(!product) break;
    }
    return product;
}


double median(list_SL *number_list){
    register long sum = 0;
    register size_t i;
    node_SL_p actual;
    if(!number_list->length) return 0;
    actual = number_list->first;
    sum += *((long*)actual->node_data.ptr);
    for(i = 1; i < number_list->length; i++){
        actual = actual->next;
        sum += *((long*)actual->node_data.ptr);
    }
    return (double) sum / ( (double) number_list->length * 1.0);
}


double variance(list_SL *number_list, double median){
    register double sum = 0;
    register size_t i;
    node_SL_p actual;
    if(!number_list->length) return 0;
    actual = number_list->first;
    sum += pow((double) *((long*)actual->node_data.ptr) - median, 2);
    for(i = 1; i < number_list->length; i++){
        actual = actual->next;
        sum += pow((double) *((long*)actual->node_data.ptr) - median, 2);
    }
    return (double) sum / ( (double) number_list->length * 1.0);
}


double standardDeviation(double variance){
    return sqrt(variance);
}


unsigned frequencies(list_SL *number_list, list_SL *freq, list_SL *freq_elements){
    register size_t i, j;
    size_t *pos;
    node_SL_p actual, aux;
    for (i = 0; i < number_list->length; i++){
        if(!i) actual = number_list->first;
        else actual = actual->next;
        pos = freq->getIndex(freq_elements, actual->node_data);
        if(pos) {
            aux = freq->first;
            for(j = 0; j < *pos; j++) aux = aux->next;
            *((long*)aux->node_data.ptr) += 1;
        }
        else{
            if(freq->add(freq, newInteger(1))) return 1;
            if(freq_elements->add(freq_elements, newInteger(*((int*)actual->node_data.ptr)))) return 1;
        }
    }
    return 0;
}
