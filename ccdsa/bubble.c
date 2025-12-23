#include<stdio.h>

void sort(int arr[], int n);

int main() {
    int arr[5] = {10, 30, 50, 40, 20};
    sort(arr, 5); // calling function

    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void sort(int arr[], int n) {
    int count = 0; // to count number of swaps

    for (int i = 0; i < n - 1; i++) {
        int swapHappened = 0; // flag to check if any swap occurred

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                count++;            // increment swap count
                swapHappened = 1;   // mark that swap occurred
            }
        }

        // If no swaps occurred in this pass, array is already sorted
        if (swapHappened == 0) {
            printf("\nNo swaps in iteration %d — array is already sorted.\n", i + 1);
            break;
        }
    }

    printf("\nTotal number of swaps performed: %d\n", count);
}



