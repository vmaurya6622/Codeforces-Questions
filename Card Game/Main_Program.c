#include <stdio.h>
#include <stdlib.h>
#define N 100000

struct SegmentTreeNode {
    int max_val;
};

void buildSegmentTree(int arr[], struct SegmentTreeNode tree[], int node, int start, int end) {
    if (start == end) {
        tree[node].max_val = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        buildSegmentTree(arr, tree, 2 * node + 1, start, mid);
        buildSegmentTree(arr, tree, 2 * node + 2, mid + 1, end);
        tree[node].max_val = (tree[2 * node + 1].max_val > tree[2 * node + 2].max_val) ? tree[2 * node + 1].max_val : tree[2 * node + 2].max_val;
    }
}

int querySegmentTree(struct SegmentTreeNode tree[], int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return 0;
    }
    else if (start >= left && end <= right) {
        return tree[node].max_val;
    }
    else {
        int mid = (start + end) / 2;
        int left_val = querySegmentTree(tree, 2 * node + 1, start, mid, left, right);
        int right_val = querySegmentTree(tree, 2 * node + 2, mid + 1, end, left, right);
        return (left_val > right_val) ? left_val : right_val;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // build segment tree
    struct SegmentTreeNode tree[4 * N];
    buildSegmentTree(arr, tree, 0, 0, n - 1);

    int ishu = 0, rohu = 0;
    for (int i = 0; i < n - k + 1; i++) {
        if (i % 2 == 0) {
            ishu += querySegmentTree(tree, 0, 0, n - 1, i, i + k - 1);
        }
        else {
            rohu += querySegmentTree(tree, 0, 0, n - 1, i, i + k - 1);
        }
    }

    if (ishu > rohu) {
        printf("ishu");
    }
    else if (ishu < rohu) {
        printf("rohu");
    }
    else {
        printf("draw");
    }

    return 0;
}
