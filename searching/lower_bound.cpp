#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10, 20, 20, 30, 40, 50};
    int size = 6;
    int target = 20;

    int index = lower_bound(arr, arr + size, target) - arr;

    cout << "Lower bound index: " << index << endl;
    cout << "Value: " << arr[index] << endl;

    return 0;
}