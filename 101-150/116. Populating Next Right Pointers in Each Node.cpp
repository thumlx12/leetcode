//
// Created by sensetime on 5/4/17.
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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    if (root->left) {
        root->left->next = root->right;
    }
    if (root->right) {
        if (root->next) {
            root->right->next = root->next->left;
        }
    }
    connect(root->right);
    connect(root->left);
}

//int main() {
//    TreeLinkNode *n1 = new TreeLinkNode(1);
//    TreeLinkNode *n2 = new TreeLinkNode(2);
//    TreeLinkNode *n3 = new TreeLinkNode(3);
//    TreeLinkNode *n4 = new TreeLinkNode(4);
//    TreeLinkNode *n5 = new TreeLinkNode(5);
//    TreeLinkNode *n6 = new TreeLinkNode(6);
//    TreeLinkNode *n7 = new TreeLinkNode(7);
//    TreeLinkNode *n8 = new TreeLinkNode(8);
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;
//    n4->left = n8;
//    connect(n1);
//    cout << endl;
//}