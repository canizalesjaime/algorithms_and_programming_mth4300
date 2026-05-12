#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <string>

class HashTable {
private:
    std::vector<std::pair<int, std::string>> table;  // Key-value pairs
    std::vector<bool> isOccupied;  // Track if the bucket is occupied
    int numBuckets;  // Number of buckets

    // Primary hash function
    int hash1(int key) const {
        return key % numBuckets;
    }

    // Secondary hash function (must be non-zero and relatively prime to numBuckets)
    int hash2(int key) const {
        // Common practice: use a prime smaller than numBuckets
        return 1 + (key % (numBuckets - 1));
    }

public:
    // Constructor: initialize the table
    HashTable(int buckets) : numBuckets(buckets), table(buckets), isOccupied(buckets, false) {}

    // Insert using double hashing
    void insert(int key, const std::string &value) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int i = 0;

        while (i < numBuckets) {
            int probeIndex = (h1 + i * h2) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    table[probeIndex].second = value; // Update value
                    return;
                }
            } else {
                table[probeIndex] = std::make_pair(key, value);
                isOccupied[probeIndex] = true;
                return;
            }
            ++i;
        }

        std::cout << "Table is full!" << std::endl;
    }

    // Remove using double hashing
    void remove(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int i = 0;

        while (i < numBuckets) {
            int probeIndex = (h1 + i * h2) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    isOccupied[probeIndex] = false;
                    return;
                }
            } else {
                break;
            }
            ++i;
        }
    }

    // Search using double hashing
    std::string search(int key) const {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int i = 0;

        while (i < numBuckets) {
            int probeIndex = (h1 + i * h2) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    return table[probeIndex].second;
                }
            } else {
                break;
            }
            ++i;
        }

        return "Key not found";
    }

    // Display the hash table
    void display() const {
        for (int i = 0; i < numBuckets; ++i) {
            if (isOccupied[i]) {
                std::cout << "Bucket " << i << ": [" << table[i].first << ": " << table[i].second << "]\n";
            } else {
                std::cout << "Bucket " << i << ": [empty]\n";
            }
        }
    }
};

int main() {
    HashTable hashTable(5);  // Choose a prime number of buckets for better double hashing behavior

    // Insert key-value pairs
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");
    hashTable.insert(8, "Eight");  // Collision with 3 likely

    // Display the hash table
    std::cout << "Hash Table after insertions:\n";
    hashTable.display();

    // Search
    std::cout << "\nSearch key 2: " << hashTable.search(2) << "\n";
    std::cout << "Search key 8: " << hashTable.search(8) << "\n";
    std::cout << "Search key 10: " << hashTable.search(10) << "\n";

    // Remove
    hashTable.remove(3);
    std::cout << "\nHash Table after deleting key 3:\n";
    hashTable.display();

    return 0;
}
