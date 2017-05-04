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

void connect2(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    if (root->left) {
        root->left->next = root->right ? root->right : NULL;
        if (!root->left->next) {
            TreeLinkNode *leftNext = NULL;
            for (TreeLinkNode *rootNext = root->next; rootNext; rootNext = rootNext->next) {
                if (rootNext->left) {
                    leftNext = rootNext->left;
                    break;
                }
                if (rootNext->right) {
                    leftNext = rootNext->right;
                    break;
                }
            }
            root->left->next = leftNext;
        }
    }
    if (root->right) {
        TreeLinkNode *rightNext = NULL;
        for (TreeLinkNode *rootNext = root->next; rootNext; rootNext = rootNext->next) {
            if (rootNext->left) {
                rightNext = rootNext->left;
                break;
            }
            if (rootNext->right) {
                rightNext = rootNext->right;
                break;
            }
        }
        root->right->next = rightNext;
    }
    connect2(root->right);
    connect2(root->left);
}

/*
int main() {
    TreeLinkNode *n1 = new TreeLinkNode(2);
    TreeLinkNode *n2 = new TreeLinkNode(1);
    TreeLinkNode *n3 = new TreeLinkNode(3);
    TreeLinkNode *n4 = new TreeLinkNode(0);
    TreeLinkNode *n5 = new TreeLinkNode(7);
    TreeLinkNode *n6 = new TreeLinkNode(9);
    TreeLinkNode *n7 = new TreeLinkNode(1);
    TreeLinkNode *n8 = new TreeLinkNode(2);
    TreeLinkNode *n9 = new TreeLinkNode(1);
    TreeLinkNode *n10 = new TreeLinkNode(0);
    TreeLinkNode *n11 = new TreeLinkNode(8);
    TreeLinkNode *n12 = new TreeLinkNode(8);
    TreeLinkNode *n13 = new TreeLinkNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n5->left = n9;
    n5->right = n10;
    n7->left = n11;
    n7->right = n12;
    n12->left = n13;
    n10->left = n13;

    connect2(n1);
    cout << endl;
}*/
