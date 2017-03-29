//
// Created by sensetime on 3/28/17.
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

using namespace std;

int longestValidParentheses(string s) {
    stack<int> pStack;
    int max_length = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            pStack.push(i);
        } else {
            if (!pStack.empty()) {
                if (s[pStack.top()] == '(') {
                    pStack.pop();
                } else {
                    pStack.push(i);
                }
            } else {
                pStack.push(i);
            }
        }
    }
    if (pStack.empty()) {
        max_length = s.length();
    } else {
        int st = s.length();
        while (!pStack.empty()) {
            if (max_length < (st - pStack.top() - -1)) {
                max_length = st - pStack.top() - 1;
            }
            st = pStack.top();
            pStack.pop();
        }
        if (max_length < st) {
            max_length = st;
        }

    }
    return max_length;
}

int main() {
    string s = "(()";
    cout << longestValidParentheses(s);
}
