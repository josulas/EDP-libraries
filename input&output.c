# include "input&output.h"

char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = (char*) calloc(size, sizeof(*str));
    if(!str) return str;
    // Max size is 1 MB
    while(EOF != (ch = fgetc(fp)) && ch != '\n' && len < 1048575){
        str[len++] = (char) ch;
        if(len == size){
            str = (char*) realloc(str, sizeof(*str) * (size += 16));
            if(!str)return str;
        }
    }
    str[len++] = '\0';

    return (char*) realloc(str, sizeof(*str) * ++len);
}


long int inputLong(){
    char *string, *aux;
    long int number;
    do{
        aux = inputString(stdin, 10);
        number = strtol(aux, &string, 10);
        if(strLen(string)) printf("Please input a valid integer: ");
    } while (strLen(string));
    free(aux);
    return number;
}


long unsigned inputLongUnsigned(){
    char *string, *aux;
    long unsigned number;
    do{
        aux = inputString(stdin, 10);
        number = strtoul(aux, &string, 10);
        if(strLen(string)) printf("Please input a valid integer: ");
    } while (strLen(string));
    free(aux);
    return number;
}


size_t inputSize_t(){
    char *string, *aux;
    size_t number;
    do{
        aux = inputString(stdin, 10);
        number = strtoull(aux, &string, 10);
        if(strLen(string)) printf("Please input a valid integer: ");
    } while (strLen(string));
    free(aux);
    return number;
}


double inputDouble(){
    char *string, *aux;
    double number;
    do{
        aux = inputString(stdin, 10);
        number = strtof(aux, &string);
        if(strLen(string)) printf("Please input a valid number: ");
    } while (strLen(string));
    free(aux);
    return number;
}
