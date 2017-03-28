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
    stack<bool> pStack;
    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            pStack.push(true);
        } else {
            if (pStack.empty()) {
                if (max_length < current_length) {
                    max_length = current_length;
                    current_length = 0;
                }
            } else {
                pStack.pop();
                current_length += 2;
            }
        }
    }
    if (max_length < current_length) {
        max_length = current_length;
    }
    return max_length;
}

int main() {
    string s = "()(()";
    cout << longestValidParentheses(s);
}
