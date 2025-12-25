#define MAX_SIZE 2502
#include <stdio.h>

int grid_paper[MAX_SIZE][MAX_SIZE];
int prefix_sum_row[MAX_SIZE][MAX_SIZE];
int prefix_sum_col[MAX_SIZE][MAX_SIZE];

int main() {
    int N, M, K;
    int res = 0;

    scanf("%d %d", &N, &M);
    scanf("%d", &K);

    // 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &grid_paper[i][j]);
        }
    }

    // K == 0 처리
    if (K == 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (grid_paper[i][j] == 1)
                    res++;
            }
        }
        printf("%d", res);
        return 0;
    }

    // 가로 누적합
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefix_sum_row[i][j] = grid_paper[i][j] + prefix_sum_row[i][j - 1];
        }
    }

    // 세로 누적합
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefix_sum_col[i][j] = grid_paper[i][j] + prefix_sum_col[i - 1][j];
        }
    }

    int need = 4 * K + 1;

    // 중심 순회
    for (int i = K + 1; i <= N - K; i++) {
        for (int j = K + 1; j <= M - K; j++) {

            int horizontal =
                prefix_sum_row[i][j + K] - prefix_sum_row[i][j - K - 1];

            int vertical =
                prefix_sum_col[i + K][j] - prefix_sum_col[i - K - 1][j];

            int temp = horizontal + vertical - grid_paper[i][j];

            if (temp == need)
                res++;
        }
    }

    printf("%d", res);
    return 0;
}
