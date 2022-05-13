#include "menu.h"

unsigned int confirmation(){
    char ch, *aux;
    unsigned valid;
    do{
        printf("Are you sure (Y/N): ");
        aux = inputShortString(1, &valid);
        ch = aux[0];
        if (!valid || (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')) puts("Type only 'Y' or 'N'.");
        free(aux);
    } while (!valid || (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N'));
    if(ch == 'y' || ch == 'Y') return 1;
    return 0;
}


unsigned int menu(char *message, unsigned int number_of_options){
    long unsigned number;
    puts("The options are:");
    puts(message);
    do{
        printf("Enter your choice: ");
        number = inputLongUnsigned();
        if(number < 1 || number > number_of_options) puts("You must input a valid option.");
    } while(number < 1 || number > number_of_options);
    return (unsigned) number;
}
