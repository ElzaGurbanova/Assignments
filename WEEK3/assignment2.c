#include <stdio.h>

/* Since the provided strings may not be of the same size 
the usage of character pointers is optimum */

void swapStrings(char **destination, char **source);              
														
int main(){												
    char *str1 = "Karabakh";				
    char *str2 = "Azerbaijan";

    printf("str1: %s, str2: %s\n", str1, str2);
    swapStrings(&str1, &str2);
    printf("str1: %s, str2: %s\n", str1, str2);

    return 0;
}

void swapStrings(char **destination, char **source){
    char *temp = *destination;
    *destination = *source;
    *source = temp;
}
