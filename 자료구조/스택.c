#include <stdio.h>

int stack[10];
int top = -1;

void push(int data){
	if (top == 10) {
		printf("overflow\n");
	}
	else {
		if (top == -1)
			top++;
		stack[top] = data;
		top++;
		for (int i = 0; i < top; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

void pop() {
	if (top == -1) {
		printf("underflow\n");
	}
	else {
		top--;
		stack[top] = NULL;
		for (int i = 0; i < top; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	push(1);
	push(2);
	pop();
	push(4);
	push(5);
	push(5);
	pop();
	pop();
}
