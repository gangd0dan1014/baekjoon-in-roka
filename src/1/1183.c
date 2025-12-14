#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {

    int time[50];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int promise, arrive;
        scanf("%d %d", &promise, &arrive);
        time[i] = promise - arrive;
    }

    qsort(time, n, sizeof(int), compare);

    if (n % 2 == 1) {
        printf("1\n");
    } else {
        printf("%d\n", time[n / 2] - time[n / 2 - 1] + 1);
    }

    return 0;
}
