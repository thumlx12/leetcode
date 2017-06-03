//
// Created by sensetime on 4/29/17.
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findTheTwo(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev) {
    if (!root) {
        return;
    }
    findTheTwo(root->left, first, second, prev);
    if (prev && prev->val > root->val) {
        if (!first) {
            first = prev;
        }
        if (first) {
            second = root;
        }
    }
    prev = root;
    findTheTwo(root->right, first, second, prev);
}

void recoverTree(TreeNode *root) {
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    findTheTwo(root, first, second, prev);
    if (first && second) {
        swap(first->val, second->val);
    }
}

//int main() {
//    TreeNode *n1 = new TreeNode(5);
//    TreeNode *n2 = new TreeNode(3);
//    TreeNode *n3 = new TreeNode(9);
//    TreeNode *n4 = new TreeNode(4);
////    n1->right = n4;
////    n1->left = n2;
////    n2->right = n3;
//    n2->left = n1;
//    recoverTree(n2);
//    cout << endl;
//}

//int main() {
//    string s1 = "{\"type\":\"record\",\"name\":\"Datum\",\"namespace\":\"com.sensetime.commons.io\",\"fields\":[{\"name\":\"group\",\"type\":\"string\"},{\"name\":\"name\",\"type\":\"string\"},{\"name\":\"status\",\"type\":\"int\"},{\"name\":\"meta\",\"type\":[\"string\",\"null\"]},{\"name\":\"bin\",\"type\":[\"bytes\",\"null\"]}]}";
//    string s2 = "{\"type\":\"record\",\"name\":\"Datum\",\"namespace\":\"com.sensetime.commons.io\",\"fields\":[{\"name\":\"group\",\"type\":\"string\"},{\"name\":\"name\",\"type\":\"string\"},{\"name\":\"status\",\"type\":\"int\"},{\"name\":\"meta\",\"type\":[\"string\",\"null\"]},{\"name\":\"bin\",\"type\":[\"bytes\",\"null\"]}]}";
//    if(s1 == s2){
//        cout<<"euqal!";
//    }
//}