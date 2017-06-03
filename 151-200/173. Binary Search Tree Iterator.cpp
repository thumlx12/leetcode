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
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> smallStack;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;
        while (tmp) {
            smallStack.push(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (!smallStack.empty()) {
            return true;
        } else {
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = smallStack.top();
        int nextNum = cur->val;
        smallStack.pop();
        if (cur->right) {
            cur = cur->right;
            while (cur) {
                smallStack.push(cur);
                cur = cur->left;
            }
        }
        return nextNum;
    }
};
