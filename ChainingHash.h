/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    int tableSize;
    int currentSize;
    std::vector<std::list<std::pair<K, V>>> *column;

public:
    ChainingHash(int n = 11) {
        //this->column->resize(n);
        this->currentSize = 0;
        this->tableSize = n;
        std::list<std::pair<K, V>> initList;
        this->column = new std::vector<std::list<std::pair<K, V>>>;
        this->column->resize(n, initList);
    }

    ~ChainingHash() {
        this->clear();
        delete this->column;
        currentSize = 0;
    }

    int size() {
        return this->currentSize;
    }

    V operator[](const K& key) {
        int hashIndex = hash(key);
        list<pair<K, V>> curList = this->column->at(hashIndex);
        typename list<pair<K, V>>::iterator iter = curList.begin();
        
        for (iter; iter != curList.end(); ++iter)
        {
            if ((*iter).first == key)
            {
                return (*iter).second;
            }
        }
    }

    bool insert(const std::pair<K, V>& pair) {

        this->column->at(hash(pair.first)).push_back(pair);
        if (++this->currentSize > (this->column->capacity() / 2)) //(++this->currentSize > this->column->capacity()
        {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        int hashIndex = hash(key);
        list<pair<K, V>> curList = this->column->at(hashIndex);
        typename list<pair<K, V>>::iterator iter = curList.begin();

        while (iter != curList.end() && (*iter).first != key)
        {
            ++iter;
        }
        curList.erase(iter);
        --currentSize;
    }

    void clear() {
        int i = 0;
        for (i = 0; i < this->column->size(); i++)
        {
            column->at(i).clear();
        }
    }

    int bucket_count() {
        return this->column->capacity();
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
        int hashIndex = key % this->tableSize;
        if (hashIndex < 0)
        {
            hashIndex += this->tableSize;
        }
        return hashIndex;
    }


    void rehash() {

        list<pair<K, V>> initPair;
        vector<list<pair<K, V>>> oldColumn = std::move(*column);
        int cap = this->tableSize, index = 0;
        column->resize(findNextPrime(cap * 2), initPair);
        this->tableSize = column->capacity();
        currentSize = 0;
        for (index = 0; index < oldColumn.capacity(); index++) //move through vector
        {
            while (oldColumn[index].empty() != true) //move through each list in vector till reach end
            {
                insert(oldColumn[index].front());
                oldColumn[index].pop_front();
            }
        }
       
    }
};

#endif //__CHAINING_HASH_H

