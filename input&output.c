# include "input&output.h"


void flush(FILE *ptr){
    char ch;
    while( (ch = (char) fgetc(ptr))!='\n' && ch != EOF);
}


char *inputShortString(size_t len, unsigned *verifier){
    char *string;
    char ch;
    register size_t i = 0;
    *verifier = 1;
    if(!len) return NULL;
    string = calloc(len + 1, sizeof(char));
    if(!string) return NULL;
    while((ch = getchar()) != '\n' && i++ < len) string[i-1] = ch;
    if(ch != '\n') flush(stdin);
    if(ch != '\n') *verifier = 0;
    return string;
}


// This function was originally taken from stackoverflow. It takes from a *FILE character by character.
char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = (char*) calloc(size, sizeof(*str));
    //Error control
    if(!str) return str;
    // Max size is 1 MiB
    while(EOF != (ch = fgetc(fp)) && ch != '\n' && len < MiB - 1){
        str[len++] = (char) ch;
        if(len == size){
            str = (char*) realloc(str, sizeof(*str) * (size += 16));
            if(!str)return str;
        }
    }
    if(ch != '\n') flush(fp);
    str[len++] = '\0';
    // The ++ helps to avoid some errors when the input is void.
    return (char*) realloc(str, sizeof(*str) * ++len);
}


long int inputLong(){
    char *string, *aux = NULL;
    unsigned valid;
    long int number;
    do{
        if(aux) free(aux);
        aux = inputShortString(MAX_LONG_CHARACTERS, &valid);
        if(!aux) return 0;
        number = strtol(aux, &string, 10);
        if(strlen(string)) {
            printf("Please input a valid integer: ");
        }
        else if(!valid) printf("The integer is too long. Please input a valid integer: ");
    } while(!valid || strlen(string));
    free(aux);
    return number;
}


long unsigned inputLongUnsigned(){
    char *string, *aux = NULL;
    long unsigned number;
    unsigned valid;
    do{
        if(aux) free(aux);
        aux = inputShortString(MAX_U_LONG_CHARACTERS, &valid);
        if(!aux) return 0;
        number = strtoul(aux, &string, 10);
        if(strlen(string)) {
            printf("Please input a valid non-negative integer: ");
        }
        else if(!valid) printf("The integer is too long. Please input a valid non-negative integer: ");
    } while(!valid || strlen(string));
    free(aux);
    return number;
}

// Size_t is only unsigned long long in x64
size_t inputSize_t(){
    char *string, *aux = NULL;
    size_t number;
    unsigned valid;
    do{
        if(aux) free(aux);
        aux = inputShortString(MAX_U_LONG_LONG_CHARACTERS, &valid);
        if(!aux) return 0;
        number = strtoull(aux, &string, 10);
        if(strlen(string)) {
            printf("Please input a valid non-negative integer: ");
        }
        else if(!valid) printf("The integer is too long. Please input a valid non-negative integer: ");
    } while(!valid || strlen(string));
    free(aux);
    return number;
}


double inputDouble(){
    char *string, *aux = NULL;
    double number;
    unsigned valid;
    do{
        if(aux) free(aux);
        aux = inputShortString(MAX_DOUBLE_CHARACTERS, &valid);
        if(!aux) return 0;
        number = strtod(aux, &string);
        if(strlen(string)) {
            printf("Please input a valid number: ");
        }
        else if(!valid) printf("The number is too long. Please input a valid number: ");
    } while(!valid || strlen(string));
    free(aux);
    return number;
}
