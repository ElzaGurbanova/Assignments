#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    bool swapped;
    struct Node * next;
}; 

void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref;
    new_node->swapped = 0;
    new_node->data  = new_data; 
    new_node->next = NULL; 

    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
}

void printList(struct Node* iter)
{
	while (iter!= NULL)
	{
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}

void swapNodes(struct Node** head, int swap_data){
    struct Node *first = *head;
    struct Node *prev1 = NULL;
    while (first && first->data != swap_data){
        prev1 = first;
        first = first->next;
    }
    struct Node *second = first->next;
    struct Node *prev2 = first;
    if (first == NULL || second == NULL || first->swapped == 1 || second->swapped == 1){
        printf("No swap candidates found. Try again:\n");
        return;
    }
    if (prev1 != NULL)
        prev1->next = second;
    else
        *head = second;
    if (prev2 != NULL)
        prev2->next = first;
    else
        *head = first;
    struct Node *temp = second->next;
    second->next = first->next;
    first->next = temp;
    first->swapped = 1;
    second->swapped = 1;
    printf("result: ");
    printList(*head);
}

int main()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head = NULL;
	printf("Enter numbers to add to your list:\n");
	char input[256];
	int swap_data;
	int new_data;
	while (true)
	{
		scanf("%s", input);
		if (strcmp(input, "DONE") == 0) break;
		else append(&head, atoi(input));	
	}
	printf("Here is your list\n");
	printList(head);

	bool quit = 0;
	printf("Type two numbers to swap them around:\n");
	while(!quit){
		scanf("%s", input);
		if (strcmp(input, "DONE") == 0) quit = 1;
		else swapNodes(&head, atoi(input));
	}
	return 0;
}