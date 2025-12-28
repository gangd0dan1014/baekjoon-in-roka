#include <stdio.h>

int main() {

	int win[1001];
	int N;
	
	win[1] = 1;
	win[2] = 0;
	win[3] = 1;
	win[4] = 1;

	scanf("%d",&N);

	if (N >= 5) {
		for (int i = 5; i <= N; i++) {
			win[i] = !win[i - 1] | !win[i - 3] | !win[i - 4];
		}
	}

	if (win[N]) {
		printf("SK");
	}
	else {
		printf("CY");
	}
}