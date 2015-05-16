#include <stdio.h>
#include <stdlib.h>
#define MAX_EL 128

struct Stack {
	int *elements;
	int curr;
};

static struct Stack stack = {.curr = -1};

void pop(){
	if (stack.curr >= 0){
		*(stack.elements+stack.curr) = '\0';
		--stack.curr;
	}
	else puts("No elements in stack");
}
void push(int el){
	if (stack.curr == 128)
		puts("Stack Overflow");
	else{
		++stack.curr;
		*(stack.elements+stack.curr) = el;
	}
}

void peek(){
	if (stack.curr < 0) puts("No elements!");
	else printf("%d\n", *(stack.elements+stack.curr));
}

int main (){
	stack.elements = malloc(sizeof(int)*MAX_EL);
	int i = 0;
	for (; i <= 129; ++i)
		push(i);
	peek();
	
	for (i = 0; i <= 128; ++i)
		pop();
	peek();
}
