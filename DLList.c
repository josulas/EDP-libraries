#include "DLList.h"


void actualize_DL(list_DL *self){
    unsigned type;
    node_DL_p actual;
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


void freeNode_DL(node_DL_p to_free){
    freeData(&to_free->node_data);
    free(to_free);
}


unsigned add_DL(list_DL *self, data input){
    node_DL_p new;
    new = calloc(1, sizeof(node_DL));
    if(!new) return 1;
    if(!self->length) self->type = input.type;
    else if(self->type != 10 && input.type != self->type) self->type = 10;
    new->node_data = input;
    if(!self->length) {
        self->first = new;
        self->last = new;
    }
    else{
        self->first->prev = new;
        new->next = self->first;
        self->first = new;
    }
    self->length++;
    return 0;
}


unsigned append_DL(list_DL *self, data input){
    node_DL_p new;
    if(!self->length) return add_DL(self, input);
    new = calloc(1, sizeof(node_DL));
    if(!new) return 1;
    new->node_data = input;
    if(!self->length) self->type = input.type;
    else if(self->type != 10 && input.type != self->type) self->type = 10;
    self->last->next = new;
    new->prev = self->last;
    self->last = new;
    self->length++;
    return 0;
}


unsigned insert_DL(list_DL *self, size_t index, data input){
    node_DL_p aux, new;
    register size_t i;
    if(!index) return add_DL(self, input);
    if (index > self->length) return 2;
    if(index == self->length) return append_DL(self, input);
    new = calloc(1, sizeof(node_DL));
    if(!new) return 1;
    new->node_data = input;
    if(self->type != 10 && input.type != self->type) self->type = 10;
    aux = self->first;
    for(i = 0; i < index; i++){
        aux = aux->next;
    }
    aux->prev->next = new;
    new->prev = aux->prev;
    new->next = aux;
    aux->prev = new;
    self->length++;
    return 0;
}


void removeFirst_DL(list_DL *self){
    node_DL_p aux;
    if(self->first){
        if(self->first->next){
            aux = self->first;
            self->first = aux->next;
            aux->next->prev = NULL;
            freeNode_DL(aux);
        }
        else freeNode_DL(self->first);
        self->length--;
    }
    if(self->type == 10) actualize_DL(self);
}


void pop_DL(list_DL *self){
    node_DL_p aux;
    if(self->last){
        if(self->last->prev){
            aux = self->last;
            self->last = aux->prev;
            self->last->next = NULL;
            freeNode_DL(aux);
        }
        else freeNode_DL(self->last);
        self->length--;
    }
    if(self->type == 10) actualize_DL(self);
}


unsigned deleteNode_DL(list_DL *self, size_t index){
    node_DL_p aux;
    register size_t i;
    if (index >= self->length) return 2;
    if(!index) {
        removeFirst_DL(self);
        return 0;
    }
    if(index == self->length - 1){
        pop_DL(self);
        return 0;
    }
    aux = self->first;
    for(i = 0; i < index; i++){
        aux = aux->next;
    }
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    freeNode_DL(aux);
    self->length--;
    if(self->type == 10) actualize_DL(self);
    return 0;
}


size_t *getIndex_DL(list_DL *self, data input){
    register size_t i;
    static size_t index;
    node_DL_p actual;
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


data *getElement_DL(list_DL *self, size_t index){
    node_DL_p aux;
    register size_t i;
    static data new;
    if(index >= self->length) return NULL;
    if(index < self->length / 2){
        aux = self->first;
        for(i = 0; i < index; i++) aux = aux->next;
    }
    else{
        aux = self->last;
        for(i = self->length - 1; i > index; i--) aux = aux->prev;
    }
    new = aux->node_data;
    return &new;
}


unsigned swapNodes_DL(list_DL *self, size_t index1, size_t index2){
    node_DL_p aux1, aux2, aux3, aux4, aux5, aux6;
    register size_t i;
    if(index1 >= self->length || index2 >= self->length) return 2;
    if(index1 == index2) return 0;
    if(index1 < self->length / 2){
        aux1 = self->first;
        for(i = 0; i < index1; i++) aux1 = aux1->next;
    }
    else{
        aux1 = self->last;
        for(i = self->length - 1; i > index1; i--) aux1 = aux1->prev;
    }
    if(index2 < self->length / 2){
        aux2 = self->first;
        for(i = 0; i < index2; i++) aux2 = aux2->next;
    }
    else{
        aux2 = self->last;
        for(i = self->length - 1; i > index2; i--) aux2 = aux2->prev;
    }
    aux3 = aux1->next;
    aux4 = aux1->prev;
    aux5 = aux2->next;
    aux6 = aux2->prev;
    if(index1 - index2 == 1) {
        aux2->next = aux3;
        aux2->prev = aux1;
        aux1->next = aux2;
        aux1->prev = aux6;
        if(!index2) self->first = aux1;
        else aux6->next = aux1;
        if(index1 == self->length - 1) self->last = aux2;
        else aux3->prev = aux2;
    }
    else if(index2 - index1 == 1) {
        aux2->next = aux1;
        aux2->prev = aux4;
        aux1->next = aux5;
        aux1->prev = aux2;
        if(!index1) self->first = aux2;
        else aux4->next = aux2;
        if(index2 == self->length - 1) self->last = aux1;
        else aux5->prev = aux1;
    }
    else{
        aux1->next = aux5;
        aux1->prev = aux6;
        aux2->next = aux3;
        aux2->prev = aux4;
        if(index1) aux4->next = aux2;
        else self->first = aux2;
        if(index1 != self->length - 1) aux3->prev = aux2;
        else self->last = aux2;
        if(index2) aux6->next = aux1;
        else self->first = aux1;
        if(index2 != self->length - 1) aux5->prev = aux1;
        else self->last = aux1;
    }
    return 0;
}


unsigned modifyNode_DL(list_DL *self, size_t index, data input){
    if(deleteNode_DL(self, index) == 2) return  2;
    return insert_DL(self, index, input);
}


void clear_DL(list_DL *self){
    while(self->length){
        removeFirst_DL(self);
    }
}


void printList_DL(list_DL *to_show, unsigned reverse){
    node_DL_p actual;
    register size_t i;
    printf("[");
    if(to_show->length){
        if(reverse){
            actual = to_show->last;
            for(i = 0; i < to_show->length - 1; i++){
                printData(&actual->node_data);
                printf(", ");
                actual = actual->prev;
            }
        }
        else {
            actual = to_show->first;
            for(i = 0; i < to_show->length - 1; i++){
                printData(&actual->node_data);
                printf(", ");
                actual = actual->next;
            }
        }
        printData(&actual->node_data);
    }
    printf("]\n");
}
