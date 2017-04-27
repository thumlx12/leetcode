//
// Created by sensetime on 4/27/17.
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

ListNode *reverseSector(ListNode *start, ListNode *end) {
    ListNode *newHead = end;
    ListNode *p1 = start;
    ListNode *p2 = start->next;
    ListNode *p3 = end->next;
    while (p1 != end) {
        ListNode *tmp = p2->next;
        p1->next = p3;
        p2->next = p1;
        p3 = p1;
        p1 = p2;
        p2 = tmp;
    }
    return newHead;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || !head->next) {
        return head;
    }
    int extraSteps = n - m;
    ListNode *pEnd = head;
    ListNode *pStart = head;
    ListNode *pPrevious = new ListNode(-1);
    pPrevious->next = head;
    for (int i = 0; i < extraSteps; ++i) {
        pEnd = pEnd->next;
    }
    for (int i = 1; i < m; i++) {
        pEnd = pEnd->next;
        pStart = pStart->next;
        pPrevious = pPrevious->next;
    }
    ListNode *sectorHead = reverseSector(pStart, pEnd);
    pPrevious->next = sectorHead;
    if (m > 1) {
        return head;
    } else {
        return pPrevious->next;
    }
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
//    ListNode *n6 = new ListNode(6);
//    ListNode *n7 = new ListNode(7);
//
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = n6;
//    n6->next = n7;
//    n7->next = NULL;
//
//    ListNode *newHead = reverseBetween(n1, 1, 7);
//    for (; newHead; newHead = newHead->next) {
//        cout << newHead->val << "\t";
//    }
//}