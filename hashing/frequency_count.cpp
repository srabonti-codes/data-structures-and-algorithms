#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int size = 10;

    unordered_map<int, int> frequency;

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    for (auto pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}