#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intSize, floatSize;

    cout << "Enter the size of the integer array: ";
    cin >> intSize;
    int intArray[intSize];
    cout << "Enter the elements of the integer array: ";
    for (int i = 0; i < intSize; i++) {
        cin >> intArray[i];
    }
    selectionSort(intArray, intSize);
    cout << "Sorted integer array: ";
    displayArray(intArray, intSize);

    cout << "Enter the size of the float array: ";
    cin >> floatSize;
    float floatArray[floatSize];
    cout << "Enter the elements of the float array: ";
    for (int i = 0; i < floatSize; i++) {
        cin >> floatArray[i];
    }
    selectionSort(floatArray, floatSize);
    cout << "Sorted float array: ";
    displayArray(floatArray, floatSize);

    return 0;
}