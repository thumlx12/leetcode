//
// Created by sensetime on 4/15/17.
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

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) {
        return head;
    }

    int size = 0;
    ListNode *p1 = head, *p2, *newHead;
    while (p1) {
        size++;
        p1 = p1->next;
    }
    k = k % size;
    if (k == 0) {
        return head;
    }

    p1 = head;
    for (int i = 0; i < size - k - 1; ++i) {
        p1 = p1->next;
    }
    newHead = p1->next;
    p1->next = NULL;

    p2 = newHead;
    while (p2->next) {
        p2 = p2->next;
    }
    p2->next = head;
    return newHead;
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    ListNode *rotated = rotateRight(n1, 6);
//    while (rotated) {
//        cout << rotated->val << "\t";
//        rotated = rotated->next;
//    }
//}