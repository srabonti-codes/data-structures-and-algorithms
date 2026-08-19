#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};
    int size = 3;

    for (int start = 0; start < size; start++) {
        for (int end = start; end < size; end++) {
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}