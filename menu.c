#include "menu.h"

unsigned int confirmation(){
    char *choice, ch;
    do{
    printf("Are you sure (Y/N): ");
    choice = inputString(stdin, 1);
    ch = choice[0];
    if (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') puts("Type only 'Y' or 'N'.");
    } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
    free(choice);
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
