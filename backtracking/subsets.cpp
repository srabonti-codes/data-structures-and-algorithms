#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& arr, vector<int>& current, int index) {
    if (index == arr.size()) {
        cout << "{ ";

        for (int value : current) {
            cout << value << " ";
        }

        cout << "}" << endl;
        return;
    }

    generateSubsets(arr, current, index + 1);

    current.push_back(arr[index]);
    generateSubsets(arr, current, index + 1);
    current.pop_back();
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> current;

    generateSubsets(arr, current, 0);

    return 0;
}