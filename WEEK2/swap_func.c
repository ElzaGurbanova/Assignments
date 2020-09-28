#include <stdio.h>

//in the swap function copies of val1 and val2 are passed 
int swap(int val1, int val2);

int main(){
	
	int a;
	int b; 
	
	scanf("%d%d", &a, &b);

	printf("Before the execution of swap function:\nval1 - %d, val2 - %d\n", a, b);
	swap(a, b);	
	printf("After the function:\nval1 - %d, val2 - %d\n", a, b);
	
	return 0; 

}

int swap(int val1, int val2){
	
	int temp;
	
	temp = val1;
	val1 = val2;
	val2 = temp;

	printf("Inside the function:\nval1 - %d, val2 - %d\n", val1, val2); 
	return 0;

}
