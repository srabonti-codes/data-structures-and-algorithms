#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> coins = {25, 10, 5, 1};
    int amount = 63;

    int count = 0;

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
            cout << coin << " ";
        }
    }

    cout << "\nMinimum coins: " << count;

    return 0;
}