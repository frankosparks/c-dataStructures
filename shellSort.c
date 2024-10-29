#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for Shell Sort
void shellSort(int a[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int j = gap; j < n; j++) {
            // Save a[j] in temp and make space for it
            int temp = a[j];
            int i;
            
            // Shift earlier gap-sorted elements up until the correct location for a[j] is found
            for (i = j - gap; i >= 0 && a[i] > temp; i -= gap) {
                a[i + gap] = a[i];
            }
            
            // Put temp (the original a[j]) in its correct location
            a[i + gap] = temp;
        }
    }
}

// Function to print the array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int a[] = {12, 34, 54, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Array before sorting:\n");
    printArray(a, n);

    shellSort(a, n);

    printf("Array after sorting:\n");
    printArray(a, n);

    return 0;
}
