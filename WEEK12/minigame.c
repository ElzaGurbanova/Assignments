#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 250
bool flag = true;

int compare_strings(char a[], char b[]){
    int c = 0;
        while (a[c] == b[c]) {
            if (a[c] == '\0' || b[c] == '\0') break;
            c++;
        }if (a[c] == '\0' && b[c] == '\0') return 0;
        else
            return -1;
}

char *check(char *input, char *passwd, int len){
	char *arr = (char*)malloc(BUF_SIZE * sizeof(char));
	int input_len = 0;

	while (input[input_len] != '\0')
        input_len++;
    
    if (len != input_len) return "%";
    
    for (int i = 0; i < len; i++){
        if (passwd[i] == input[i])
            arr[i] = '+';
        
        else{
            bool flag = false;
            for(int k = 0; k < len; k++){
                if (input[i] == passwd[k]){
                    flag = true;
                    break; 
                }
            }
            arr[i] = (flag ? '!' : '.');
        }
    }
    return arr;
}

        
int main( int argc, char **argv ){

	if (argc < 2){
		fprintf(stderr, "Needs at least one argument\n" );
		exit(1);
	}

	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("Unable to open file!\n");
		exit(1);
	}

	char buf[BUF_SIZE];
    buf[BUF_SIZE-1] = '\0';
    size_t buf_size = sizeof(buf);
    
    char *passwd = (char *)malloc(buf_size*sizeof(int));
    int len, tries;

    fscanf( fp, "%s %d %d", passwd, &len , &tries);
    fclose(fp);

    printf("Welcome to Fallout 3 hacking minigame!\n");
    printf("The passphrase contains %d letters.\n", len);

    for(; tries > 0; ){
    	printf("You have %d tries left: ", tries);
    	char *input = (char *)malloc(50*sizeof(int));
    	char *quit = (char *)malloc(50*sizeof(int));
    	char *feedback = (char *)malloc(BUF_SIZE*sizeof(char));
    	quit = "!quit";
        scanf("%s", input);

        if (compare_strings(input, quit) == 0)
        	break;

        feedback = check(input, passwd, len);
        if (feedback == "%"){                  // this deters the decremention of num of tries
        	printf("Wrong number of characters, try again.\n");
        	continue;   
        }
        for (int i=0; i<len; i++){
        	if (feedback[i] != '+')
        		flag = false;
        }
       
        flag == true ? printf("correct, here's how you did:\n"): printf("incorrect, here's how you did\n");

        printf("%s\n", input);
        printf("%s\n", feedback );

        if (flag == true){
            printf("you win.\n");
            free(input);
        	free(feedback);
            return 0;
        }
        else{
            flag = true;
            if (tries != 1) printf("try again.\n");
            if (tries == 1)
            	printf("\ngame over.\n");
            free(input);
       		free(feedback);
        }
        tries --; 
    }
    free(passwd);
    return 0;
}