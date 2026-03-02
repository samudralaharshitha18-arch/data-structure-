#include <stdio.h>

// Function to count number of 1 bits
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting based on rules
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            int count1 = countBits(arr[i]);
            int count2 = countBits(arr[j]);

            // Primary sort: ascending by number of 1 bits
            // Secondary sort: ascending numerical order
            if (count1 > count2 || 
               (count1 == count2 && arr[i] > arr[j])) {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

