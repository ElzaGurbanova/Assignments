#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void function(char *source, char *integers, char *nonIntegers)
{
    int i = 0;
	int n = 0;    // for intArr
	int k = 0;    // for nonIntArr

    for( ; source[i] != '\0'; i++){
        if(source[i] < 58 && source[i] > 47){
            integers[n] = source[i];
            n++;
        }else{
            nonIntegers[k] = source[i];
            k++;
        }
        integers[n] = '\0';
        nonIntegers[k] = '\0';
    }
}

int main(){

    char source[] = "169132726abcdD EF98*&_";
    char integers[256];
    char nonIntegers[256];

    function(source, integers, nonIntegers);
    printf("source string:%s\n", source);
    printf("integer string:%s\n", integers);
    printf("noninteger string:%s\n", nonIntegers);

    return 0;}
