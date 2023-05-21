#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

typedef struct {
    int index;
    int sum;
    int values[MAX_M];
} col_node;

int compare_col(const void* a, const void* b) {
    const col_node* c1 = (const col_node*)a;
    const col_node* c2 = (const col_node*)b;
    if (c1->sum != c2->sum) {
        return c1->sum - c2->sum;
    } else {
        return c1->index - c2->index;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[MAX_M][MAX_N];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    col_node col[MAX_N];
    for (int j = 0; j < n; j++) {
        col[j].index = j;
        col[j].sum = 0;
        for (int i = 0; i < m; i++) {
            col[j].sum += matrix[i][j];
            col[j].values[i] = matrix[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            if (compare_col(&col[i], &col[j]) < 0) {
                col_node temp = col[i];
                col[i] = col[j];
                col[j] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", col[j].values[i]);
        }
        printf("\n");
    }

    return 0;
}
