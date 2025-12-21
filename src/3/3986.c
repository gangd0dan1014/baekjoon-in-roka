#define MAX 100001
#include <stdio.h>
#include <string.h>


char stack[MAX];
char word[MAX];
int top = -1;

void push(char alpha) {
	stack[++top] = alpha;
}

char pop() {
	return stack[top--];
}

int main() {
	int res = 0, count;

	scanf("%d",&count);

	for (int i = 0; i < count; i++) {
		top = -1;
		scanf("%s", word);
		int len = strlen(word);
		for (int j = 0; j < len; j++) {
			if (top != -1 && (stack[top] == word[j])){
				pop();
			}
			else {
				push(word[j]);
			}
		}

		if (top == -1) {
			res++;
		}
	}

	printf("%d",res);
}