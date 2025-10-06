#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertAtIndex(int arr[], int *n, int index, int value);
void deleteAtIndex(int arr[], int *n, int index);
int findMin(int arr[], int n);
int findMax(int arr[], int n);
void displayArray(int arr[], int n);
void reverseDisplay(int arr[], int n);
int searchElement(int arr[], int n, int value);
float averageArray(int arr[], int n);
int hasDuplicates(int arr[], int n);
void reverseArray(int arr[], int n);

int main() {
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);

    int arr[100]; // assuming max size of array is 100
    int i;

    printf("Enter %d elements between 1 and %d:\n", N, N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, index, value, pos;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert element at index\n");
        printf("2. Delete element at index\n");
        printf("3. Find minimum value\n");
        printf("4. Find maximum value\n");
        printf("5. Display array elements\n");
        printf("6. Reverse display array elements\n");
        printf("7. Search element in array\n");
        printf("8. Array element count\n");
        printf("9. Average of all array elements\n");
        printf("10. Check if array contains duplicates\n");
        printf("11. Reverse the array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index to insert: ");
                scanf("%d", &index);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtIndex(arr, &N, index, value);
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(arr, &N, index);
                break;

            case 3:
                printf("Minimum value: %d\n", findMin(arr, N));
                break;

            case 4:
                printf("Maximum value: %d\n", findMax(arr, N));
                break;

            case 5:
                printf("Array elements: ");
                displayArray(arr, N);
                break;

            case 6:
                printf("Array in reverse order: ");
                reverseDisplay(arr, N);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &value);
                pos = searchElement(arr, N, value);
                if (pos != -1)
                    printf("Element found at index %d\n", pos);
                else
                    printf("Element not found.\n");
                break;

            case 8:
                printf("Array element count: %d\n", N);
                break;

            case 9:
                printf("Average of all elements: %.2f\n", averageArray(arr, N));
                break;

            case 10:
                if (hasDuplicates(arr, N))
                    printf("Array contains duplicates.\n");
                else
                    printf("Array does not contain duplicates.\n");
                break;

            case 11:
                reverseArray(arr, N);
                printf("Array reversed successfully.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// Function definitions
void insertAtIndex(int arr[], int *n, int index, int value) {
    if (index < 0 || index > *n) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
    printf("Element inserted.\n");
}

void deleteAtIndex(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted.\n");
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseDisplay(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchElement(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

float averageArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

int hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

