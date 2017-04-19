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
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode *divideSolution(vector<ListNode *> &lists, int lo, int hi) {
    if (lo < hi) {
        int mi = (lo + hi) / 2;
        return mergeTwoLists(divideSolution(lists, lo, mi), divideSolution(lists, mi + 1, hi));
    }
    return lists[lo];
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> trimmedList;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            trimmedList.push_back(lists[i]);
        }
    }
    if (trimmedList.size() <= 0) {
        return NULL;
    }

    return divideSolution(trimmedList, 0, trimmedList.size() - 1);
}

//int main() {
//
//    ListNode *n1 = new ListNode(1);
////    ListNode *n2 = new ListNode(3);
////    ListNode *n3 = new ListNode(5);
////    ListNode *n4 = new ListNode(7);
////    ListNode *n5 = new ListNode(9);
////    n1->next = n2;
////    n2->next = n3;
////    n3->next = n4;
////    n4->next = n5;
////    n5->next = NULL;
//    ListNode *head1 = n1;
//
//
//    ListNode *m1 = new ListNode(0);
////    ListNode *m2 = new ListNode(4);
////    ListNode *m3 = new ListNode(6);
////    ListNode *m4 = new ListNode(8);
////    ListNode *m5 = new ListNode(10);
////    ListNode *m6 = new ListNode(13);
////    m1->next = m2;
////    m2->next = m3;
////    m3->next = m4;
////    m4->next = m5;
////    m5->next = m6;
////    m6->next = NULL;
//    ListNode *head2 = m1;
//
//    vector<ListNode *> lists;
//    lists.push_back(head1);
//    lists.push_back(head2);
//
//    ListNode *newHead = mergeKLists(lists);
//    while (newHead) {
//        cout << newHead->val << '\t';
//        newHead = newHead->next;
//    }
//}