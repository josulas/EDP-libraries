#include "SLList.h"


//This function has not a utility yet. It will help when trying to sort the list
void actualize_SL(list_SL *self){
    unsigned type;
    node_SL_p actual;
    unsigned uniform = 1;
    register size_t i;
    if(!self->length) self->type = 0;
    else if(self->length == 1) self->type = self->first->node_data.type;
    else {
        actual = self->first;
        type = actual->node_data.type;
        for(i = 1; i < self->length; i++){
            actual = actual->next;
            if(type != actual->node_data.type){
                uniform = 0;
                break;
            }
        }
        if(uniform) self->type = type;
    }
}


void freeNode_SL(node_SL_p to_free){
    freeData(&to_free->node_data);
    free(to_free);
}


unsigned add_SL(list_SL *self, data input){
    node_SL_p new;
    new = calloc(1, sizeof(node_SL));
    if(!new) return 1;
    if(!self->length) self->type = input.type;
    else if(self->type != 10 && input.type != self->type) self->type = 10;
    new->node_data = input;
    new->next = self->first;
    self->first = new;
    self->length++;
    return 0;
}


unsigned append_SL(list_SL *self, data input){
    node_SL_p new, actual;
    new = calloc(1, sizeof(node_SL));
    if(!new) return 1;
    new->node_data = input;
    if(!self->length) self->type = input.type;
    else if(self->type != 10 && input.type != self->type) self->type = 10;
    if(!self->first) self->first = new;
    else {
        actual = self->first;
        while (actual->next) actual = actual->next;
        actual->next = new;
    }
    self->length++;
    return 0;
}


unsigned insert_SL(list_SL *self, size_t index, data input){
    node_SL_p aux1, aux2, new;
    register size_t i;
    if(!index) return add_SL(self, input);
    if (index > self->length) return 2;
    if(index == self->length) return append_SL(self, input);
    new = calloc(1, sizeof(node_SL));
    if(!new) return 1;
    if(self->type != 10 && input.type != self->type) self->type = 10;
    new->node_data = input;
    aux1 = self->first;
    for(i = 0; i < index; i++){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    aux2->next = new;
    new->next = aux1;
    self->length++;
    return 0;
}


void removeFirst_SL(list_SL *self){
    node_SL_p aux;
    if(self->first){
        if(self->first->next){
            aux = self->first;
            self->first = aux->next;
            freeNode_SL(aux);
        }
        else freeNode_SL(self->first);
        self->length--;
    }
    if(self->type == 10) actualize_SL(self);
}


void pop_SL(list_SL *self){
    node_SL_p actual, aux;
    if(self->first){
        actual = self->first;
        while(actual->next) {
            aux = actual;
            actual = actual->next;
        }
        freeNode_SL(actual);
        if(aux) aux->next = NULL;
        else self->first = NULL;
        self->length--;
    }
    if(self->type == 10) actualize_SL(self);
}


unsigned deleteNode_SL(list_SL *self, size_t index){
    node_SL_p aux1, aux2;
    register size_t i;
    if (index >= self->length) return 2;
    if(!index) {
        removeFirst_SL(self);
        return 0;
    }
    if(index == self->length - 1){
        pop_SL(self);
        return 0;
    }
    aux1 = self->first;
    for(i = 0; i < index; i++){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    aux2->next = aux1->next;
    freeNode_SL(aux1);
    self->length--;
    if(self->type == 10) actualize_SL(self);
    return 0;
}


size_t *getIndex_SL(list_SL *self, data input){
    register size_t i;
    static size_t index;
    node_SL_p actual;
    if(!self->length) return NULL;
    actual = self->first;
    for(i = 0; i < self->length; i++){
        if (!compareData(&actual->node_data, &input)){
            index = i;
            return &index;
        }
        actual = actual->next;
    }
    return NULL;
}


data *getElement_SL(list_SL *self, size_t index){
    node_SL_p aux;
    register size_t i;
    static data new;
    if(index >= self->length) return NULL;
    aux = self->first;
    for(i = 0; i < index; i++) aux = aux->next;
    new = aux->node_data;
    return &new;
}


unsigned swapNodes_SL(list_SL *self, size_t index1, size_t index2){
    node_SL_p aux1, aux2, aux3, aux4, aux5;
    register size_t i;
    if(index1 >= self->length || index2 >= self->length) return 2;
    if(index1 == index2) return 0;
    aux1 = self->first;
    for(i = 0; i < index1; i++) {
        aux3 = aux1;
        aux1 = aux1->next;
    }
    aux2 = self->first;
    for(i = 0; i < index2; i++) {
        aux4 = aux2;
        aux2 = aux2->next;
    }
    aux5 = aux2->next;
    if (index1 - index2 == 1){
        if(!index2) self->first = aux1;
        else aux4->next = aux1;
        aux2->next = aux1->next;
        aux1->next = aux2;
    }
    else if (index2 - index1 == 1){
        if(!index1) self->first = aux2;
        else aux3->next = aux2;
        aux1->next = aux2->next;
        aux2->next = aux1;
    }
    else{
        if(!index1) self->first = aux2;
        else aux3->next = aux2;
        aux2->next = aux1->next;
        if(!index2) self->first = aux1;
        else aux4->next = aux1;
        aux1->next = aux5;
    }
    return 0;
}


unsigned modifyNode_SL(list_SL *self, size_t index, data input){
    if(deleteNode_SL(self, index) == 2) return 2;
    return insert_SL(self, index, input);
}


void clear_SL(list_SL *self){
    while(self->length){
        removeFirst_SL(self);
    }
}


void printList_SL(list_SL *to_show){
    node_SL_p actual;
    register size_t i;
    printf("[");
    if(to_show->length){
        actual = to_show->first;
        for(i = 0; i < to_show->length - 1; i++){
            printData(&actual->node_data);
            printf(", ");
            actual = actual->next;
        }
        printData(&actual->node_data);
    }
    printf("]\n");
}
