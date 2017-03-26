//
// Created by LIXUAN MAO on 2017/3/26.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p_current = head;
    ListNode *p_next = head;
    for (int i = 0; i < n - 1; ++i) {
        p_next = p_next->next;
    }
    ListNode *p_previous = NULL;
    while (p_next->next) {
        p_previous = p_current;
        p_current = p_current->next;
        p_next = p_next->next;
    }
    if (p_previous) {
        p_previous->next = p_current->next;
    } else {
        head = p_current->next;
    }
    p_current->next = NULL;
    delete (p_current);
    return head;
}

//int main() {
//    int n = 4;
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = NULL;
//    ListNode *head = n1;
//    ListNode *newHead = removeNthFromEnd(head, n);
//    while (newHead) {
//        cout << newHead->val << '\t';
//        newHead = newHead->next;
//    }
//}