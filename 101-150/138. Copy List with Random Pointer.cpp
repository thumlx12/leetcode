//
// Created by sensetime on 5/18/17.
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
#include <bits/unordered_set.h>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList2(RandomListNode *head) {
    if (!head) {
        return NULL;
    }
    unordered_map<RandomListNode *, RandomListNode *> old2new;
    RandomListNode *p1 = head;
    RandomListNode *p2 = new RandomListNode(head->label);
    old2new.insert(make_pair(p1, p2));
    while (p1) {
        if (p1->next) {
            if (old2new.count(p1->next)) {
                p2->next = old2new[p1->next];
            } else {
                p2->next = new RandomListNode(p1->next->label);
                old2new.insert(make_pair(p1->next, p2->next));
            }
        }
        if (p1->random) {
            if (old2new.count(p1->random)) {
                p2->random = old2new[p1->random];
            } else {
                p2->random = new RandomListNode(p1->random->label);
                old2new.insert(make_pair(p1->random, p2->random));
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return old2new[head];
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
        return NULL;
    }
    unordered_map<RandomListNode *, int> Node2Index;
    unordered_map<int, RandomListNode *> Index2Node;
    RandomListNode *p = head;
    for (int i = 0; p; p = p->next, ++i) {
        Node2Index.insert(make_pair(p, i));
    }

    RandomListNode *newHead = new RandomListNode(head->label);
    RandomListNode *p1 = newHead;
    int idx = 0;
    Index2Node.insert(make_pair(idx, newHead));
    for (idx = 1, p = head->next; p; p = p->next, p1 = p1->next, ++idx) {
        RandomListNode *tmp = new RandomListNode(p->label);
        p1->next = tmp;
        Index2Node.insert(make_pair(idx, tmp));
    }

    for (p = head, p1 = newHead; p; p = p->next, p1 = p1->next) {
        RandomListNode *randomNode = p->random;
        if (!randomNode) {
            continue;
        } else {
            int randomNodeIdx = Node2Index[randomNode];
            p1->random = Index2Node[randomNodeIdx];
        }
    }

    return newHead;
}

//int main() {
//    RandomListNode *n1 = new RandomListNode(-1);
//    RandomListNode *ret = copyRandomList(n1);
//    cout << endl;
//}
