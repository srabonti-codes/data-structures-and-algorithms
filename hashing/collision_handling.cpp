#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
private:
    static const int SIZE = 5;
    vector<list<int>> table;

public:
    HashTable() : table(SIZE) {}

    void insert(int key) {
        int index = key % SIZE;
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = key % SIZE;

        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }

        return false;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";

            for (int value : table[i]) {
                cout << value << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(10);
    hashTable.insert(15);
    hashTable.insert(20);
    hashTable.insert(25);

    hashTable.display();

    cout << hashTable.search(20) << endl;

    return 0;
}