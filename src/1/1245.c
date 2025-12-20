#define CRT_SECURE_NO_WARNINGS
#define MAX_ROW 102
#define MAX_COL 72
#include <stdio.h>

typedef struct {
    int row;
    int col;
} coordinate;

int farm[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];
coordinate queue[MAX_ROW * MAX_COL];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int front, rear;
int N, M;

void add_queue(coordinate temp) {
    queue[++rear] = temp;
}

coordinate del_queue() {
    return queue[++front];
}

int bfs(int start_row, int start_col) {
    int isPeak = 1;
    int height = farm[start_row][start_col];

    front = rear = -1;
    add_queue((coordinate){start_row, start_col});
    visited[start_row][start_col] = 0;

    while (front < rear) {
        coordinate cur = del_queue();

        for (int i = 0; i < 8; i++) {
            int nr = cur.row + dy[i];
            int nc = cur.col + dx[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if (farm[nr][nc] > height) {
                isPeak = 0;
            }

            if (visited[nr][nc] && farm[nr][nc] == height) {
                visited[nr][nc] = 0;
                add_queue((coordinate){nr, nc});
            }
        }
    }

    return isPeak;
}

int main() {
    int result = 0;

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &farm[i][j]);
            visited[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (visited[i][j]) {
                result += bfs(i, j);
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
