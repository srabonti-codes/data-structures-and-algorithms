#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> heap;

    heap.push(30);
    heap.push(10);
    heap.push(50);
    heap.push(20);

    cout << "Top: " << heap.top() << endl;

    heap.pop();

    cout << "Top after pop: " << heap.top() << endl;
    cout << "Size: " << heap.size() << endl;
    cout << "Empty: " << heap.empty() << endl;

    return 0;
}