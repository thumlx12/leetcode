//
// Created by sensetime on 5/24/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <list>
#include <bits/unordered_set.h>

using namespace std;

class LRUCache {
private:
    unordered_map<int, int> table;
    list<int> order;
    int _capacity;
    int _size;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        table.clear();
    }

    void update(int key) {
        list<int>::iterator findIter = std::find(order.begin(), order.end(), key);
        if (findIter == order.end()) {
            order.push_front(key);
        } else {
            order.erase(findIter);
            order.push_front(key);
        }
    }

    int get(int key) {
        if (table.count(key)) {
            update(key);
            return table[key];
        } else {
            return -1;
        }

    }

    void put(int key, int value) {
        if (table.count(key)) {
            table[key] = value;
            update(key);
            return;
        }
        if (_size < _capacity) {
            table.insert(make_pair(key, value));
            ++_size;
        } else {
            int earliest = order.back();
            table.erase(earliest);
            order.pop_back();
            table.insert(make_pair(key, value));
        }
        update(key);
    }

};

int main() {
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns 3
    cout << cache->get(4) << endl;       // returns 4

    LRUCache *cache2 = new LRUCache(2);
    cache2->put(2, 1);
    cache2->put(2, 2);
//    list<int> t = {1, 3, 4, 5, 6};
//    list<int>::iterator findIter = std::find(t.begin(), t.end(), 4);
//    t.erase(findIter);
//    t.push_front(4);
//    cout << t.back();
}