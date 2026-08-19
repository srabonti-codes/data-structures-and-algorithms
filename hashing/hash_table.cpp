#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int index = key % SIZE;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    bool search(int key) {
        int index = key % SIZE;
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }

            index = (index + 1) % SIZE;

            if (index == start) {
                break;
            }
        }

        return false;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);

    hashTable.display();

    cout << hashTable.search(25) << endl;

    return 0;
}