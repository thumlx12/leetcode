//
// Created by sensetime on 4/17/17.
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

/* DEPRECATED
string trim(string &s) {
    string trimmed = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            trimmed += s[i];
        }
    }
    return trimmed;
}

vector<string> split(string &s, char seperator) {
    vector<string> splitted;
    int start = 0;
    int end = 0;
    for (; end < s.length(); ++end) {
        if (s[end] == seperator && s[end - 1] != seperator) {
            splitted.push_back(s.substr(start, end - start));
            start = end + 1;
        }
    }
    if (0 < end - start && s[start] != seperator) {
        splitted.push_back(s.substr(start, end - start));
    }
    return splitted;
}*/

bool isNumber(string s) {
    if (s.length() <= 0) {
        return false;
    }
    int start = 0;
    int end = s.length();
    for (; s[start] == ' ' && start < s.length(); ++start) {}
    if (s[start] == '+' || s[start] == '-') start++;

    for (; s[end - 1] == ' ' && 0 <= (end - 1); --end) {}
    if (start >= end) {
        return false;
    }

    int e_index = -1;
    int e_count = 0;
    int point_count = 0;
    for (int i = start; i < end; ++i) {
        if (s[i] == 'e') {
            e_index = i;
            e_count++;
        } else if (s[i] == '.') {
            point_count++;
        }
    }
    if (e_count > 1 || point_count > 1) {
        return false;
    }
    if (e_count == 1) {
        int after_start;
        if (s[e_index + 1] == '+' || s[e_index + 1] == '-') {
            after_start = e_index + 2;
        } else {
            after_start = e_index + 1;
        }
        int digit_after_e = 0;
        for (int i = after_start; i < end; ++i) {
            if (isdigit(s[i])) {
                digit_after_e++;
            } else {
                return false;
            }
        }
        if (digit_after_e == 0) {
            return false;
        }
    } else {
        e_index = end;
    }
    int digit_around_point = 0;
    for (int i = start; i < e_index; ++i) {
        if (isdigit(s[i])) {
            digit_around_point++;
        } else if (s[i] == '.') {
            continue;
        } else {
            return false;
        }
    }
    if (digit_around_point == 0) {
        return false;
    }
    return true;
}

//int main() {
//    string str = " 005047e+6";
//    cout << isNumber(str) << endl;
//}