#include <stdio.h>

int main() {

	long long N;
	scanf("%lld", &N);

	if (N % 5 == 0 || N % 5 == 2) {
		printf("CY");
	}
	else {
		printf("SK");
	}
	
}