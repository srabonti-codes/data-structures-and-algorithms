#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapSort(vector<int>& arr) {
    make_heap(arr.begin(), arr.end());

    for (int i = arr.size() - 1; i > 0; i--) {
        pop_heap(arr.begin(), arr.begin() + i + 1);
    }
}

int main() {
    vector<int> arr = {50, 20, 40, 10, 30};

    heapSort(arr);

    for (int value : arr) {
        cout << value << " ";
    }

    return 0;
}