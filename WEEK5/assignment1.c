#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_CAPACITY 2

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = STACK_CAPACITY;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);
    printf("deallocated\n");
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void resize(struct Stack* stack)
{
	stack->capacity *= 2;
    int *tmp_arr;
    tmp_arr = (int *) malloc(stack->capacity * sizeof(int));
    
	for (int i = 0; i < stack->capacity; i++) {
        tmp_arr[i] = stack->array[i];
    }
    free(stack->array);
    stack->array = tmp_arr;
    printf("stack reallocated, new length: %d\n", stack->capacity);
}

void shrink_to_half(struct Stack* stack){
    stack->capacity /= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n",stack->capacity);
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        resize(stack);
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    if(stack->top <= stack->capacity/4){
        shrink_to_half(stack);
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int displayStack(struct Stack* stack){
	if( stack->top == -1)
	printf("\nStack is empty");
	else
	{
		for (int i = stack->top; i >= 0; i--)
        	printf("%d ", stack->array[i]);
    	printf("\n\n"); // adding for formatting purposes
	}
return 0;
}

int main()
{
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d popped from stack\n", pop(stack));

	printf("Stack capacity before shrinking unused memory: %d\n", stack->capacity);	
    shrink_to_half(stack);
	printf("Stack capacity after shrinking unused memory: %d\n", stack->capacity);
	displayStack(stack);
	deallocStack(stack);
    return 0;
}
