//
// Created by sensetime on 4/21/17.
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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates2(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *newHead = NULL;
    ListNode *start = head;
    ListNode *end = head->next;
    ListNode *previous = new ListNode(-1);
    previous->next = head;
    bool isFindHead = false;
    while (end) {
        if (end->val != start->val) {
            if (start->next == end) {
                previous = start;
                start = end;
                end = end->next;
                if (!isFindHead) {
                    newHead = previous;
                    isFindHead = true;
                }
            } else {
                previous->next = end;
                start = end;
                end = end->next;
            }
        } else {
            end = end->next;
        }
    }
    if (start->next != end) {
        previous->next = end;
    }
    if (!isFindHead) {
        newHead = previous->next;
    }
    return newHead;
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(1);
//    ListNode *n3 = new ListNode(1);
//    ListNode *n4 = new ListNode(1);
//    ListNode *n5 = new ListNode(1);
//    ListNode *n6 = new ListNode(5);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = n6;
//    n6->next = NULL;
//    ListNode *p = deleteDuplicates2(n1);
//    while (p) {
//        cout << p->val << "\t";
//        p = p->next;
//    }
//
//}