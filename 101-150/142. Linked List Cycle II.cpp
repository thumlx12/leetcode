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
#include <malloc.h>
#include <queue>
#include <bits/unordered_set.h>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution142 {
public:
    ListNode *hasCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        bool hasCycle = false;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *meeting = hasCycle(head);
        if (!meeting) {
            return NULL;
        }
        ListNode *p1 = head;
        while (p1 != meeting) {
            p1 = p1->next;
            meeting = meeting->next;
        }
        return p1;
    }

};


