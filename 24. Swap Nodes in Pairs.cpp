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

ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *newHead = p2;

    ListNode *previous = new ListNode(-1);
    previous->next = head;

    while (p2) {
        previous->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        if (!p1->next) {
            break;
        }

        p1 = p1->next;
        p2 = p1->next;
        previous = previous->next->next;
    }
    return newHead;
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(3);
//    ListNode *n3 = new ListNode(5);
//    ListNode *n4 = new ListNode(7);
//    ListNode *n5 = new ListNode(9);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = NULL;
//    ListNode *head1 = n1;
//    ListNode *newHead = swapPairs(head1);
//    while (newHead) {
//        cout << newHead->val << '\t';
//        newHead = newHead->next;
//    }
//}