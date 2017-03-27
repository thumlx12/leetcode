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


void reverseList(ListNode *inlet, ListNode *outlet) {
    //如果链表为空或者链表中只有一个元素
    if (inlet->next == outlet || inlet->next->next == outlet)
        return;
    ListNode *p = inlet->next->next;
    ListNode *q = inlet->next;
    while (p != outlet) {
        q->next = p->next;
        p->next = inlet->next;
        inlet->next = p;
        p = q->next;
    }
}

bool reverseGroup(ListNode *entry, int num) {
    ListNode *p = entry->next;
    int actual_num = 0;
    while (p && actual_num < num) {
        actual_num++;
        p = p->next;
    }
    ListNode *outlet = p;
    if (actual_num < num) {
        return false;
    } else {
        reverseList(entry, outlet);
        return true;
    }
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
        bool isReversed = reverseGroup(previous, k);
        if (!isGetHead) {
            newHead = previous->next;
            isGetHead = true;
        }
        if (!isReversed) {
            break;
        }
        for (int i = 0; i < k; ++i) {
            previous = previous->next;
        }

    }
    return newHead;
}

ListNode *reverseKGroup_consise(ListNode *head, int k) {
    if (!head || !head->next || k <= 1) {
        return head;
    }
    ListNode *preHead = new ListNode(-1);
    preHead->next = head;
    ListNode *previous = preHead;
    ListNode *current = previous;
    ListNode *next = NULL;
    int num = 0;
    while (current = current->next) {
        num++;
    }
    while (num >= k) {
        current = previous->next;
        next = current->next;
        for (int i = 0; i < k - 1; ++i) {
            current->next = next->next;
            next->next = previous->next;
            previous->next = next;
            next = current->next;
        }
        previous = current;
        num -= k;
    }
    return preHead->next;

}

//int main() {
//    ListNode *head = new ListNode(1);
//    ListNode *hp = head;
//    for (int i = 2; i <= 16; ++i) {
//        ListNode *node = new ListNode(i);
//        hp->next = node;
//        hp = hp->next;
//    }
//    ListNode *newHead = reverseKGroup_consise(head, 4);
//    while (newHead) {
//        cout << newHead->val << '\t';
//        newHead = newHead->next;
//    }
//}
