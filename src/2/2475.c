#define CRT_SERCURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int num;
	int res = 0;

	for(int i = 0; i < 5; i++) {
		scanf("%d", &num);
		res += num * num;
	}

	printf("%d", res % 10);
	
}