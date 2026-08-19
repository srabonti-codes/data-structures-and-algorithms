#include <iostream>
using namespace std;

int recursiveSearch(int arr[], int n, int key, int index) {
    if (index == n) {
        return -1;
    }

    if (arr[index] == key) {
        return index;
    }

    return recursiveSearch(arr, n, key, index + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = recursiveSearch(arr, n, key, 0);

    if (result != -1) {
        cout << "Found at index: " << result;
    } else {
        cout << "Not found";
    }

    return 0;
}