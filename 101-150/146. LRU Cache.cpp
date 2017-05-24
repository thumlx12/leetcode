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

struct DoubleLinkedNode {
    int key;
    int value;
    DoubleLinkedNode *prev;
    DoubleLinkedNode *next;

    DoubleLinkedNode(int x, int y) : key(x), value(y), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, DoubleLinkedNode *> table;
    DoubleLinkedNode *front;
    DoubleLinkedNode *tail;
    int _capacity;
    int _size;

    void move2head(DoubleLinkedNode *node) {
        if (!node || node == front) {
            return;
        }
        DoubleLinkedNode *prevNode = node->prev;
        DoubleLinkedNode *nextNode = node->next;
        if (!nextNode) {
            prevNode->next = NULL;
            tail = prevNode;
        } else if (!prevNode) {
            nextNode->prev = NULL;
            front = nextNode;
        } else {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        node->next = front;
        node->prev = NULL;
        front->prev = node;
        front = node;
    }

    void deleteBack() {
        if (front == tail) {
            delete[] front;
            front = NULL;
            tail = NULL;
            return;
        }
        DoubleLinkedNode *prev = tail->prev;
        tail->prev = NULL;
        delete[] tail;
        prev->next = NULL;
        tail = prev;
    }

    void addNewEle(int key, int value) {
        DoubleLinkedNode *newHead = new DoubleLinkedNode(key, value);
        table.insert(make_pair(key, newHead));
        if (!front) {
            front = newHead;
            tail = newHead;
            return;
        }
        newHead->next = front;
        front->prev = newHead;
        front = newHead;
    }

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        front = NULL;
        tail = NULL;
        table.clear();
    }

    int get(int key) {
        if (table.count(key)) {
            move2head(table[key]);
            return table[key]->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (table.count(key)) {
            table[key]->value = value;
            move2head(table[key]);
            return;
        }
        if (_size < _capacity) {
            addNewEle(key, value);
            _size++;
        } else {
            table.erase(tail->key);
            deleteBack();
            addNewEle(key, value);
        }
    }
};

//int main() {
//    LRUCache *cache = new LRUCache(2);
//
//    cache->put(1, 1);
//    cache->put(2, 2);
//    cout << cache->get(1) << endl;       // returns 1
//    cache->put(3, 3);    // evicts key 2
//    cout << cache->get(2) << endl;       // returns -1 (not found)
//    cache->put(4, 4);    // evicts key 1
//    cout << cache->get(1) << endl;       // returns -1 (not found)
//    cout << cache->get(3) << endl;       // returns 3
//    cout << cache->get(4) << endl;       // returns 4
//
//    cout << "*********************************************************" << endl;
//    LRUCache *cache2 = new LRUCache(3);
//    cache2->put(1, 1);
//    cache2->put(2, 2);
//    cache2->put(3, 3);
//    cache2->put(4, 4);
//    cout << cache2->get(4) << endl;
//    cout << cache2->get(3) << endl;
//    cout << cache2->get(2) << endl;
//    cout << cache2->get(1) << endl;
//    cache2->put(5, 5);
//    cout << cache2->get(1) << endl;
//    cout << cache2->get(2) << endl;
//    cout << cache2->get(3) << endl;
//    cout << cache2->get(4) << endl;
//    cout << cache2->get(5) << endl;
//
//}