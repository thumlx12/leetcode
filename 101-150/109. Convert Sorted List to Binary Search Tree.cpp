//
// Created by sensetime on 5/2/17.
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return (new TreeNode(head->val));
    }
    ListNode *p_slow = head;
    ListNode *p_fast = head;
    ListNode *prev = new ListNode(-1);
    prev->next = head;
    while (p_fast && p_fast->next) {
        p_slow = p_slow->next;
        p_fast = p_fast->next;
        p_fast = p_fast->next;
        prev = prev->next;
    }
    TreeNode *root = new TreeNode(p_slow->val);
    ListNode *rightTree = p_slow->next;
    prev->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(rightTree);
    return root;
}

//int main() {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
//    ListNode *n6 = new ListNode(6);
//    ListNode *n7 = new ListNode(7);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
//    n5->next = n6;
//    n6->next = n7;
//    TreeNode *root = sortedListToBST(n1);
//    cout << endl;
//}