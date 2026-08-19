#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(vector<int>& arr, vector<int>& current, int index, int r) {
    if (current.size() == r) {
        for (int value : current) {
            cout << value << " ";
        }

        cout << endl;
        return;
    }

    if (index == arr.size()) {
        return;
    }

    current.push_back(arr[index]);
    generateCombinations(arr, current, index + 1, r);
    current.pop_back();

    generateCombinations(arr, current, index + 1, r);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    vector<int> current;
    int r = 2;

    generateCombinations(arr, current, 0, r);

    return 0;
}