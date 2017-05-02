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

TreeNode *in_pos_Reconstruct(vector<int> &inorder, vector<int> &postorder, int posEnd, int inStart, int inEnd) {
    if (inEnd - inStart < 1) {
        if (inStart == inEnd) {
            return (new TreeNode(inorder[inStart]));
        } else {
            return NULL;
        }
    }
    TreeNode *root = new TreeNode(postorder[posEnd]);
    int root_idx = inStart;
    for (; root_idx <= inEnd; ++root_idx) {
        if (inorder[root_idx] == postorder[posEnd]) {
            break;
        }
    }
    root->right = in_pos_Reconstruct(inorder, postorder, posEnd - 1, root_idx + 1, inEnd);
    root->left = in_pos_Reconstruct(inorder, postorder, posEnd - (inEnd - root_idx) - 1, inStart, root_idx - 1);
    return root;
}

TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.size() <= 0 || inorder.size() <= 0 || postorder.size() != inorder.size()) {
        return NULL;
    }
    return in_pos_Reconstruct(inorder, postorder, postorder.size() - 1, 0, postorder.size() - 1);
}
