#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};

    int n = dimensions.size() - 1;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] +
                            dp[k + 1][j] +
                            dimensions[i] *
                            dimensions[k + 1] *
                            dimensions[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum multiplication cost: " << dp[0][n - 1];

    return 0;
}