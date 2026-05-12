#include <iostream>
#include <list>
#include <vector>
#include <utility> // For std::pair
#include <string>

class HashTable {
private:
    // Each bucket stores a list of key-value pairs
    std::vector<std::list<std::pair<int, std::string>>> table;
    int numBuckets; // Number of buckets

    // Hash function: computes an index for a given key
    int hashFunction(int key) const {
        return key % numBuckets;
    }

public:
    // Constructor: initialize the table with a fixed number of buckets
    HashTable(int buckets) : numBuckets(buckets), table(buckets) {}

    // Insert a key-value pair
    void insert(int key, const std::string &value) 
    {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key already exists
                return;
            }
        }
        table[index].emplace_back(key, value); // Add new key-value pair
    }

    // Remove a key-value pair by key
    void remove(int key) 
    {
        int index = hashFunction(key);
        auto &chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }

    // Search for a value by key
    std::string search(int key) const 
    {
        int index = hashFunction(key);
        for (const auto &pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Key not found";
    }

    // Display the hash table
    void display() const {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto &pair : table[i]) {
                std::cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    HashTable hashTable(5); // Create a hash table with 5 buckets

    // Insert key-value pairs
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");
    hashTable.insert(8, "Eight"); // This will cause a collision with key 3 (same bucket)

    // Display the hash table
    hashTable.display();

    // Search for a key
    std::cout << "Search key 2: " << hashTable.search(2) << "\n";
    std::cout << "Search key 8: " << hashTable.search(8) << "\n";
    std::cout << "Search key 10: " << hashTable.search(10) << "\n";

    // Remove a key
    hashTable.remove(3);
    hashTable.display();

    return 0;
}
