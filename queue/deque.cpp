#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << dq.front() << endl;

    return 0;
}