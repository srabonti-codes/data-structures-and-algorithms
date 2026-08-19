#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& arr, int index) {
    if (index == arr.size()) {
        for (int value : arr) {
            cout << value << " ";
        }

        cout << endl;
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        generatePermutations(arr, index + 1);
        swap(arr[index], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};

    generatePermutations(arr, 0);

    return 0;
}