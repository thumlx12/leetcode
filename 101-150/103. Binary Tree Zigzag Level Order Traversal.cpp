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

void zigzagLeverTraverse(vector<vector<int>> &res, stack<TreeNode *> &s1, stack<TreeNode *> &s2) {
    for (bool direction = true; !s1.empty() || !s2.empty(); direction = !direction) {
        int n = direction ? s1.size() : s2.size();
        vector<int> thisLevel;
        for (int i = 0; i < n; ++i) {
            if (direction) {
                if (s1.top()->left) {
                    s2.push(s1.top()->left);
                }
                if (s1.top()->right) {
                    s2.push(s1.top()->right);
                }
                thisLevel.push_back(s1.top()->val);
                s1.pop();
            } else {
                if (s2.top()->right) {
                    s1.push(s2.top()->right);
                }
                if (s2.top()->left) {
                    s1.push(s2.top()->left);
                }
                thisLevel.push_back(s2.top()->val);
                s2.pop();
            }

        }
        res.push_back(thisLevel);
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    stack<TreeNode *> stack1;
    stack<TreeNode *> stack2;
    stack1.push(root);
    zigzagLeverTraverse(res, stack1, stack2);
    return res;
}

//int main() {
//    TreeNode *n1 = new TreeNode(3);
//    TreeNode *n2 = new TreeNode(9);
//    TreeNode *n3 = new TreeNode(20);
//    TreeNode *n4 = new TreeNode(8);
//    TreeNode *n5 = new TreeNode(10);
//    TreeNode *n6 = new TreeNode(15);
//    TreeNode *n7 = new TreeNode(7);
//    TreeNode *n8 = new TreeNode(17);
//    TreeNode *n9 = new TreeNode(19);
//    TreeNode *n10 = new TreeNode(21);
//    TreeNode *n11 = new TreeNode(20);
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;
//    n4->left = n8;
//    n5->left = n9;
//    n7->left = n10;
//    n7->right = n11;
//    vector<vector<int>> res = zigzagLevelOrder(n1);
//    for (int i = 0; i < res.size(); ++i) {
//        for (int j = 0; j < res[i].size(); ++j) {
//            cout << res[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}