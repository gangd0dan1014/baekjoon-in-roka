#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b); 
}

int main() {

	int K, N, value = 0;
	long long* lan_cable;
	long long min = 1, max, mid, count_lan_cable = 0;

	scanf("%d %d", &K, &N);

	lan_cable = (long long*)malloc(sizeof(long long) * K);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &lan_cable[i]);
	}

	qsort(lan_cable, K, sizeof(long long), compare);
	max = lan_cable[K - 1];

	while(min <= max) {
		mid = (min + max) / 2;
		count_lan_cable = 0;

		// 랜선의 개수가 총 N개가 되는 지 확인
		for (int i = 0; i < K; i++) {
			count_lan_cable += (lan_cable[i] / mid);
		}

		if (count_lan_cable >= N) {
			value = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	printf("%d", value);
	free(lan_cable);
	
}