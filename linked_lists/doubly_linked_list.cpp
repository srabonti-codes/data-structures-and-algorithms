#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;

    Node* current = first;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}