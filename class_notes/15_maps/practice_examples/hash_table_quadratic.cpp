#include <iostream>
#include <vector>
#include <utility> // For std::pair
#include <string>

class HashTable {
private:
    std::vector<std::pair<int, std::string>> table;  // Key-value pairs
    std::vector<bool> isOccupied;  // Track if the bucket is occupied
    int numBuckets;  // Number of buckets

    // Hash function: computes an index for a given key
    int hashFunction(int key) const {
        return key % numBuckets;
    }

public:
    // Constructor: initialize the table with a fixed number of buckets
    HashTable(int buckets) : numBuckets(buckets), table(buckets), isOccupied(buckets, false) {}

    // Insert a key-value pair using quadratic probing
    void insert(int key, const std::string &value) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing
        while (i < numBuckets) {
            int probeIndex = (index + i * i) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    table[probeIndex].second = value; // Update value if key already exists
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

    // Remove a key-value pair by key using quadratic probing
    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < numBuckets) {
            int probeIndex = (index + i * i) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    isOccupied[probeIndex] = false;  // Mark as empty (no tombstone handling)
                    return;
                }
            } else {
                break;  // Stop probing if we hit an empty slot
            }
            ++i;
        }
    }

    // Search for a value by key using quadratic probing
    std::string search(int key) const {
        int index = hashFunction(key);
        int i = 0;

        while (i < numBuckets) {
            int probeIndex = (index + i * i) % numBuckets;
            if (isOccupied[probeIndex]) {
                if (table[probeIndex].first == key) {
                    return table[probeIndex].second;  // Return the value if found
                }
            } else {
                break;  // Stop probing if we hit an empty slot
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
    HashTable hashTable(5);  // Create a hash table with 5 buckets

    // Insert key-value pairs
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");
    hashTable.insert(8, "Eight");  // This will cause a collision with key 3 (same bucket)

    // Display the hash table
    std::cout << "Hash Table after insertions:\n";
    hashTable.display();

    // Search for a key
    std::cout << "\nSearch key 2: " << hashTable.search(2) << "\n";
    std::cout << "Search key 8: " << hashTable.search(8) << "\n";
    std::cout << "Search key 10: " << hashTable.search(10) << "\n";

    // Remove a key
    hashTable.remove(3);
    std::cout << "\nHash Table after deleting key 3:\n";
    hashTable.display();

    return 0;
}
