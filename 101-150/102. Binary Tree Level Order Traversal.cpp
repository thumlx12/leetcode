//
// Created by maolixuan on 2017/4/30.
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

void leverTraverse(vector<vector<int>> &res, queue<TreeNode *> &q) {
    while (!q.empty()) {
        int n = q.size();
        vector<int> thisLevel;
        for (int i = 0; i < n; ++i) {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            thisLevel.push_back(q.front()->val);
            q.pop();
        }
        res.push_back(thisLevel);
    }
}

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    leverTraverse(res, q);
    return res;
}
//
//int main() {
//    TreeNode *n1 = new TreeNode(5);
//    TreeNode *n2 = new TreeNode(3);
//    TreeNode *n3 = new TreeNode(9);
//    TreeNode *n4 = new TreeNode(4);
//    n1->right = n3;
//    n1->left = n2;
//    n2->right = n4;
//    vector<vector<int>> res = levelOrder(n1);
//    for (int i = 0; i < res.size(); ++i) {
//        for (int j = 0; j < res[i].size(); ++j) {
//            cout << res[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}