#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (size == 5) {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        front = (front + 1) % 5;
        size--;
    }

    int peek() {
        if (size == 0) {
            return -1;
        }

        return arr[front];
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.peek() << endl;

    queue.dequeue();

    cout << queue.peek() << endl;

    return 0;
}