// FINAL FORM

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <functional>

enum class EntryState { EMPTY, OCCUPIED, DELETED };

class HashTable {
private:
    std::vector<std::pair<std::string, std::string>> table;
    std::vector<EntryState> state;
    int numBuckets;
    int size;
    const double loadFactorThreshold = 0.7;

    int hashFunction(const std::string &key) const {
        std::hash<std::string> hasher;
        return hasher(key) % numBuckets;
    }

    void rehash() {
        int oldNumBuckets = numBuckets;
        numBuckets *= 2;
        std::vector<std::pair<std::string, std::string>> oldTable = table;
        std::vector<EntryState> oldState = state;

        table = std::vector<std::pair<std::string, std::string>>(numBuckets);
        state = std::vector<EntryState>(numBuckets, EntryState::EMPTY);
        size = 0;

        for (int i = 0; i < oldNumBuckets; ++i) {
            if (oldState[i] == EntryState::OCCUPIED) {
                insert(oldTable[i].first, oldTable[i].second);
            }
        }
    }

public:
    HashTable(int initialBuckets = 8) : numBuckets(initialBuckets), size(0) {
        table.resize(numBuckets);
        state.resize(numBuckets, EntryState::EMPTY);
    }

    void insert(const std::string &key, const std::string &value) {
        if ((double)size / numBuckets > loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(key);
        int startIdx = index;
        int firstDeletedIdx = -1;

        while (state[index] != EntryState::EMPTY) {
            if (state[index] == EntryState::OCCUPIED && table[index].first == key) {
                table[index].second = value;
                return;
            }
            if (state[index] == EntryState::DELETED && firstDeletedIdx == -1) {
                firstDeletedIdx = index;
            }
            index = (index + 1) % numBuckets;
            if (index == startIdx) {
                std::cout << "Table is full!\n";
                return;
            }
        }

        int targetIdx = (firstDeletedIdx != -1) ? firstDeletedIdx : index;
        table[targetIdx] = std::make_pair(key, value);
        state[targetIdx] = EntryState::OCCUPIED;
        ++size;
    }

    void remove(const std::string &key) {
        int index = hashFunction(key);
        int startIdx = index;

        while (state[index] != EntryState::EMPTY) {
            if (state[index] == EntryState::OCCUPIED && table[index].first == key) {
                state[index] = EntryState::DELETED;
                --size;
                return;
            }
            index = (index + 1) % numBuckets;
            if (index == startIdx) break;
        }
    }

    std::string search(const std::string &key) const {
        int index = hashFunction(key);
        int startIdx = index;

        while (state[index] != EntryState::EMPTY) {
            if (state[index] == EntryState::OCCUPIED && table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % numBuckets;
            if (index == startIdx) break;
        }
        return "Key not found";
    }

    void display() const {
        std::cout << "HashTable with " << numBuckets << " buckets:\n";
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            if (state[i] == EntryState::OCCUPIED) {
                std::cout << "[" << table[i].first << ": " << table[i].second << "]\n";
            } else if (state[i] == EntryState::DELETED) {
                std::cout << "[deleted]\n";
            } else {
                std::cout << "[empty]\n";
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("one", "1");
    ht.insert("two", "2");
    ht.insert("three", "3");
    ht.insert("four", "4");
    ht.insert("five", "5");
    ht.insert("six", "6");
    ht.insert("seven", "7");
    ht.insert("eight", "8");

    ht.display();

    std::cout << "\nSearch 'five': " << ht.search("five") << "\n";
    std::cout << "Search 'nine': " << ht.search("nine") << "\n";

    ht.remove("four");
    std::cout << "\nAfter removing 'four':\n";
    ht.display();

    std::cout << "\nSearch 'eight' after removing 'four': " << ht.search("eight") << "\n";

    return 0;
}
