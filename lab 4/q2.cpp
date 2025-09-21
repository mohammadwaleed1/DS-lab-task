#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) { // Selection Sort
    for (int i = 0; i< n-1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx])
                idx = j;
        }
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}
int interpolationSearch(int arr[], int n, int key) { // Interpolation Search (returns index or -1)
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }
        int pos = low + ((double)(key - arr[low]) * (high - low)) / (arr[high] - arr[low]);// formula to find mid
        if (arr[pos] == key) {

            while (pos > 0 && arr[pos - 1] == key) {//handles duplicates
                pos--;
            }
            return pos;
        }

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1; 
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<< "Original array: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int idx = interpolationSearch(arr, n, key);

    if (idx != -1)
        cout << "Element found at index " << idx << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
