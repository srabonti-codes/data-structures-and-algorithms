#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        index++;

        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int prefixSum(int index) {
        index++;
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

    int rangeSum(int left, int right) {
        if (left == 0)
            return prefixSum(right);

        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    FenwickTree tree(arr.size());

    for (int i = 0; i < arr.size(); i++)
        tree.update(i, arr[i]);

    cout << tree.rangeSum(1, 3);

    return 0;
}