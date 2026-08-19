#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10, 20, 20, 30, 40, 50};
    int size = 6;
    int target = 20;

    int index = upper_bound(arr, arr + size, target) - arr;

    cout << "Upper bound index: " << index << endl;

    if (index < size) {
        cout << "Value: " << arr[index] << endl;
    }

    return 0;
}