#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int position = 2;

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}