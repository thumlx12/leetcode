//
// Created by sensetime on 3/27/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseList(ListNode *inlet, ListNode *outlet) {
    //如果链表为空或者链表中只有一个元素
    if (inlet->next == outlet || inlet->next->next == outlet)
        return inlet;
    ListNode *p = inlet->next->next;
    ListNode *q = inlet->next;
    while (p != outlet) {
        q->next = p->next;
        p->next = inlet->next;
        inlet->next = p;
        p = q->next;
    }
    return inlet;
}

ListNode *reverseGroup(ListNode *entry, int num) {
    ListNode *p = entry->next;
    int actual_num = 0;
    while (p && actual_num < num) {
        actual_num++;
        p = p->next;
    }
    ListNode *outlet = p;
    if (actual_num < num) {
        return entry;
    }
    return reverseList(entry, outlet);


}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *previous = new ListNode(-1);
    previous->next = head;
    bool isGetHead = false;
    ListNode *newHead = NULL;
    while (previous->next) {
        previous = reverseGroup(previous, k);
        if (!isGetHead) {
            newHead = previous->next;
            isGetHead = true;
        }
        for (int i = 0; i < k ; ++i) {
            previous = previous->next;
        }
    }
    return newHead;

}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *hp = head;
    for (int i = 2; i <= 13; ++i) {
        ListNode *node = new ListNode(i);
        hp->next = node;
        hp = hp->next;
    }
    ListNode *newHead = reverseKGroup(head, 3);
    while (newHead) {
        cout << newHead->val << '\t';
        newHead = newHead->next;
    }
}
