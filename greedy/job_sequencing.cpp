#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;

    for (Job job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<char> schedule(maxDeadline + 1, '-');
    vector<bool> used(maxDeadline + 1, false);

    int totalProfit = 0;

    for (Job job : jobs) {
        for (int slot = job.deadline; slot >= 1; slot--) {
            if (!used[slot]) {
                used[slot] = true;
                schedule[slot] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    for (int i = 1; i <= maxDeadline; i++) {
        cout << schedule[i] << " ";
    }

    cout << "\nTotal profit: " << totalProfit;

    return 0;
}