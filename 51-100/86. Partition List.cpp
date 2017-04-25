//
// Created by sensetime on 4/25/17.
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

ListNode *partition(ListNode *head, int x) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *part1 = new ListNode(-1);
    ListNode *part2 = new ListNode(-1);
    ListNode *p = head;
    ListNode *newHead = part1;
    ListNode *newTail = part2;
    while (p) {
        if (p->val < x) {
            part1->next = p;
            part1 = part1->next;
        } else {
            part2->next = p;
            part2 = part2->next;
        }
        p = p->next;
    }
    part1->next = NULL;
    part1->next = NULL;
    ListNode *tmp = newHead;
    for (; tmp->next; tmp = tmp->next) {}
    tmp->next = newTail->next;
    return newHead->next;
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(10);
//    ListNode *n3 = new ListNode(2);
//    ListNode *n4 = new ListNode(11);
//    ListNode *n5 = new ListNode(3);
//    ListNode *n6 = new ListNode(12);
//    ListNode *n7 = new ListNode(4);
//
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = n6;
//    n6->next = n7;
//    n7->next = NULL;
//
//    ListNode *newHead = partition(n1, 5);
//    for (; newHead; newHead = newHead->next) {
//        cout << newHead->val << "\t";
//    }
//}