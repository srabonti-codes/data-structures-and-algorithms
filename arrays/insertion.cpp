#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int position = 2;
    int value = 25;

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    size++;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}