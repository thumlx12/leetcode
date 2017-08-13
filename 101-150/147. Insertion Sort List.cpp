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
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *sentinel = new ListNode(-1);
    while (head) {
        ListNode *tmp = head->next;
        ListNode *p2 = sentinel;
        while (p2->next && head->val > p2->next->val) {
            p2 = p2->next;
        }
        head->next = p2->next;
        p2->next = head;
        head = tmp;
    }
//.
    return sentinel->next;
}

static ListNode *turnVector2List(vector<int> vec) {
    if (vec.size() <= 0) {
        return NULL;
    }
    ListNode *head = new ListNode(vec[0]);
    ListNode *p = head;
    for (int i = 1; i < vec.size(); ++i) {
        ListNode *node = new ListNode(vec[i]);
        p->next = node;
        p = p->next;
    }
    return head;
}

//int main() {
//    vector<int> nums = {9, 10, 5, 7, 20, 4};
//    ListNode *head = turnVector2List(nums);
//    ListNode *newHead = insertionSortList(head);
//    for (; newHead; newHead = newHead->next) {
//        cout << newHead->val << "\t";
//
//    }
//}