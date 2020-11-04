#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char data[256];
    struct Node *next;
}node_t;


void printlist(node_t *node)
{
    printf("Queue: ");
    while(node != NULL){
        printf("%s, ", node->data);
        node = node->next;
    }
    printf("\n");
}

void admit(node_t **start)
{
    if (*start == NULL){
        printf("Empty queue.\n");
        return;
    }
    node_t* next_node = (*start)->next;
    printf("%s was admitted\n", (*start)->data);
    free(*start);
	
    *start = next_node;
}

void append(node_t **start, char *key)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    node_t *last = *start;
    strcpy(new_node->data, key);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}


void moveToTail(node_t** start, char *key){
    node_t *temp = (*start), *prev;

    if(temp != NULL && strcmp(temp->data, key) == 0){
        *start = temp->next;
    }else {
        while (temp != NULL && strcmp(temp->data, key) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("There is no such customer.\n");
            return;
        }
        prev->next = temp->next;
    }
    node_t *new_node = (node_t *)malloc(sizeof(node_t*));
    node_t *last = *start;
    strcpy(new_node->data, temp->data);
    new_node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    free(temp);
    temp = NULL;
}


void deleteList(node_t** start)   
{
	node_t* current = *start, *next;

	while (current != NULL){
		next = current -> next;
		free(current);
		current = next;
	}
	*start = NULL;
}

int main(){
	
    char input[256];
    bool quit = 0;
    node_t *head = (node_t *)malloc(sizeof(node_t));
	char name[30];
    for(int i=0; i<5; i++){
		printf("Enter the name of the person in queue: ");
		scanf("%s", name);
		if(i==0){
			strcpy(head->data, name);
			head->next = NULL;
		}
		else{
			append(&head, name);
    }}
	printlist(head);
    while(!quit){
        
		printf("\n");
        printf("Enter a command (q for quit): ");
        scanf("%s", input);
        
		if(strcmp(input, "q") == 0) quit = 1;
        else if(strcmp(input, "admit") == 0) admit(&head);
        else moveToTail(&head, input);
        
        printlist(head);
    }
    deleteList(&head);

    return 0;
}
