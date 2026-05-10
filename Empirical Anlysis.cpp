#include <iostream>
#include <ctime>
using namespace std;
// Selection Sort
void selectionSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Space Usage: O(1) In-place" << endl;
}
// Bubble Sort
void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Space Usage: O(1) In-place" << endl;
}
// Quick Sort
int quickComparisons = 0;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        quickComparisons++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSortHelper(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}
void quickSort(int arr[], int n) {
    quickComparisons = 0;
    quickSortHelper(arr, 0, n - 1);
    cout << "Comparisons: " << quickComparisons << endl;
    cout << "Swaps: N/A" << endl;
    cout << "Space Usage: O(log n) Recursive Stack" << endl;
}
// Merge Sort
int mergeComparisons = 0;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100];
    int R[100];
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2) {
        mergeComparisons++;
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortHelper(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void mergeSort(int arr[], int n) {
    mergeComparisons = 0;
    mergeSortHelper(arr, 0, n - 1);
    cout << "Comparisons: " << mergeComparisons << endl;
    cout << "Swaps: N/A" << endl;
    cout << "Space Usage: O(n) Extra Arrays" << endl;
}
// Copy Array Function
void copyArray(int source[], int destination[], int n) {
    for(int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}
// Main Function
int main() {
    int sorted5[5] = {1,2,3,4,5};
    int reverse5[5] = {5,4,3,2,1};
    int sorted100[100];
    int reverse100[100];
    for(int i = 0; i < 100; i++) {
        sorted100[i] = i + 1;
        reverse100[i] = 100 - i;
    }
    int temp[100];
   // Selection Sort
    cout << "\n========== Selection Sort ==========\n";
    cout << "\nCase: Size 5 Sorted\n";
    copyArray(sorted5, temp, 5);
    double start = clock();
    selectionSort(temp, 5);
    double end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 5 Reverse\n";
    copyArray(reverse5, temp, 5);
    start = clock();
    selectionSort(temp, 5);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 100 Sorted\n";
    copyArray(sorted100, temp, 100);
    start = clock();
    selectionSort(temp, 100);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC  << " seconds\n";
    cout << "\nCase: Size 100 Reverse\n";
    copyArray(reverse100, temp, 100);
    start = clock();
    selectionSort(temp, 100);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    // Bubble Sort
   cout << "\n========== Bubble Sort ==========\n";
    cout << "\nCase: Size 5 Sorted\n";
    copyArray(sorted5, temp, 5);
    start = clock();
    bubbleSort(temp, 5);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "\nCase: Size 5 Reverse\n";
    copyArray(reverse5, temp, 5);
    start = clock();
    bubbleSort(temp, 5);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 100 Sorted\n";
    copyArray(sorted100, temp, 100);
    start = clock();
    bubbleSort(temp, 100);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 100 Reverse\n";
    copyArray(reverse100, temp, 100);
    start = clock();
    bubbleSort(temp, 100);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    // Quick Sort
    cout << "\n========== Quick Sort ==========\n";
    cout << "\nCase: Size 5 Sorted\n";
    copyArray(sorted5, temp, 5);
    start = clock();
    quickSort(temp, 5);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 5 Reverse\n";
    copyArray(reverse5, temp, 5);
    start = clock();
    quickSort(temp, 5);
    end = clock();
    cout << "Time Taken: " << (end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "\nCase: Size 100 Sorted\n";
    copyArray(sorted100, temp, 100);
    start = clock();
    quickSort(temp, 100);
    end = clock();
    cout << "Time Taken: "<< (end - start) / CLOCKS_PER_SEC<< " seconds\n";
    cout << "\nCase: Size 100 Reverse\n";
    copyArray(reverse100, temp, 100);
    start = clock();
    quickSort(temp, 100);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    // Merge Sort
    cout << "\n========== Merge Sort ==========\n";
    cout << "\nCase: Size 5 Sorted\n";
    copyArray(sorted5, temp, 5);
    start = clock();
    mergeSort(temp, 5);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    cout << "\nCase: Size 5 Reverse\n";
    copyArray(reverse5, temp, 5);
    start = clock();
    mergeSort(temp, 5);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    cout << "\nCase: Size 100 Sorted\n";
    copyArray(sorted100, temp, 100);
    start = clock();
    mergeSort(temp, 100);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    cout << "\nCase: Size 100 Reverse\n";
    copyArray(reverse100, temp, 100);
    start = clock();
    mergeSort(temp, 100);
    end = clock();
    cout << "Time Taken: "
         << (end - start) / CLOCKS_PER_SEC
         << " seconds\n";
    return 0;
}
