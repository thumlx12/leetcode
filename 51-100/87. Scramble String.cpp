//
// Created by sensetime on 4/25/17.
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

struct StrNode {
    int start;
    int end;
    StrNode *lc;
    StrNode *rc;

    StrNode() : start(0), end(0), lc(NULL), rc(NULL) {}

    StrNode(int s, int e) : start(s), end(e), lc(NULL), rc(NULL) {}
};

void addLeftChild(StrNode *s, int l, int r) {
    if (r - l <= 0) {
        return;
    }
    int length = r - l + 1;
    StrNode *lc = new StrNode(l, l + length / 2 - 1);
    s->lc = lc;
}

void addRightChild(StrNode *s, int l, int r) {
    if (r - l <= 0) {
        return;
    }
    int length = r - l + 1;
    StrNode *rc = new StrNode(l + length / 2, r);
    s->rc = rc;
}

void buildStrTree(StrNode *root, int l, int r) {
    if (r - l <= 0) {
        return;
    }
    addLeftChild(root, l, r);
    addRightChild(root, l, r);
    buildStrTree(root->lc, l, (l + r + 1) / 2 - 1);
    buildStrTree(root->rc, (l + r + 1) / 2, r);
}

bool isScramble(string s1, string s2) {

}

int main() {
    string s1 = "great";
    int left = 0;
    int right = s1.length() - 1;
    StrNode *root = new StrNode(left, right);
    buildStrTree(root, left, right);
    cout<<endl;
}