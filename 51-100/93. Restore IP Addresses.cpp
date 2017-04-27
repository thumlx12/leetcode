//
// Created by sensetime on 4/27/17.
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

void findAllIP(string &s, vector<string> &ret, string current, int sector, int start) {
    if (sector > 4) {
        return;
    }
    if (sector == 4) {
        if (start == s.length()) {
            current.pop_back();
            ret.push_back(current);
        }
    } else {
        if (s.length() - start >= 3) {
            string sub1 = s.substr(start, 3);
            int num = (sub1[0] - 48) * 100 + (sub1[1] - 48) * 10 + (sub1[2] - 48);
            if (100 <= num && num <= 255) {
                findAllIP(s, ret, current + sub1 + ".", sector + 1, start + 3);
            }
        }
        if (s.length() - start >= 2) {
            string sub2 = s.substr(start, 2);
            int num = (sub2[0] - 48) * 10 + (sub2[1] - 48);
            if (10 <= num) {
                findAllIP(s, ret, current + sub2 + ".", sector + 1, start + 2);
            }
        }
        if (s.length() - start >= 1) {
            string sub3 = s.substr(start, 1);
            int num = (sub3[0] - 48);
            findAllIP(s, ret, current + sub3 + ".", sector + 1, start + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    if (s.length() > 12 || s.length() < 4) {
        return ret;
    }
    string current = "";
    findAllIP(s, ret, current, 0, 0);
    return ret;
}

//int main() {
//    vector<string> IPs = restoreIpAddresses("234");
//    for (int i = 0; i < IPs.size(); ++i) {
//        cout << IPs[i] << endl;
//    }
//}
