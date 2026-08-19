#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack overflow" << endl;
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }

        top--;
    }

    int peek() {
        if (top == -1) {
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << stack.peek() << endl;

    stack.pop();

    cout << stack.peek() << endl;

    return 0;
}