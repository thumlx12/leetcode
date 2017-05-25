//
// Created by sensetime on 5/25/17.
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

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution148 {
public:

    ListNode *splitTwo(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
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

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l2) {
            return l1;
        }
        if (!l1) {
            return l2;
        }
        ListNode *newHead;
        ListNode *p1;
        ListNode *p2;
        if (l1->val < l2->val) {
            newHead = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            newHead = l2;
            p1 = l1;
            p2 = l2->next;
        }
        ListNode *newCur = newHead;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                newCur->next = p1;
                p1 = p1->next;
            } else {
                newCur->next = p2;
                p2 = p2->next;
            }
            newCur = newCur->next;
        }
        if (p1) {
            newCur->next = p1;
        }
        if (p2) {
            newCur->next = p2;
        }
        return newHead;

    }

    ListNode *mergeSort(ListNode *node) {
        if (!node || !node->next) {
            return node;
        }
        return mergeTwoLists(mergeSort(node), mergeSort(splitTwo(node)));
//        ListNode *left = node;
//        ListNode *right = splitTwo(node);
//
//        ListNode *sortedLeft = mergeSort(left);
//        ListNode *sortedRight = mergeSort(right);
//        ListNode *merged = mergeTwoLists(sortedLeft, sortedRight);
//        return merged;
    }

    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }
};
