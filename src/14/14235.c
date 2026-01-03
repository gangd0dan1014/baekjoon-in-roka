#define MAX 500001
#include <stdio.h>

int heap[MAX];
int heap_index = 0;

void push(int number) {
	int index = ++heap_index;

	while ((index != 1) && (number > heap[index / 2])) {
		heap[index] = heap[index / 2];
		index /= 2;
	}
	heap[index] = number;
}

int pop() {
	
	int ret = heap[1];
	int temp = heap[heap_index--], parent = 1, child = 2;

	while (child <= heap_index) {
		if ((child + 1 <= heap_index) && (heap[child] < heap[child + 1])) {
			child++;
		}

		if (temp > heap[child]) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child = parent * 2;
	}
	heap[parent] = temp;
	return ret;
	
}

int main() {

	int count, destination, value;
	scanf("%d", &count);

	// destination 값에 따라 행동하기
	for (int i = 0; i < count; i++) {
		scanf("%d", &destination);

		if (destination) {
			for (int j = 0; j < destination; j++) {
				scanf("%d",&value);
				push(value);
			}
		}
		else {
			if (heap_index) {
				printf("%d\n", pop());
			}
			else {
				printf("%d\n", -1);
			}
		}
	}

	
}