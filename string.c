#include "string.h"

size_t strLen(const char *string){
    size_t length = 0;
    while (string[length]){
        length++;
    }
    return length;
}


void stringCopy(char *receptor, const char *string){
    size_t i;
    for(i = 0; i <= strLen(string); i++) receptor[i] = string[i];
}


unsigned strComp(const char *string1, const char *string2){
    size_t len1 = strLen(string1), len2 = strLen(string2), min, i;
    if(len1 < len2) min = len1; else min = len2;
    for(i = 0; i < min; i++){
        if(string1[i] > string2[i]) return 1;
        if(string1[i] < string2[i]) return -1;
    }
    if(len1 > len2) return 1;
    if(len1 < len2) return -1;
    return 0;
}


unsigned isAlpha(const char ch){
    return(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));
}


unsigned isDigit(const char ch){
    return('0' <= ch && ch <= '9');
}


size_t wordCounter(const char *string){
    size_t counter = 0, pos = 0;
    char actual, prev = ' ';
    while(string[pos] != '\0'){
        actual = string[pos++];
        if(isAlpha(prev) && !isAlpha(actual)) counter++;
        prev = actual;
    }
    if(isAlpha(actual)) counter++;
    return counter;
}


char *concatenate(char *string_1, char *string_2, unsigned total_strings, ...){
    char *receptor;
    va_list args;
    size_t size = 0, length = 0, count = 0;
    char *actual;
    unsigned int i;
    
    size += strLen(string_1) + strLen(string_2);
    va_start(args, total_strings);
    for(i = 0; i < total_strings - 2; i++) size += strLen(va_arg(args, char*));
    
    receptor = (char *) calloc(size + 1, sizeof(char));
    if(!receptor) return 0;
    
    while (string_1[count] != 0) {
        receptor[length++] = string_1[count++];
    }
    count = 0;
    
    while (string_2[count] != 0) {
        receptor[length++] = string_2[count++];
    }
    count = 0;
    
    va_start(args, total_strings);
    for(i = 0; i < total_strings - 2; i++){
        actual = va_arg(args, char*);
        while (actual[count] != 0) {
            receptor[length++] = actual[count++];
        }
        count = 0;
    }
    va_end(args);
    receptor[length] = 0;
    return receptor;
}


long int isSubstring(const char sub[], const char string[]){
    size_t len_sub = strLen(sub), len_string = strLen(string);
    unsigned val;
    long int pos;
    if (len_sub > len_string) return -1;
    for (int i = 0; i <= len_string - len_sub; i++){
        val = 1;
        pos = i;
        for (int j = 0; j < len_sub; j++){
            if (string[i + j] != sub[j]){
                val = 0;
                break;
            }
        }
        if (val) return pos;
    }
    return -1;
}


void strUpr(char *string){
    int i;
    for (i = 0;string[i] != '\0'; i++){
        if (('a' <= string[i]) && (string[i] <= 'z')) {
            string[i] -= 32;
        }
    }
}

void strLwr(char *string){
    int i;
    for (i = 0;string[i] != '\0'; i++){
        if (('A' <= string[i]) && (string[i] <= 'Z')) {
            string[i] += 32;
        }
    }
}


unsigned isPalindrome(char *string){
    size_t len = strLen(string);
    register size_t i;
    for(i = 0; i < len / 2; i++) if(string[i] != string[len - 1 - i]) return 0;
    return 1;
}
