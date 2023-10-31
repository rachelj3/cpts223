#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    int currentSize;
    int tableSize;
    vector<pair<pair<K, V>, EntryState>> column;

public:
    ProbingHash(int n = 11) {
        tableSize = n;
        currentSize = 0;
        pair<pair<K, V>, EntryState> initPair;
        initPair.second = EMPTY;
        column.resize(n, initPair);
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->currentSize;
    }

    V operator[](const K& key) {
        int hashIndex = 0;
        K tempKey = key;
        while (this->column.at(hash(key)).first.first != key)//while its not the key we are looking for
        {
            ++tempKey; //keep on probing
        }
        hashIndex = hash(tempKey);

        return this->column.at(hashIndex).first.second;
    }

    bool insert(const std::pair<K, V>& pair) {

       std::pair<std::pair<K, V>, EntryState> newPair;
       newPair.first = pair;
       newPair.second = VALID;
       int hashIndex = 0;
       K key = pair.first;
       while (this->column.at(hash(key)).second != EMPTY) //while the spot to place is full/deleted
       {
           ++key;
       }
       hashIndex = hash(key);
       this->column.at(hashIndex) = newPair;

       if (++this->currentSize > (this->column.capacity() / 2)) //(++this->currentSize > this->column->capacity()
       {
           rehash();
       }
       return true;
    }

    void erase(const K& key) {
        int hashIndex = hash(key);
        this->column.at(hashIndex).second = DELETED;
    }

    void clear() {
        int index = 0;
        for (index = 0; index < this->tableSize; ++index)
        {
            this->erase(column.at(index).first.first);
        }
    }

    int bucket_count() {
        return this->tableSize;
    }

    float load_factor() {
        float lf = (float)this->currentSize / (float)this->tableSize;
        return lf;
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        int hashIndex = 0;
        hashIndex = (key) % this->tableSize;
        return hashIndex;
       // return -1;
    }

    void rehash()
    {
        vector<pair<pair<K, V>, EntryState>> oldColumn = std::move(column);
        pair<pair<K, V>, EntryState> initPair;
        int index = 0;
        initPair.second = EMPTY;
        column.resize(findNextPrime(tableSize * 2), initPair);
        this->tableSize = column.capacity();
        currentSize = 0;
        for (index = 0; index < oldColumn.capacity(); ++index)
        {
            if (oldColumn.at(index).second == VALID)
            {
                insert(oldColumn.at(index).first);
            }
        }
    }
};

#endif //__PROBING_HASH_H
