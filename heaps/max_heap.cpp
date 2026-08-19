#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heap = {40, 20, 30, 10, 50, 60};

    make_heap(heap.begin(), heap.end());

    cout << "Max heap: ";

    for (int value : heap) {
        cout << value << " ";
    }

    return 0;
}