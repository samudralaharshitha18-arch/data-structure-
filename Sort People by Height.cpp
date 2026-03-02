#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];
    int heights[n];

    // Read names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Read heights
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    // Sort in descending order of heights
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (heights[i] < heights[j]) {
                // Swap heights
                int tempHeight = heights[i];
                heights[i] = heights[j];
                heights[j] = tempHeight;

                // Swap corresponding names
                char tempName[50];
                strcpy(tempName, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tempName);
            }
        }
    }

    // Print sorted names
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }

    return 0;
}

