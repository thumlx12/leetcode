//
// Created by sensetime on 5/25/17.
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
#include <list>
#include <unordered_set>

using namespace std;


int evalRPN(vector<string> &tokens) {
    stack<int> s;
    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+") {
            int r1 = s.top();
            s.pop();
            int r2 = s.top();
            s.pop();
            s.push(r1 + r2);
        } else if (tokens[i] == "-") {
            int r1 = s.top();
            s.pop();
            int r2 = s.top();
            s.pop();
            s.push(r2 - r1);
        } else if (tokens[i] == "*") {
            int r1 = s.top();
            s.pop();
            int r2 = s.top();
            s.pop();
            s.push(r1 * r2);
        } else if (tokens[i] == "/") {
            int r1 = s.top();
            s.pop();
            int r2 = s.top();
            s.pop();
            s.push(r2 / r1);
        } else {
            s.push(atoi(tokens[i].c_str()));
        }
    }
    return s.top();
}
