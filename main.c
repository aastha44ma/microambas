#include <stdio.h>

// Merge function to merge two halves
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // Temporary array
    int left = low, right = mid + 1, k = 0;

    // Merging in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // Copy remaining elements from the left half
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Copy remaining elements from the right half
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Copy the sorted elements back to the original array
    for (int i = low, j = 0; i <= high; i++, j++) {
        arr[i] = temp[j];
    }
}

// Merge Sort function
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);     // Sort left half
        mergeSort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);   // Merge sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting Array:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("After Sorting Array:\n");
    printArray(arr, n);

    return 0;
}
