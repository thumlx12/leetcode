//
// Created by sensetime on 4/26/17.
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
#include <bitset>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> ret;
    if (n < 0) {
        return ret;
    }
    ret.push_back(0);
    int base = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = ret.size() - 1; 0 <= j; --j) {
            ret.push_back(ret[j] + base);
        }
        base <<= 1;
    }
    return ret;
}

//int main() {
//    vector<int> ret = grayCode(1);
//    for (int i = 0; i < ret.size(); ++i) {
//        cout << ret[i] << "\n";
//    }
//}