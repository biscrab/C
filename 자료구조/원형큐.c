#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
int front = 0, rear = 0; //초기화
int queue[QUEUE_SIZE];

int IsEmpty() {
	if (rear == front)
		return  1; //비어있음
	else
		return 0; //데이터가 있음
}

int IsFull() {
	if ((rear+1)%QUEUE_SIZE == front)
		return 1; //데이터가 다 참
	else
		return 0; //빈자리가 있음
}

void enQueue(int data) {
	if (IsFull()) printf("queue is full\n");
	else
		rear = (rear + 1) % QUEUE_SIZE;
		queue[rear] = data;
}

void deQueue() {
	if (IsEmpty()) printf("queue is empty\n");
	else
		front = (front + 1) % QUEUE_SIZE;
		printf("%d \n", queue[front]);
}

void printqueue() {
	int i = 0;
	int temprear = ((rear < front) ? rear + QUEUE_SIZE : rear);
	for (i = front; i <= temprear; i++) {//front는 공백이니까 front 다음 인덱스부터 출력
		printf("Q[%d] : %d\n", i % QUEUE_SIZE, queue[i % QUEUE_SIZE]);
	}if (rear == front) {
		printf("empty queue");
	}
	printf("\n");
}

int main() {
	int i = 1;
	int n, data = 0;

	while (i) {
		printf("- queue menu -\n1.enQueue  2.deQueue  3.print  4.end\n choice : ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("input data? ");
			scanf("%d", &data);
			enQueue(data);
			break;
		case 2:
			deQueue();
			break;
		case 3:
			printqueue();
			break;
		case 4:
			printf("bye~~\n");
			i = 0; //i = 0;
			break;
		default:
			printf("no number, select again.\n");
			break;
		}
	}
}
