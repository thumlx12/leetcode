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
#include <bits/unordered_set.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution143 {
public:
    ListNode *splitTwo(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev = NULL;
        while (p2 && p2->next) {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (!p2) {
            prev->next = NULL;
            return p1;
        } else {
            ListNode *secHead = p1->next;
            p1->next = NULL;
            return secHead;
        }
    }

    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *newHead = NULL;
        ListNode *next = NULL;
        ListNode *current = head;
        ListNode *prev = head->next;
        while (prev) {
            current->next = next;
            ListNode *tmp = prev->next;
            prev->next = current;
            newHead = prev;
            next = current;
            current = prev;
            prev = tmp;
        }
        return newHead;
    }

    void reorderList(ListNode *head) {
        ListNode *secPartHead = splitTwo(head);
        ListNode *reversedSec = reverseList(secPartHead);

        ListNode *p1 = head;
        ListNode *p2 = reversedSec;

        while (p1 && p2) {
            ListNode *tmp1 = p1->next;
            ListNode *tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
        return;
    }
};

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
////    ListNode *n6 = new ListNode(6);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
////    n5->next = n6;
//
//    Solution143 *solu;
//    solu->reorderList(n1);
//    ListNode *newHead = n1;
//    for (; newHead; newHead = newHead->next) {
//        cout << newHead->val << "\t";
//
//    }
//}