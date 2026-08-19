#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == 99) {
            cout << "Queue overflow" << endl;
            return;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue underflow" << endl;
            return;
        }

        front++;
    }

    int peek() {
        if (front > rear) {
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.peek() << endl;

    queue.dequeue();

    cout << queue.peek() << endl;

    return 0;
}