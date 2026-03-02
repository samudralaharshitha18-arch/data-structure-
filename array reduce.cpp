#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmpPairs(const void *a, const void *b) {
    int va = ((Pair *)a)->value;
    int vb = ((Pair *)b)->value;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Create array of (value, original_index)
    Pair *p = (Pair *)malloc(N * sizeof(Pair));
    for (int i = 0; i < N; i++) {
        p[i].value = arr[i];
        p[i].index = i;
    }

    // Sort by value
    qsort(p, N, sizeof(Pair), cmpPairs);

    // rank[i] = reduced form for original index i
    int *rank = (int *)malloc(N * sizeof(int));
    for (int newVal = 0; newVal < N; newVal++) {
        int origIndex = p[newVal].index;
        rank[origIndex] = newVal;
    }

    // Output reduced form in original order
    for (int i = 0; i < N; i++) {
        printf("%d", rank[i]);
        if (i != N - 1) printf(" ");
    }

    free(arr);
    free(p);
    free(rank);
    return 0;
}

