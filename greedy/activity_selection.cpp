#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

int main() {
    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    sort(activities.begin(), activities.end(), [](Activity a, Activity b) {
        return a.finish < b.finish;
    });

    int lastFinish = -1;

    for (Activity activity : activities) {
        if (activity.start >= lastFinish) {
            cout << "(" << activity.start << ", " << activity.finish << ") ";
            lastFinish = activity.finish;
        }
    }

    return 0;
}